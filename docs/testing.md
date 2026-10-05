# Testing

Build and run all tests:

```bash
./scripts/build.sh
```

Or:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j2
ctest --test-dir build --output-on-failure
```

Expected:

```text
100% tests passed
```

Driver validation:

```bash
./scripts/build_driver.sh
sudo insmod driver/virtual_dsp.ko
ls -l /dev/virtual_dsp
./build/driver_demo
sudo rmmod virtual_dsp
```
