#!/bin/sh
set -eu
if [ ! -f driver/virtual_dsp.ko ]; then
  ./scripts/build_driver.sh
fi
sudo insmod driver/virtual_dsp.ko
echo "Driver loaded."
ls -l /dev/virtual_dsp
