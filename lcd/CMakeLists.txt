cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
include(example_auto_set_url.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

project(final_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
pico_sdk_init()

add_executable(lcd_display main.c)

pico_enable_stdio_usb(lcd_display 1)


target_sources(lcd_display PRIVATE
        main.c
        st7735_driver.h
        st7735_driver.c
        DEV_Config.c
        DEV_Config.h
        fonts.c
        fonts.h
    )

target_link_libraries(
    lcd_display
    pico_stdlib
    hardware_dma
    hardware_pio
    hardware_timer
    hardware_clocks
    hardware_pwm
    hardware_flash
    hardware_spi
    hardware_i2c
)
# example_auto_set_url(audio)
pico_add_extra_outputs(lcd_display)
