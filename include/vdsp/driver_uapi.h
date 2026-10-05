#ifndef VDSP_DRIVER_UAPI_H
#define VDSP_DRIVER_UAPI_H

#include <linux/ioctl.h>

#define VDSP_IOCTL_MAGIC 'V'
#define VDSP_MAX_DRIVER_SAMPLES 64
#define VDSP_MAX_DRIVER_TAPS 16

struct vdsp_fir_request {
    int input[VDSP_MAX_DRIVER_SAMPLES];
    unsigned int input_len;
    int coeff[VDSP_MAX_DRIVER_TAPS];
    unsigned int coeff_len;
    int output[VDSP_MAX_DRIVER_SAMPLES];
};

#define VDSP_IOCTL_FIR _IOWR(VDSP_IOCTL_MAGIC, 1, struct vdsp_fir_request)

#endif
