cmake_minimum_required(VERSION 3.16)
project(VirtualDSPAccelerator C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(vdsp_core
    src/dsp/fir.c
    src/dsp/convolution.c
    src/dsp/dft.c
    src/common/logger.c
    src/common/utils.c
)

add_executable(virtual_dsp
    src/main.c
    src/cli/cli.c
    src/runtime/runtime.c
    src/accelerator/accelerator.c
)

target_link_libraries(virtual_dsp PRIVATE vdsp_core m)

add_executable(fir_demo examples/fir_demo.c)
target_link_libraries(fir_demo PRIVATE vdsp_core m)

add_executable(convolution_demo examples/convolution_demo.c)
target_link_libraries(convolution_demo PRIVATE vdsp_core m)

add_executable(dft_demo examples/dft_demo.c)
target_link_libraries(dft_demo PRIVATE vdsp_core m)

add_executable(driver_demo examples/driver_demo.c)
target_link_libraries(driver_demo PRIVATE vdsp_core m)

enable_testing()
add_executable(dsp_test tests/dsp_test.c)
target_link_libraries(dsp_test PRIVATE vdsp_core m)
add_test(NAME DSPCoreTest COMMAND dsp_test)
