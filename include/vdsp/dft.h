#ifndef VDSP_DFT_H
#define VDSP_DFT_H
#include <stddef.h>
int vdsp_dft(const double *x, size_t n, double *re, double *im);
#endif
