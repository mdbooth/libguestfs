// To run this file:
//   LD_LIBRARY_PATH=.libs  GI_TYPELIB_PATH=.  ../run gjs ./test.js

const Guestfs = imports.gi.Guestfs;

print('Starting');
var g = new Guestfs.Session();
//g.add_drive('/home/mbooth/tmp/foo.img');
//g.launch();

var v = g.version();

//var o = new Guestfs.AddDriveOpts({readonly: 3});
var o = new Guestfs.AddDriveOpts();
print(o.readonly);
o.readonly = true;
print(o.readonly);
o.readonly = false;
print(o.readonly);
o.readonly = Guestfs.Tristate.NONE;
print(o.readonly);

print(v.major + '.' + v.minor + '.' + v.release);
print('Finished');
