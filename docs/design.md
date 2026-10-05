# Design

## DSP layer
Contains independent C implementations of FIR, convolution and DFT.

## Accelerator layer
Provides a stable API between applications and DSP implementations.

## Runtime layer
Coordinates the demonstration and reports results.

## Driver layer
Implements a Linux character-device interface. The driver accepts an FIR
request using ioctl and performs the operation in kernel space.

## Why this architecture
The separation makes the DSP algorithm reusable while allowing a future
hardware accelerator or DMA-backed implementation to replace the software
backend.
