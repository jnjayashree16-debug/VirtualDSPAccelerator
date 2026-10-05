#ifndef VDSP_FIR_H
#define VDSP_FIR_H
#include <stddef.h>
int vdsp_fir(const double *x, size_t n, const double *h, size_t m, double *y);
#endif
