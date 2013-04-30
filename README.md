firefox-symlinks
================

This patch prevent firefox from resolving symlinks whith the file://
scheme.

Just add the Boolean preference (in about:config):

   network.file.allowSymlinks

Set it to true.

Modified from Ubuntu's apt-get source

firefox-20.0+build1



