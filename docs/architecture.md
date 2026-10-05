# Architecture

The project follows a layered Linux software architecture.

```text
User Space
  CLI / Examples / Tests
          |
       Runtime
          |
  Accelerator API
      /   |   \
    FIR Conv  DFT
          |
 Optional ioctl()
          |
Kernel Space
  virtual_dsp.ko
          |
 /dev/virtual_dsp
```

The driver uses the Linux misc-device framework and an ioctl interface for
FIR requests. The software path remains available for development and testing.
