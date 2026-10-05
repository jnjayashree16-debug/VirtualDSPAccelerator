# VirtualDSPAccelerator

## Linux-Based Virtual DSP Accelerator & Character Device Driver Framework

VirtualDSPAccelerator is a C-based Linux project that demonstrates how DSP
algorithms can be organized as an accelerator architecture and exposed through
a Linux character-device driver interface.

### Implemented

- FIR filtering
- 1-D convolution
- DFT reference calculation
- Accelerator abstraction layer
- Linux misc/character-device driver
- ioctl interface
- CLI application
- Unit tests
- Documentation and execution scripts

### Technology constraints

- Language: C only
- OS: Linux
- Build: CMake
- Driver: Linux kernel module
- No Python, Java, or other application language

### Quick run

```bash
sudo apt update
sudo apt install -y build-essential cmake
chmod +x scripts/build.sh scripts/setup_driver.sh scripts/cleanup.sh
./scripts/build.sh
./build/virtual_dsp
./build/fir_demo
./build/convolution_demo
./build/dft_demo
ctest --test-dir build --output-on-failure
```

### Driver

The real `/dev/virtual_dsp` device requires a Linux kernel development tree
matching the running kernel.

Check:

```bash
ls -ld /lib/modules/$(uname -r)/build
```

If available:

```bash
./scripts/build_driver.sh
sudo insmod driver/virtual_dsp.ko
ls -l /dev/virtual_dsp
./build/driver_demo
```

Unload:

```bash
sudo rmmod virtual_dsp
```

### WSL note

The user-space DSP application can be built on WSL. A standard Microsoft WSL
kernel may not provide `/lib/modules/$(uname -r)/build`, so the kernel module
cannot be compiled there unless a matching kernel development environment is
provided. The project does not falsely claim that a WSL kernel driver is
running when it is not.

## Architecture

```text
CLI / Demo Application
        |
        v
Runtime Controller
        |
        v
Accelerator Abstraction
        |
   +----+----------------+
   |    |                |
  FIR Convolution       DFT
   |
   v
Linux Character Device / ioctl
        |
        v
virtual_dsp.ko
        |
        v
/dev/virtual_dsp
```

See `docs/architecture.md` and `docs/design.md`.
