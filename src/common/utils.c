#include <stdio.h>
#include "vdsp/utils.h"
void vdsp_print_vector(const char *name,const double *v,unsigned long n)
{
    printf("%s: ",name);
    for(unsigned long i=0;i<n;i++) printf("%.3f ",v[i]);
    putchar('\n');
}
