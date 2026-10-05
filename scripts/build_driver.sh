#!/bin/sh
set -eu
make -C driver
echo "Driver build completed: driver/virtual_dsp.ko"
