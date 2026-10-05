#include <math.h>
#include "vdsp/dft.h"
int vdsp_dft(const double *x,size_t n,double *re,double *im)
{
    if (!x || !re || !im || !n) return -1;
    const double pi=acos(-1.0);
    for(size_t k=0;k<n;k++){
        re[k]=im[k]=0.0;
        for(size_t t=0;t<n;t++){
            double a=-2.0*pi*(double)k*(double)t/(double)n;
            re[k]+=x[t]*cos(a);
            im[k]+=x[t]*sin(a);
        }
    }
    return 0;
}
