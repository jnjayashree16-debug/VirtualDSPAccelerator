#include "vdsp/convolution.h"
int vdsp_convolution(const double *x,size_t n,const double *h,size_t m,double *y)
{
    if (!x || !h || !y || !n || !m) return -1;
    for (size_t i=0;i<n+m-1;i++) y[i]=0.0;
    for (size_t i=0;i<n;i++)
        for (size_t j=0;j<m;j++)
            y[i+j]+=x[i]*h[j];
    return 0;
}
