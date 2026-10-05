#include "vdsp/accelerator.h"
#include "vdsp/fir.h"
#include "vdsp/convolution.h"
#include "vdsp/dft.h"

int vdsp_accel_fir(const double *x,size_t n,const double *h,size_t m,double *y)
{ return vdsp_fir(x,n,h,m,y); }

int vdsp_accel_convolution(const double *x,size_t n,const double *h,size_t m,double *y)
{ return vdsp_convolution(x,n,h,m,y); }

int vdsp_accel_dft(const double *x,size_t n,double *re,double *im)
{ return vdsp_dft(x,n,re,im); }
