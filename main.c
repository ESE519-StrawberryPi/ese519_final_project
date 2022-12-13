//
// Created by Xuanbiao Zhu on 12/3/22.
//

#include "utils/play.h"
#include "utils/audio_generator.h"
#include "utils/sl_utils.h"
#include "utils/game_mode.h"
#include "zrx_543_driver/zrx543_driver.h"

#include "resources/audio.h"


int main(){
    stdio_init_all();
    sleep_ms(5000);

    // Set up PIO
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pwm_program);
    pwm_program_init(pio, sm, offset,AUDIO_PIN);

    uint32_t period = 64934;
    int recordedCharLen = 1000;

    int x=5;
    int y=40;

    printf("Welcome to the music instrument. We have three modes. \n");

    char c ;
    int wait_time[]={0,10000};
    int wait_time_index=0;
    while(true){
        ST7735_Init();
        init_gpio();

        ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
        ST7735_WriteString(x,y,"Welcome ", Font_7x10,
                           ST7735_BLACK,ST7735_GREEN);
        ST7735_WriteString(x,y+10,"A Record", Font_7x10,
                           ST7735_BLACK,ST7735_GREEN);
        ST7735_WriteString(x,y+20,"B Music ", Font_7x10,
                           ST7735_BLACK,ST7735_GREEN);
        ST7735_WriteString(x,y+30,"C Free  ", Font_7x10,
                           ST7735_BLACK,ST7735_GREEN);
        ST7735_WriteString(x,y+40,"D Load  ", Font_7x10,
                           ST7735_BLACK,ST7735_GREEN);
        ST7735_WriteString(x,y+50,"* Game  ", Font_7x10,
                           ST7735_BLACK,ST7735_GREEN);
        ST7735_WriteString(x,y+60,"# Quit  ", Font_7x10,
                           ST7735_BLACK,ST7735_GREEN);

        c = get_key_timeout_us(wait_time[wait_time_index%2] * 1000*1000);

        if(c == '#' || c == '0'){
            ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
            ST7735_WriteString(x,y,"Bye ", Font_16x26,ST7735_BLACK,ST7735_GREEN);
            sleep_ms(2000);
            ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
            break;
        }

        switch(c){
            case 'A':
                ST7735_FillRectangle(0,0,80,160,ST7735_BLACK);
                ST7735_WriteString(5,40,"Recording", Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 10,"Press #  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 20,"to end  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                record_music(recordedCharLen,pio,sm);
                break;

            case 'B':
                ST7735_FillRectangle(0,0,80,160,ST7735_BLACK);
                ST7735_WriteString(5,40,"Playing...", Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 10,"Press #  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 20,"to quit  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                set_sys_clock_khz(66000, true);
                play_mode(pio, sm,DATA_AUDIO, DATA_LENGTH_AUDIO);
                break;

            case 'C':
                ST7735_FillRectangle(0,0,80,160,ST7735_BLACK);
                // uint cycles=clock_get_hz(clk_sys)/(freq*clk_div);
                ST7735_WriteString(5,40,"Free Play",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 10,"Press #  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 20,"to quit  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                free_mode(pio, sm);
                ST7735_FillRectangle(0,0,80,160,ST7735_BLACK);
                printf("Exited free mode. \n");
                break;

            case 'D':
                ST7735_FillRectangle(0,0,80,160,ST7735_BLACK);
                ST7735_WriteString(5,40,"Replay...", Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 10,"Press #  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                ST7735_WriteString(5,40 + 20,"to end  ",Font_7x10,
                                   ST7735_BLACK,ST7735_GREEN);
                load_music(recordedCharLen, pio, sm, period);
                break;

            case '*':
                printf("\nWelcome To Games!\n");
                game_mode_test();
                multicore_reset_core1();
                break;

        }
        wait_time_index++;
    }
}



