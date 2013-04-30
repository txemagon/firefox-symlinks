#!/usr/bin/python

from optparse import OptionParser
import os
import os.path
import re
import shutil
import subprocess
import sys
import time
import urllib
import xml.dom.minidom
import json

class DependencyNotFound(Exception):
    def __init__(self, depend):
        super(DependencyNotFound, self).__init__(depend)
        self.path = depend[0]
        self.package = depend[1]

    def __str__(self):
        return 'Dependency not found: %s. Please install package %s' % (self.path, self.package)

class MissingLocaleError(Exception):
    def __init__(self, locale):
        super(MissingLocaleError, self).__init__(locale)
        self.locale = locale

    def __str__(self):
        return "Locale %s is missing from the source tarball" % self.locale

class RevisionNotFound(Exception):
    def __init__(self, revision, repo):
        super(RevisionNotFound, self).__init__(revision, repo)
        self.revision = revision
        self.repo = repo

    def __str__(self):
        return "Revision %s not found in %s" % (self.revision, self.repo)

class InvalidTagError(Exception):
    def __init__(self, tag):
        super(InvalidTagError, self).__init__(tag)
        self.tag = tag

    def __str__(self):
        return "Tag %s is invalid" % self.tag

def do_exec(args, quiet=True, ignore_error=False, cwd=None):
    if quiet == False:
        arg_string = ''
        for arg in args:
            sep = ' ' if arg_string != '' else ''
            arg_string += '%s%s' % (sep, arg)
        if cwd != None:
            arg_string += ' in %s' % cwd
        print 'Running %s' % arg_string

    p = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=cwd)
    out = ''
    while p.poll() == None:
        for line in p.stdout:
            out += line
            if quiet == False:
                print line.strip()

    if p.returncode != 0 and ignore_error == False:
        raise subprocess.CalledProcessError(p.returncode, args[0])

    return (p.returncode, out)

def pack_orig_source(name, version, destdir, includes, excludes):
    print '\n\n*** Packing tarball ***\n'
    os.chdir('..')
    topsrcdir = '%s-%s' % (name, version)
    os.rename(name, topsrcdir)
    args = ['tar', '-jc', '--exclude-vcs']
    for exclude in excludes:
        args.append('--no-wildcards-match-slash') if exclude['wms'] == False else args.append('--wildcards-match-slash')
        args.append('--exclude')
        args.append(os.path.join(topsrcdir , exclude['path']))
    args.append('-f')
    args.append(os.path.join(destdir, '%s_%s.orig.tar.bz2' % (name, version)))
    for include in includes:
        args.append(os.path.join(topsrcdir, include))

    do_exec(args)

    # We need to manually clean up the files we packed now. We
    # can't pass --remove-files to tar, because it uses rmdir, which
    # fails because we exclude some files
    for include in includes:
        if os.path.exists(os.path.join(topsrcdir, include)):
            shutil.rmtree(os.path.join(topsrcdir, include))

def determine_upstream_version(repo, tag, version_file, want_moz_version):
    vf = open(version_file, 'r')
    upstream_version = re.sub(r'~$', '', re.sub(r'([0-9\.]*)(.*)', r'\1~\2', vf.read().strip()))
    vf.close()

    if tag == None:
        (ret, out) = do_exec(['hg', 'tip'], quiet=True)
        for line in out.split('\n'):
            if line.startswith('changeset:'):
                rev = line.split()[1].split(':')[0].strip()
                changeset = line.split()[1].split(':')[1].strip()
                break

        u = urllib.urlopen('%s/pushlog?changeset=%s' % (repo, changeset))
        dom = xml.dom.minidom.parseString(u.read())
        t = time.strptime(dom.getElementsByTagName('updated')[0].firstChild.nodeValue.strip(), '%Y-%m-%dT%H:%M:%SZ')
        upstream_version += '~hg%s%s%sr%s' % ('%02d' % t.tm_year, '%02d' % t.tm_mon, '%02d' % t.tm_mday, rev)
        u.close()

        if want_moz_version == 1:
            # Embed the moz revision in the version number too. Allows us to respin dailies for comm-central
            # even if the only changes landed in mozilla-central
            (ret, out) = do_exec(['hg', 'tip'], cwd='mozilla', quiet=True)
            for line in out.split('\n'):
                if line.startswith('changeset:'):
                    upstream_version += '.%s' % line.split()[1].split(':')[0].strip()
                    break
    else:
        parsed = False
        version_from_upstream = upstream_version
        upstream_version = ''
        build = None
        for comp in tag.split('_')[1:]:
            if parsed == True:
                raise InvalidTagError(tag)

            if comp.startswith('BUILD'):
                build = re.sub(r'BUILD', '', comp)
                parsed = True
            elif comp.startswith('RELEASE'):
                parsed = True
            else:
                if upstream_version != '':
                    upstream_version += '.'
                upstream_version += re.sub(r'~$', '', re.sub(r'([0-9]*)(.*)', r'\1~\2', comp))

            if parsed == True and upstream_version == '':
                raise InvalidTagError(tag)

        if upstream_version == '':
            raise InvalidTagError(tag)

        if build != None:
            upstream_version += '+build%s' % build

        if not upstream_version.startswith(version_from_upstream):
            raise InvalidTagError(tag)

    print '\n\nUpstream version is %s\n' % upstream_version
    return upstream_version

def ensure_cache(repo, cache):
    dest = os.path.join(cache, os.path.basename(repo))
    if os.path.isdir(dest):
        (ret, out) = do_exec(['hg', 'summary'], cwd=dest, quiet=True, ignore_error=True)
        if ret == 0:
            print 'Cache location %s exists, using it' % dest
            do_exec(['hg', 'pull', repo], cwd=dest)
            do_exec(['hg', 'update'], cwd=dest)
            return

    if not os.path.isdir(cache):
        os.makedirs(cache)

    print 'Creating cache location %s' % dest
    do_exec(['hg', 'clone', repo, dest])

def post_checkout(repo, cache, tag):
    print '\n\n*** Running checkout script ***\n'
    moz_local = None
    moz_repo = os.path.join(os.path.dirname(repo), os.path.basename(repo).replace('comm', 'mozilla'))
    if cache != None:
        ensure_cache(moz_repo, cache)
        moz_local = os.path.join(cache, os.path.basename(moz_repo))
    args = ['python', 'client.py', 'checkout']
    if moz_local != None:
        args.append('--mozilla-repo=%s' % moz_local)
    if tag != None:
        args.append('--comm-rev=%s' % tag)
        args.append('--mozilla-rev=%s' % tag)
    do_exec(args)

def verify_all_locales(all_locales, blfile, shipped_locales):
    # When we also use translations from Launchpad, there will be a file
    # containing the additional locales we want to ship (locales.extra??)
    print '\n\n*** Checking that required locales are present ***\n'

    blacklist = {}
    if blfile:
        bl = open(blfile, 'r')
        for line in bl:
            locale = line.strip()
            if locale.startswith('#'):
                continue

            blacklist[locale] = 1
        bl.close()

    sl = open(shipped_locales, 'r')
    for line in sl:
        line = line.strip()
        if line.startswith('#'):
            continue

        if line == 'en-US':
            print 'Ignoring en-US'
            continue

        locale = line.split(' ')[0].strip()
        platforms = line.split(' ')[1:]

        if blacklist.has_key(locale):
            print 'Ignoring blacklisted locale %s' % locale
            continue

        if len(platforms) > 0:
            for_linux = False
            for platform in platforms:
                if platform == 'linux':
                    for_linux = True
                    break
            if not for_linux:
                print 'Ignoring %s (not for linux)' % locale
                continue

        if not all_locales.has_key(locale):
            raise MissingLocaleError(locale)

        print '%s - Yes' % locale

    sl.close()

def do_checkout(source, dest, tag=None):
    dest_parent = os.path.dirname(dest)
    if dest_parent != '' and not os.path.isdir(dest_parent):
        os.makedirs(dest_parent)

    do_exec(['hg', 'clone', source, dest])

    try:
        args = ['hg', 'update']
        if tag != None:
            args.append('-r')
            args.append(tag)
        do_exec(args, cwd=dest)
    except:
        if tag != None:
            raise RevisionNotFound(tag, source)
        raise

def checkout_locale(base, cache, locale, tag, changesets):
    print '\nChecking out %s' % locale
    local_source = None
    remote_source = os.path.join(base, locale)
    destdir = os.path.join('l10n', locale)

    if cache != None:
        l10n_cache_top = os.path.join(cache, 'l10n')
        ensure_cache(remote_source, l10n_cache_top)
        local_source = os.path.join(l10n_cache_top, locale)
    source = remote_source if local_source == None else local_source
    do_checkout(source, destdir, tag)

    (ret, out) = do_exec(['hg', 'tip'], cwd=destdir, quiet=True)
    for line in out.split('\n'):
        if line.startswith('changeset:'):
            changesets.write('%s %s\n' % (locale, line.split()[1].strip()))
            print 'Got changeset %s' % line.split()[1].strip()
            break

def checkout_upstream_l10n(base, cache, tag, got_locales, all_locales, shipped_locales):
    print '\n\n*** Checking out l10n source from %s%s ***\n' % (base, ' using cache from %s' % cache if cache != None else '')
    lists = []
    if all_locales != None:
        al = open(all_locales, 'r')
        lists.append(al)
    lists.append(open(shipped_locales, 'r'))
    l10ndir = 'l10n'
    if not os.path.isdir(l10ndir):
        os.makedirs(l10ndir)
    changesets = open(os.path.join(l10ndir, 'changesets'), 'w')
    try:
        for l10nlist in lists:
            for line in l10nlist:
                locale = line.split(' ')[0].strip()
                if locale.startswith('#') or locale in got_locales or locale == 'en-US':
                    continue

                if l10nlist != al: print 'WARNING: Locale %s is not in all-locales. This is an upstream oversight' % locale

                try:
                    checkout_locale(base, cache, locale, tag, changesets)
                    got_locales[locale] = 1
                except Exception as e:
                    # checkout_locale will throw if the specified revision isn't found
                    # In this case, omit it from the tarball
                    print >> sys.stderr, 'Failed to checkout %s' % locale
                    localedir = os.path.join(l10ndir, locale)
                    if os.path.exists(localedir):
                        shutil.rmtree(localedir)
    finally:
        for l10nlist in lists:
            l10nlist.close()
        changesets.close()

def checkout_compare_locales(cache, tag):
    print '\n\n*** Checking out compare-locales ***\n'
    remote_source = 'https://hg.mozilla.org/build/compare-locales'
    local_source = None
    if cache != None:
        ensure_cache(remote_source, cache)
        local_source = os.path.join(cache, 'compare-locales')
    source = remote_source if local_source == None else local_source
    do_checkout(source, 'compare-locales', tag=tag)

def checkout_source(repo, cache, tag):
    print '\n\n*** Checking out source from %s%s ***\n' % (repo, ' using cache from %s' % cache if cache != None else '')
    local_source = None
    if cache != None:
        ensure_cache(repo, cache)
        local_source = os.path.join(cache, os.path.basename(repo))
    source = repo if local_source == None else local_source
    do_checkout(source, os.getcwd(), tag=tag)

def check_dependencies():
    DEPENDENCIES = [
        [ 'hg', 'mercurial' ],
        [ 'tar', 'tar' ]
    ]

    print 'Checking dependencies'
    for depend in DEPENDENCIES:
        if os.path.isabs(depend[0]) and not os.access(depend[0], os.X_OK):
            raise DependencyNotFound(depend)
        else:
            found = False
            for path in os.environ['PATH'].split(os.pathsep):
                if os.access(os.path.join(path, depend[0]), os.X_OK):
                    found = True
                    break
            if found == False:
                raise DependencyNotFound(depend)

def cleanup_working_dir(origwd):
    os.chdir(origwd)
    shutil.rmtree('.mozsource')

def setup_working_dir(name):
    topwrkdir = os.path.abspath('.mozsource')
    if os.path.exists(topwrkdir):
        shutil.rmtree(topwrkdir)

    working_dir = os.path.abspath('.mozsource/%s' % name)

    os.makedirs(working_dir)
    os.chdir(working_dir)

if __name__ == '__main__':
    usage = 'usage: %prog [options]'
    parser = OptionParser(usage=usage)
    parser.add_option('-r', '--repo', dest='repo', help='The remote repository from which to pull the main source')
    parser.add_option('-c', '--cache', dest='cache', help='A local cache of the remote repositories')
    parser.add_option('-l', '--l10n-base-repo', dest='l10nbase', help='The base directory of the remote repositories to pull l10n data from')
    parser.add_option('-t', '--tag', dest='tag', help='Release tag to base the checkout on')
    parser.add_option('-n', '--name', dest='name', help='The package name')
    parser.add_option('-a', '--application', dest='application', help='The application to build')

    (options, args) = parser.parse_args()

    if options.repo == None:
        parser.error('Must specify a remote repository')

    if options.name == None:
        parser.error('Must specify a package name')

    if options.application == None:
        parser.error('Must specify an application')

    fd = open('debian/config/tarball.conf', 'r')
    settings = json.load(fd)
    fd.close()

    saved_cwd = os.getcwd()
    check_dependencies()
    setup_working_dir(options.name)

    if options.cache != None and not os.path.isabs(options.cache):
        options.cache = os.path.join(os.getcwd(), options.cache)

    checkout_source(options.repo, options.cache, options.tag)
    checkout_compare_locales(options.cache, options.tag)

    need_moz = settings['need-post-checkout'] if 'need-post-checkout' in settings else False
    if need_moz:
        post_checkout(options.repo, options.cache, options.tag)

    # XXX: In the future we may have an additional l10n source from Launchpad
    if options.l10nbase != None:
        got_locales = {}
        shipped_locales = os.path.join(options.application, 'locales/shipped-locales')
        blacklist_file = settings['l10n-blacklist'] if 'l10n-blacklist' in settings else None
        if blacklist_file != None and not os.path.isabs(blacklist_file):
            blacklist_file = os.path.join(saved_cwd, blacklist_file)
        checkout_upstream_l10n(options.l10nbase, options.cache, options.tag, got_locales,
                               os.path.join(options.application, 'locales/all-locales'),
                               shipped_locales)
        verify_all_locales(got_locales, blacklist_file, shipped_locales)

    version = determine_upstream_version(options.repo, options.tag,
                                         os.path.join(options.application, 'config/version.txt'),
                                         need_moz)
    pack_orig_source(options.name, version, saved_cwd,
                     settings['includes'], settings['excludes'])

    cleanup_working_dir(saved_cwd)
