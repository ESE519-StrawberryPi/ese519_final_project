//
// Created by Xuanbiao Zhu on 12/3/22.
//

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pwm.pio.h"
#include "notes_3.h"
#include "audio.h"
#include "music.h"
#include "hardware/clocks.h"
#include "pwm_pio.c"
#include "record.c"
#include "audio_generator.c"


int main(){

    stdio_init_all();

    printf("Welcome to the music instrument. We have three modes. \n");

    while(true){
        printf("Please enter the mode you want to use: \n");
        printf("Press 'r' to record a song. \n");
        printf("Press 'p' to play a given song. \n");
        printf("Press 'f' to enter free mode. \n");
        printf("Press 'l' to load the recorded song. \n");
        printf("Press 'q' to quit. \n");
        printf("Waiting for the input... \n");
        char c = getchar_timeout_us(4 * 1000 * 1000);
        if(c == 'q'){
            printf("Bye! \n");
            break;
        }

        switch(c){
            case 'r':
                record_music();
                break;
            case 'p':
                play_mode(DATA_MUSIC, DATA_LENGTH_MUSIC);
                break;
            case 'f':
                free_mode();
                break;
            case 'l':
                load_music();
                break;
        }

        printf("\n\n\n\n");
        sleep_ms(1000);

    }



}



