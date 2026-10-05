#include <stdio.h>
#include "vdsp/fir.h"
int main(void){double x[]={1,2,3,4,5},h[]={1,.5},y[5];vdsp_fir(x,5,h,2,y);for(int i=0;i<5;i++)printf("y[%d]=%.2f\n",i,y[i]);return 0;}
