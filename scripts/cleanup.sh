#!/bin/sh
set +e
sudo rmmod virtual_dsp 2>/dev/null
rm -rf build
make -C driver clean 2>/dev/null
echo "Cleanup completed."
