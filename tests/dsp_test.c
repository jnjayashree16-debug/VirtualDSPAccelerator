#include <stdio.h>
#include <math.h>
#include "vdsp/fir.h"
#include "vdsp/convolution.h"
#include "vdsp/dft.h"
static int near(double a,double b){return fabs(a-b)<1e-9;}
int main(void){
 double x[]={1,2,3},h[]={1,1},y[3];
 vdsp_fir(x,3,h,2,y);
 if(!near(y[0],1)||!near(y[1],3)||!near(y[2],5)) return 1;
 double c[4];vdsp_convolution(x,3,h,2,c);
 if(!near(c[0],1)||!near(c[1],3)||!near(c[2],5)||!near(c[3],3)) return 2;
 puts("All DSP tests passed.");
 return 0;
}
