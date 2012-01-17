// To run this file:
//   LD_LIBRARY_PATH=.libs  GI_TYPELIB_PATH=.  ../run gjs ./test.js

const Guestfs = imports.gi.Guestfs;

print('Starting');
var g = new Guestfs.Session();

var o = new Guestfs.AddDriveOpts({format: 'raw', iface: 'virtio'});
g.add_drive_opts('../tests/guests/fedora.img', null);
g.launch();

r = g.inspect_os();
m = g.inspect_get_mountpoints(r[0]);
print(m['/boot']);

print('Finished');
