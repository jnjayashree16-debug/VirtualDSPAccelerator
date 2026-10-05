#ifndef VDSP_CONVOLUTION_H
#define VDSP_CONVOLUTION_H
#include <stddef.h>
int vdsp_convolution(const double *x, size_t n, const double *h, size_t m, double *y);
#endif
