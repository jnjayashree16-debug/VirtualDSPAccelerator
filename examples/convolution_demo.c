#include <stdio.h>
#include "vdsp/convolution.h"
int main(void){double x[]={1,2,1},h[]={1,1,1},y[5];vdsp_convolution(x,3,h,3,y);for(int i=0;i<5;i++)printf("y[%d]=%.2f\n",i,y[i]);return 0;}
