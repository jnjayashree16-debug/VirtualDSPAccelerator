#include <stdio.h>
#include "vdsp/logger.h"
void vdsp_log(const char *level,const char *message)
{ printf("[%s] %s\n",level,message); }
