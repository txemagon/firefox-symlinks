#!/usr/bin/python

import os
import os.path
import sys
from optparse import OptionParser
from subprocess import Popen
import tempfile
import shutil

skel = {
  '.config/user-dirs.dirs':
'''# This file is written by xdg-user-dirs-update
# If you want to change or add directories, just edit the line you're
# interested in. All local changes will be retained on the next run
# Format is XDG_xxx_DIR="$HOME/yyy", where yyy is a shell-escaped
# homedir-relative path, or XDG_xxx_DIR="/yyy", where /yyy is an
# absolute path. No other format is supported.
# 
XDG_DESKTOP_DIR="$HOME/Desktop"
XDG_DOWNLOAD_DIR="$HOME/Downloads"
XDG_TEMPLATES_DIR="$HOME/Templates"
XDG_PUBLICSHARE_DIR="$HOME/Public"
XDG_DOCUMENTS_DIR="$HOME/Documents"
XDG_MUSIC_DIR="$HOME/Music"
XDG_PICTURES_DIR="$HOME/Pictures"
XDG_VIDEOS_DIR="$HOME/Videos"'''
}

class TestRunHelper(OptionParser):

  def __init__(self, runner, get_runner_parser_cb, pass_args=[], paths=[], root=None, need_x=False, need_dbus=False, need_wm=False):
    OptionParser.__init__(self)

    assert root != None

    self.root = root
    self._pass_args = pass_args
    self._need_x = need_x
    self._need_dbus = need_dbus
    self._need_wm = need_wm

    assert not need_wm or (need_wm and need_x)

    if self._need_x:
      self.add_option('--own-display',
                      action='store_true', dest='wantOwnDisplay', default=False,
                      help='Run the test inside its own X session')
    if self._need_dbus:
      self.add_option('--own-session-bus',
                      action='store_true', dest='wantOwnSessionBus', default=False,
                      help='Run the test with its own dbus session')

    runner = os.path.join(self.root, runner)
    if os.path.isdir(os.path.join(os.path.dirname(__file__), 'python')):
      sys.path.insert(0, os.path.join(os.path.dirname(__file__), 'python'))
    sys.path.insert(0, os.path.dirname(runner))

    for path in reversed(paths):
      sys.path.insert(0, os.path.join(self.root, path))

    self._runner_global = {}
    self._runner_global['__file__'] = runner
    saved_argv0 = sys.argv[0]
    sys.argv[0] = runner
    try:
      execfile(runner, self._runner_global)

      runner_parser = get_runner_parser_cb(self._runner_global)

      for arg in self._pass_args:
        assert runner_parser.has_option(arg)
        self.add_option(runner_parser.get_option(arg))

    finally:
      sys.argv[0] = saved_argv0

  def run(self, defaults=[], pre_run_cb=None):
    (options, args) = self.parse_args()

    respawn_args = []
    strip_args = []

    os.putenv('MOZ_PLUGIN_PATH', os.path.join(self.root, 'plugins'))

    if self._need_x and (options.wantOwnDisplay or os.getenv('DISPLAY') == None):
      respawn_args.extend(['xvfb-run', '-a', '-s', '-screen 0 1024x768x24 -extension MIT-SCREEN-SAVER'])
      strip_args.append('--own-display')
    if self._need_dbus and (options.wantOwnSessionBus or os.getenv('DBUS_SESSION_BUS_ADDRESS') == None):
      respawn_args.extend(['dbus-launch', '--exit-with-session'])
      strip_args.append('--own-session-bus')

    if len(respawn_args) > 0:
      import subprocess

      i = 0
      while len(sys.argv) > 0 and i < len(sys.argv):
        arg = sys.argv[i]
        if arg in strip_args:
          del sys.argv[i]
          if self.has_option(arg) and self.get_option(arg).action == 'store':
            del sys.argv[i]
        else:
          i+=1

      respawn_args.extend(sys.argv)
      return subprocess.call(respawn_args, stdin=sys.stdin, stdout=sys.stdout, stderr=sys.stderr)

    sys.argv = []
    argv = sys.argv
    argv.append(self._runner_global['__file__'])

    for arg in self._pass_args:
      opt = self.get_option(arg)
      action = opt.action
      val = getattr(options, opt.dest)
      if val == opt.default and action != 'append':
        continue
      if action == 'store':
        if val != None:
          argv.extend([arg, str(val)])
      elif action == 'store_true':
        if val == True:
          argv.append(arg)
      elif action == 'store_false':
        if val == False:
          argv.append(arg)
      elif action == 'append':
        if val != None:
          for v in val:
            argv.extend([arg, str(v)])
      else:
        raise RuntimeError('Unexpected argument type with action "%s"' % action)

    for arg in defaults:
      if arg not in argv:
        argv.extend([arg, defaults[arg]() if hasattr(defaults[arg], '__call__') else defaults[arg]])

    if pre_run_cb != None:
      pre_run_cb(options, args)

    argv.extend(args)

    tmphome = tempfile.mkdtemp()
    os.environ['HOME'] = tmphome
    for name in skel:
      os.mkdir(os.path.dirname(os.path.join(tmphome, name)))
      with open(os.path.join(tmphome, name), 'w+') as f:
        print >>f, skel[name]

    if self._need_wm:
      wm = Popen(['/usr/bin/metacity', '--sm-disable', '--no-composite'])

    try:
      return self._runner_global['main']()
    finally:
      if self._need_wm:
        wm.terminate()
      shutil.rmtree(tmphome)
