#include <stdio.h>
#include "vdsp/dft.h"
int main(void){double x[]={1,0,0,0},re[4],im[4];vdsp_dft(x,4,re,im);for(int i=0;i<4;i++)printf("X[%d]=%.2f%+.2fi\n",i,re[i],im[i]);return 0;}
