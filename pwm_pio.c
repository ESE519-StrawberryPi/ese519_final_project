/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pwm.pio.h"
#include "music.h"

#define AUDIO_PIN 26

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

int main() {
    stdio_init_all();

    set_sys_clock_khz(22000, true);

    // todo get free sm
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pwm_program);
    printf("Loaded program at %d\n", offset);

    pwm_program_init(pio, sm, offset, AUDIO_PIN);
    pio_pwm_set_period(pio, sm, (1u << 8) - 1);

    int position = 0;
    while (true) {
        if (position < (DATA_LENGTH << 3) - 1){
            uint8_t chant=DATA[position >> 3];
            pio_pwm_set_level(pio0,sm, DATA[position >> 3]);
            position++;
            printf("\n%d",DATA[position>>3]);
        }
        else{
            position = 0;
            printf("\nReset the position");
        }
    }
}
