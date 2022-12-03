//
// Created by Haoze Wu on 12/2/22.
//
#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pwm.pio.h"
#include "notes_3.h"
#include "hardware/clocks.h"

#define NOTE_AUDIO_PIN 26

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

void free_mode(){

    // uint cycles=clock_get_hz(clk_sys)/(freq*clk_div);
    uint clk_div = 0x04;
    uint32_t period = 64934;

    // Fine tuning the clock so that the frequency of the music is normal
    uint32_t clk = 125000;
    set_sys_clock_khz(clk, true);

    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pwm_program);
    printf("Loaded program at %d\n", offset);
    pwm_program_init(pio, sm, offset,NOTE_AUDIO_PIN);

    // Exit the loop:
    printf("\n If you want to exit the loop, please press 'q'.");

    while(true){

        char c = getchar_timeout_us(4 * 1000 * 1000);
        if(c == 'q'){
            break;
        }

        printf("%c",c);

        switch (c) {
            case 'a':
                pio_sm_set_clkdiv(pio,sm,(float)8.8125);
                pio_pwm_set_period(pio, sm, 65476);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 's':
                pio_sm_set_clkdiv(pio,sm,(float)6.5);
                pio_pwm_set_period(pio, sm, 65485);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'd':
                pio_sm_set_clkdiv(pio,sm,(float)5.8125);
                pio_pwm_set_period(pio, sm, 65239);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'f':
                pio_sm_set_clkdiv(pio,sm,(float)5.5);
                pio_pwm_set_period(pio, sm, 65077);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'g':
                pio_sm_set_clkdiv(pio,sm,(float)4.875);
                pio_pwm_set_period(pio, sm, 65409);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'h':
                pio_sm_set_clkdiv(pio,sm,(float)4.375);
                pio_pwm_set_period(pio, sm, 64934);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'j':
                pio_sm_set_clkdiv(pio,sm,(float)3.875);
                pio_pwm_set_period(pio, sm, 65314);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
        }

    }

}


int main(){
    stdio_init_all();

    // uint cycles=clock_get_hz(clk_sys)/(freq*clk_div);
    uint clk_div = 0x04;
    uint32_t period = 64934;

    // Fine tuning the clock so that the frequency of the music is normal
    uint32_t clk = 125000;
    set_sys_clock_khz(clk, true);

    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pwm_program);
    printf("Loaded program at %d\n", offset);
    pwm_program_init(pio, sm, offset, NOTE_AUDIO_PIN);


    while(true){

        char c = getchar_timeout_us(4 * 1000 * 1000);
        // Exit the loop:
        printf("\n If you want to exit the loop, please press 'q'.");
        if(c == 'q'){
            break;
        }

        printf("%c",c);

        switch (c) {
            case 'a':
                pio_sm_set_clkdiv(pio,sm,8.8125);
                pio_pwm_set_period(pio, sm, 65476);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 's':
                pio_sm_set_clkdiv(pio,sm,6.5);
                pio_pwm_set_period(pio, sm, 65485);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'd':
                pio_sm_set_clkdiv(pio,sm,5.8125);
                pio_pwm_set_period(pio, sm, 65239);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'f':
                pio_sm_set_clkdiv(pio,sm,5.5);
                pio_pwm_set_period(pio, sm, 65077);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'g':
                pio_sm_set_clkdiv(pio,sm,(float)4.875);
                pio_pwm_set_period(pio, sm, 65409);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'h':
                pio_sm_set_clkdiv(pio,sm,(float)4.375);
                pio_pwm_set_period(pio, sm, 64934);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
            case 'j':
                pio_sm_set_clkdiv(pio,sm,(float)3.875);
                pio_pwm_set_period(pio, sm, 65314);
                pio_pwm_set_level(pio,sm,period/2);
                sleep_ms(100);
                pio_pwm_set_level(pio,sm,0);
                break;
        }


    }

}