//
// Created by Xuanbiao Zhu on 12/3/22.
//

//#include "config.h"

//#include "utils/sl_utils.h"
//#include "utils/pwm_utils.h"
#include "utils/play.h"
#include "utils/audio_generator.h"
#include "zrx_543_driver/zrx543_driver.h"


#include "resources/audio.h"

/*
 * TODO:
 * TODO 1. Update the recording function to adapt the new keypad.
 *         Sampling it under the sleep_ms function to obtain a certain sample rate.
 * TODO 2. Update the LCD function with judgement function. Judge the pressing timing
 *         in a specific timer period deciding by the position of the dropping blocks.
 * TODO 3. Complete the ZRX543 driver.
 * TODO 4. Complete the gaming display setting.
 * TODO 5. Merge all changes and reformat the structure.
 *
 */

int main(){
    stdio_init_all();
    init_gpio();

    // Set up PIO
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pwm_program);
    printf("Loaded program at %d\n", offset);
    pwm_program_init(pio, sm, offset,AUDIO_PIN);


    //
    uint32_t period = 64934;
    int recordedCharLen = 1000;



    printf("Welcome to the music instrument. We have three modes. \n");

    while(true){
        printf("Please enter the mode you want to use: \n");
        printf("Press 'r' to record a song. \n"); // Partially Done. Complete saving and loading. Sampling on going.
        printf("Press 'p' to play a given song. \n"); // Done
        printf("Press 'f' to enter free mode. \n"); //Done
        printf("Press 'l' to load the recorded song. \n"); // Partially done. Complete loading, playing loaded music on going.
        printf("Press 'q' to quit. \n");
        printf("Waiting for the input... \n");
        char c = getchar_timeout_us(4 * 1000 * 1000);
        char v;
        if(c == 'q'){
            printf("Bye! \n");
            break;
        }

        switch(c){
            case 'r':
                record_music(recordedCharLen);
                break;
            case 'p':
                set_sys_clock_khz(66000, true);
                play_mode(pio, sm,DATA_AUDIO, DATA_LENGTH_AUDIO);
                break;
            case 'f':
                free_mode(pio, sm);
//                   while(true){
//                       v = getKey();
//                       printf("%c\n",v);
//                   }

                break;
            case 'l':
                load_music(recordedCharLen, pio, sm, period);
                break;
        }

//        printf("\n\n\n\n");
        sleep_ms(1000);

    }





}



