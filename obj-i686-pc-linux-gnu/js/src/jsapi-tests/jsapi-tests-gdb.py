"""GDB Python customization auto-loader for jsapi-tests executable"""

import os.path
sys.path[0:0] = [os.path.join('/home/txema/work/firefox-20.0+build1/js/src', 'gdb')]

import mozilla.autoload
mozilla.autoload.register(gdb.current_objfile())
