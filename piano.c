/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pwm.pio.h"
#include "audio.h"
#include "hardware/clocks.h"

#include "notes_1.h"
#include "notes_2.h"
#include "notes_3.h"

#define AUDIO_PIN 1

// Write `period` to the input shift register
void pio_pwm_set_period(PIO pio, uint sm, uint32_t period) {
    pio_sm_set_enabled(pio, sm, false);
    pio_sm_put_blocking(pio, sm, period);
    pio_sm_exec(pio, sm, pio_encode_pull(false, false));
    pio_sm_exec(pio, sm, pio_encode_out(pio_isr, 32));
    pio_sm_set_enabled(pio, sm, true);
}
    
// Write `level` to TX FIFO. State machine will copy this into X.
void pio_pwm_set_level(PIO pio, uint sm, uint32_t level) {
    pio_sm_put_blocking(pio, sm, level);
}

// Play function
void play(int note, PIO pio, uint sm){
    int position = 0;
    switch(note){
        case 'a':
            position = 0;
            printf("\nPlaying song 1");
            while (position < (DATA_LENGTH_1/2 ) - 1){
                pio_pwm_set_level(pio, sm, DATA_1[position>>2]);
                position++;
            }
            pio_pwm_set_level(pio0, sm, 0);
            break;
        case 's':
            position = 0;
            printf("\nPlaying song 2");
            while (position < (DATA_LENGTH_2/2 ) - 1){
                pio_pwm_set_level(pio, sm, DATA_2[position>>2]);
                position++;
            }
            pio_pwm_set_level(pio0, sm, 0);
            break;
        case 'd':
            position = 0;
            printf("\nPlaying song 3");
            while (position < (DATA_LENGTH_3 /2) - 1){
                pio_pwm_set_level(pio, sm, DATA_3[position>>2]);
                position++;
            }
            pio_pwm_set_level(pio0, sm, 0);
            break;
    } 
    
}

int main() {
    stdio_init_all();
    sleep_ms(5000);
    printf("WELCOME!\n");
    
    uint32_t period = 250;

    // Fine tuning the clock so that the frequency of the music is normal
    uint32_t clk = 66000;
    set_sys_clock_khz(clk, true);

    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pwm_program);
    printf("Loaded program at %d\n", offset);

    pwm_program_init(pio, sm, offset,AUDIO_PIN);
    pio_pwm_set_period(pio, sm, period);

  
    while (true) {
        // sleep_ms(100);
        // if (position < (DATA_LENGTH << 3) - 1){
        printf("\n Getting input.");
        int c = getchar_timeout_us(4 * 1000 * 1000);
        printf("\n%c", c);
        play(c, pio, sm);
    }
            
}


      
        

