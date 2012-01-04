// To run this file:
//   LD_LIBRARY_PATH=.libs
//   GI_TYPELIB_PATH=.
// ../run gjs ./test.js

const Guestfs = imports.gi.Guestfs;

print('Starting');
var g = new Guestfs.Session();
//g.add_drive('/home/mbooth/tmp/foo.img');
//g.launch();

var v = g.version();

print(v.major + '.' + v.minor + '.' + v.release);
print('Finished');
