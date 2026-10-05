#include <stdio.h>
#include <string.h>
#include "vdsp/cli.h"
#include "vdsp/runtime.h"

int vdsp_cli_run(int argc, char **argv)
{
    if (argc > 1 && (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h"))) {
        printf("VirtualDSPAccelerator\n");
        printf("Usage: %s [--demo]\n", argv[0]);
        return 0;
    }
    return vdsp_runtime_run_demo();
}
