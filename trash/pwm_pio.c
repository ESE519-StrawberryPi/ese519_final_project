///**
// * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
// *
// * SPDX-License-Identifier: BSD-3-Clause
// */
//
//#include <stdio.h>
//
//#include "pico/stdlib.h"
//#include "hardware/pio.h"
//#include "pwm.pio.h"
//#include "resources/notes_3.h"
//#include "hardware/clocks.h"
//
//#define MUSIC_AUDIO_PIN 1
//
//// Write `period` to the input shift register
//void pio_pwm_set_period(PIO pio, uint sm, uint32_t period) {
//    pio_sm_set_enabled(pio, sm, false);
//    pio_sm_put_blocking(pio, sm, period);
//    pio_sm_exec(pio, sm, pio_encode_pull(false, false));
//    pio_sm_exec(pio, sm, pio_encode_out(pio_isr, 32));
//    pio_sm_set_enabled(pio, sm, true);
//}
//
//// Write `level` to TX FIFO. State machine will copy this into X.
//void pio_pwm_set_level(PIO pio, uint sm, uint32_t level) {
//    pio_sm_put_blocking(pio, sm, level);
//}
//
//
//// play the given music data
//void play_mode(uint8_t *data, int dataLen){
//    // uint cycles=clock_get_hz(clk_sys)/(freq*clk_div);
//    // uint clk_div = 8;
//    uint32_t period = 250;
//
//    // Fine-tune the clock so that the frequency of the music is normal.
//    uint32_t clk = 66000;
//    set_sys_clock_khz(clk, true);
//
//    // Set up the pio
//    PIO pio = pio0;
//    uint sm = 0;
//    uint offset = pio_add_program(pio, &pwm_program);
//    printf("\nLoaded program at %d", offset);
//
//    pwm_program_init(pio, sm, offset, MUSIC_AUDIO_PIN);
//    pio_pwm_set_period(pio, sm, period);
//
//    int position = 0;
//    int loopNum = 0;
//    while (true) {
//        loopNum++;
//        if(loopNum > 3){
//            printf("\n If you want to exit the loop, please press 'q'.");
//            char c = getchar_timeout_us(2 * 1000);
//            if(c == 'q'){
//                break;
//            }else{
//                loopNum = 0;
//            }
//        }
//
//        // if (position < (DATA_LENGTH << 3) - 1){
//        if ( position < (dataLen << 2)-1){
//            pio_pwm_set_level(pio0, sm, data[position>>2]);
//            position++;
//        }else{
//            position = 0;
//            pio_pwm_set_level(pio0,sm, 0);
//            printf("\nReset the position");
//            printf("\nRestart again");
//        }
//    }
//}
//
//
//
////int main() {
////    stdio_init_all();
////    // sleep_ms(10000);
////
////    // float freq = 440.0f;
////
////
////    // uint cycles=clock_get_hz(clk_sys)/(freq*clk_div);
////    // uint clk_div = 8;
////    uint32_t period = 250;
////
////    // Fine tuning the clock so that the frequency of the music is normal
////    uint32_t clk = 66000;
////    set_sys_clock_khz(clk, true);
////
////    // todo get free sm
////    PIO pio = pio0;
////    uint sm = 0;
////    uint offset = pio_add_program(pio, &pwm_program);
////    printf("Loaded program at %d\n", offset);
////
////    pwm_program_init(pio, sm, offset,MUSIC_AUDIO_PIN);
////    pio_pwm_set_period(pio, sm, period);
////
////    int position = 0;
////    while (true) {
////
////        // sleep_ms(100);
////        // if (position < (DATA_LENGTH << 3) - 1){
////        if ( position < (DATA_LENGTH_3<<2)-1){
////
////            // pio_pwm_set_level(pio0,sm, DATA[position >> 3]);
////            pio_pwm_set_level(pio0,sm, DATA_3[position>>2]);
////            // printf("\n%d",DATA[position>>3]);
////            position++;
////
////        }else{
////            position = 0;
////            pio_pwm_set_level(pio0,sm, 0);
////
////            printf("\nReset the position");
////            // sleep_ms(3000);
////            printf("\nRestart again");
////        }
////    }
////}
