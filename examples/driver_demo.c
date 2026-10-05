#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "vdsp/driver_uapi.h"
int main(void){
 int fd=open("/dev/virtual_dsp",O_RDWR);
 if(fd<0){perror("open /dev/virtual_dsp");return 1;}
 struct vdsp_fir_request r={{0},5,{0},3,{0}};
 int x[]={1,2,3,4,5},h[]={1,1,1};
 for(int i=0;i<5;i++)r.input[i]=x[i];
 for(int i=0;i<3;i++)r.coeff[i]=h[i];
 r.input_len=5;r.coeff_len=3;
 if(ioctl(fd,VDSP_IOCTL_FIR,&r)<0){perror("ioctl");close(fd);return 1;}
 for(int i=0;i<5;i++)printf("driver y[%d]=%d\n",i,r.output[i]);
 close(fd);return 0;
}
