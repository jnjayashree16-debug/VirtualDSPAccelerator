#!/bin/sh
set -eu
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j2
ctest --test-dir build --output-on-failure
echo "Build and tests completed."
