#!/bin/bash -
# libguestfs autobuild script
# Copyright (C) 2009-2011 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

# This script is used to download and test the latest tarball on
# Debian and other platforms.  It runs from a cron job and sends email
# to the mailing list about the status.

set -e

# Subject line of email prefix.
prefix="${1:-[autobuild]}"

# Where we send mail.
mailto="rjones@redhat.com"

# Move to temporary directory for building.
tmpdir="$(mktemp -d --tmpdir=/var/tmp)"
cd "$tmpdir"

# The libguestfs index page contains some hidden fields to help us
# find the latest version programmatically.
version=$(wget --no-cache -O- -q http://libguestfs.org |
          grep '^LATEST-VERSION:' | awk '{print $2}')
url=$(wget --no-cache -O- -q http://libguestfs.org |
      grep '^LATEST-URL:' | awk '{print $2}')
filename=$(basename "$url")
directory=$(basename "$url" .tar.gz)

echo "--------------------------------------------------"
echo "prefix     $prefix"
echo "libguestfs $version"
echo "url        $url"
echo "build dir  $tmpdir/$directory"
echo "--------------------------------------------------"

# Grab the latest tarball from upstream.
wget "$url"

# Unpack the tarball.
tar zxf "$filename"

# Enter directory.
cd "$directory"

# This function is called if any step fails.
failed ()
{
    mutt -s "$prefix libguestfs $version FAILED $1" "$mailto" -a ../build.log <<EOF
Autobuild failed.  See the attached log file.
EOF
}

# This function is called if the build is successful.
ok ()
{
    mutt -s "$prefix libguestfs $version ok" "$mailto" -a ../build.log <<EOF
Autobuild was successful.  The full log file is attached.
EOF
}

# Ensure that we get full debugging output.
export LIBGUESTFS_DEBUG=1
export LIBGUESTFS_TRACE=1

# Configure and build.
echo "configure"
./configure > ../build.log 2>&1 || {
    failed "configure"
    exit 1
}
echo "make"
make >> ../build.log 2>&1 || {
    failed "make"
    exit 1
}

# Run the tests.
echo "make check"
make check >> ../build.log 2>&1 || {
    failed "make check"
    exit 1
}

echo "finished"
ok