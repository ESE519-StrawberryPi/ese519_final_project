cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
include(example_auto_set_url.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

project(final_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
pico_sdk_init()

add_executable(pwm_pio record.c)

pico_enable_stdio_usb(pwm_pio 1)

pico_generate_pio_header(pwm_pio ${CMAKE_CURRENT_LIST_DIR}/pwm.pio)

target_link_libraries(
    pwm_pio
    pico_stdlib
    hardware_dma
    hardware_pio
    hardware_timer
    hardware_clocks
    hardware_pwm
    hardware_flash
)
# example_auto_set_url(audio)
pico_add_extra_outputs(pwm_pio)
