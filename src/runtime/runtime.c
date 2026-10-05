#include <stdio.h>
#include "vdsp/runtime.h"
#include "vdsp/accelerator.h"
#include "vdsp/utils.h"
#include "vdsp/config.h"

int vdsp_runtime_run_demo(void)
{
    const double x[] = {1,2,3,4,5};
    const double h[] = {0.25,0.5,0.25};
    double y[5];

    printf("=== Virtual DSP Accelerator ===\n");
    printf("Architecture: C user-space runtime + DSP core + optional Linux driver\n");
    vdsp_accel_fir(x, 5, h, 3, y);
    vdsp_print_vector("FIR output", y, 5);
    printf("Demo completed successfully.\n");
    return 0;
}
