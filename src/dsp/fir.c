#include "vdsp/fir.h"
int vdsp_fir(const double *x,size_t n,const double *h,size_t m,double *y)
{
    if (!x || !h || !y || !n || !m) return -1;
    for (size_t i=0;i<n;i++) {
        y[i]=0.0;
        for (size_t k=0;k<m;k++)
            if (i>=k) y[i]+=x[i-k]*h[k];
    }
    return 0;
}
