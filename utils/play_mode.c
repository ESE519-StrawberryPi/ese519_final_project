//
// Created by Haoze Wu on 12/3/22.
//

#include "play.h"
#include "sl_utils.h"

// play the given music data
void play_mode(PIO pio, uint sm, uint8_t *data, int dataLen){
    // uint cycles=clock_get_hz(clk_sys)/(freq*clk_div);
    // uint clk_div = 8;
    uint32_t period = 250;

    // Fine-tune the clock so that the frequency of the music is normal.
    uint32_t clk = 66000;
    set_sys_clock_khz(clk, true);
    pio_sm_set_clkdiv(pio,sm,1);

    // Set up the pio
//    uint offset = pio_add_program(pio, &pwm_program);
//    printf("\nLoaded program at %d", offset);
//
//    pwm_program_init(pio, sm, offset, AUDIO_PIN);
    pio_pwm_set_period(pio, sm, period);

    printf("\n If you want to exit the loop, please press '#'.\n");
    int position = 0;
    while (true) {


        // if (position < (DATA_LENGTH << 3) - 1){
        if ( position < (dataLen << 2)-1){
            pio_pwm_set_level(pio0, sm, data[position>>2]);
            position++;
        }else{
            position = 0;
            char c = get_key_timeout_us(1*1000*1500);
            printf("%c",c);
            if (c=='#'){
                return;
            }
            pio_pwm_set_level(pio0,sm, 0);
            printf("\nReset the position");
            printf("\nRestart again");
        }
    }
}
