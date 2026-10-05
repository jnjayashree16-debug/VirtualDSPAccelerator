#ifndef VDSP_ACCELERATOR_H
#define VDSP_ACCELERATOR_H
#include <stddef.h>
int vdsp_accel_fir(const double *x, size_t n, const double *h, size_t m, double *y);
int vdsp_accel_convolution(const double *x, size_t n, const double *h, size_t m, double *y);
int vdsp_accel_dft(const double *x, size_t n, double *re, double *im);
#endif
