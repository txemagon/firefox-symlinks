#!/usr/bin/perl -w

# (c) 2011, Fabien Tassin <fta@sofaraway.org>

# Enable/disable quilt patches depending on the dist
#
# Example:
#
# in debian/rules:
#
# DEBIAN_DIST_VERSION := $(shell lsb_release -cn)
#
# # must be before the patchsys-quilt.mk include
# post-patches::
# 	perl $(CURDIR)/debian/enable-dist-patches.pl $(DEBIAN_DIST_VERSION) $(CURDIR)/debian/patches/series
#
# clean::
# 	perl $(CURDIR)/debian/enable-dist-patches.pl --clean $(CURDIR)/debian/patches/series
#
# in debian/patches/series:
#
# #@DIST:lucid,natty@patch_for_lucid_and_natty.patch
# #@DIST:lucid@patch_for_lucid_only.patch
#
# for natty, only the 1st one will be enabled
# for lucid, both will be enabled
# for any other value, both will stay disabled
# so it could be used to revert the series to its
# original state (useful for the clean target)

use strict;

my $tmp = shift;

my $cleanup = ($tmp eq "--clean") ? 1 : 0;

my $dist = "";
my $arch = "";
my $series = "debian/patches/series";

$cleanup || do {
  $dist = $tmp;
  $arch = shift;
};

$cleanup && do {
  (-e "$series.in") && do unlink($series);
  exit(0);
};

open(I, "$series.in") || do {
  print STDERR "Can't open $series.in: $!\n";
  exit(1);
};
open(O, "> $series.new") || do {
  print STDERR "Can't open $series.new: $!\n";
  exit(1);
};
my $line;
while (defined ($line = <I>)) {
  $line =~ m/^#\@(.*)\@\s*(.*)/ && do {
    my ($c, $p) = ($1, $2);
    my @cs = split(':', $c);
    my $matches = 1;
    do {
      foreach my $condition (@cs) {
        $condition =~ m/^DIST\=(.*)/ && do {
          my $v = $1;
          if (not (($v =~ m/(^|,)$dist($|,)/i && $v !~ m/^!/i) ||
                   ($v =~ m/^!/i && $v !~ m/(^|,|!)$dist($|,)/i))) {
            $matches = 0;
          }
          1;
        } || $condition =~ m/^ARCH\=(.*)/ && do {
          my $v = $1;
          if (not (($v =~ m/(^|,)$arch($|,)/i && $v !~ m/^!/i) ||
                   ($v =~ m/^!/i && $v !~ m/(^|,|!)$arch($|,)/i))) {
             $matches = 0;
          }
          1;
        } || die "Invalid syntax";
      }
    };
    print O "$p\n" if $matches;
    # check if the next line is also the same
    $line = <I>;
    last unless defined $line;
    redo unless $line eq "$p\n";
    1;
  } || do {
    $line =~ m/^#(.*)/ || do print O $line;
  };
}
close I;
close O;
rename "$series.new", $series or do {
  print "Can't rename $series.new to $series: $!\n";
  exit(1);
};
exit(0);
