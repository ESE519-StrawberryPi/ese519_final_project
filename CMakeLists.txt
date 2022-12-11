cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
include(example_auto_set_url.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

project(final_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
pico_sdk_init()

add_executable(digital_piano main.c)

pico_enable_stdio_usb(digital_piano 1)

pico_generate_pio_header(digital_piano ${CMAKE_CURRENT_LIST_DIR}/utils/pwm.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/utils)

target_sources(digital_piano PRIVATE
        main.c
        utils/audio_generator.h
        utils/audio_generator.c
        utils/play.h
        utils/play_mode.c
        utils/replay_mode.c
        utils/pwm_utils.c
        utils/pwm_utils.h
        utils/sl_utils.c
        utils/sl_utils.h
        utils/game_mode.c
        utils/game_mode.h
        zrx_543_driver/zrx543_driver.h
        zrx_543_driver/zrx543_driver.c
        st7735_driver/st7735_driver.h
        st7735_driver/st7735_driver.c
        st7735_driver/fonts.h
        st7735_driver/fonts.c
        st7735_driver/DEV_Config.h
        st7735_driver/DEV_Config.c
        config.h
    )

target_link_libraries(
    digital_piano
    pico_stdlib
    hardware_dma
    hardware_pio
    hardware_timer
    hardware_clocks
    hardware_pwm
    hardware_flash
    hardware_spi
    hardware_i2c
    pico_multicore
)
# example_auto_set_url(audio)
pico_add_extra_outputs(digital_piano)
