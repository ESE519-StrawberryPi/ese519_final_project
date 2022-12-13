//
// Created by Haoze Wu on 12/2/22.
//

#include "audio_generator.h"
#include "../zrx_543_driver/zrx543_driver.h"
#include "../st7735_driver/st7735_driver.h"
#include "sl_utils.h"



void play_a_note(PIO pio, uint sm, uint32_t period, char c){
    uint32_t clk = 125000;
    set_sys_clock_khz(clk, true);
    switch (c) {
        case '1':
//            printf("Entering A mode\n");
            pio_sm_set_clkdiv(pio,sm,(float)8.8125);
            pio_pwm_set_period(pio, sm, 65476);
            pio_pwm_set_level(pio,sm,period/2);
            sleep_ms(100);
            pio_pwm_set_level(pio,sm,0);
            break;
        case '2':
            pio_sm_set_clkdiv(pio,sm,(float)6.5);
            pio_pwm_set_period(pio, sm, 65485);
            pio_pwm_set_level(pio,sm,period/2);
            sleep_ms(100);
            pio_pwm_set_level(pio,sm,0);
            break;
        case '3':
            pio_sm_set_clkdiv(pio,sm,(float)5.8125);
            pio_pwm_set_period(pio, sm, 65239);
            pio_pwm_set_level(pio,sm,period/2);
            sleep_ms(100);
            pio_pwm_set_level(pio,sm,0);
            break;
        case '4':
            pio_sm_set_clkdiv(pio,sm,(float)5.5);
            pio_pwm_set_period(pio, sm, 65077);
            pio_pwm_set_level(pio,sm,period/2);
            sleep_ms(100);
            pio_pwm_set_level(pio,sm,0);
            break;
        case '5':
            pio_sm_set_clkdiv(pio,sm,(float)4.875);
            pio_pwm_set_period(pio, sm, 65409);
            pio_pwm_set_level(pio,sm,period/2);
            sleep_ms(100);
            pio_pwm_set_level(pio,sm,0);
            break;
        case '6':
            pio_sm_set_clkdiv(pio,sm,(float)4.375);
            pio_pwm_set_period(pio, sm, 64934);
            pio_pwm_set_level(pio,sm,period/2);
            sleep_ms(100);
            pio_pwm_set_level(pio,sm,0);
            break;
        case '7':
            pio_sm_set_clkdiv(pio,sm,(float)3.875);
            pio_pwm_set_period(pio, sm, 65314);
            pio_pwm_set_level(pio,sm,period/2);
            sleep_ms(100);
            pio_pwm_set_level(pio,sm,0);
            break;
        default: // including the '\n' and '\0'
            sleep_ms(250);
            break;
    }
}

void free_mode(PIO pio, uint sm){
//    ST7735_Init();

    uint clk_div = 0x04;
    uint32_t period = 64934;

    // Fine-tuning the clock so that the frequency of the music is normal
    uint32_t clk = 125000;
    set_sys_clock_khz(clk, true);


    while(true){

        char c = get_key_timeout_us(4*1000*1000);
        if(c == '#' || c == '0'){
            pio_sm_set_clkdiv(pio,sm,1);
            break;
        }
        if(c == 'm') {
            continue;
        }
        play_a_note(pio, sm, period, c);
    }

}
