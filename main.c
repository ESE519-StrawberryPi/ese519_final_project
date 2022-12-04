//
// Created by Xuanbiao Zhu on 12/3/22.
//

//#include "config.h"

//#include "utils/sl_utils.h"
//#include "utils/pwm_utils.h"
#include "utils/play.h"
#include "utils/audio_generator.h"
#include "utils/sl_utils.h"

#include "resources/audio.h"

//void record_music(){
//    ;
//}
//
//void load_music(){
//    ;
//}

int main(){
    stdio_init_all();

    // Set up PIO
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pwm_program);
    printf("Loaded program at %d\n", offset);
    pwm_program_init(pio, sm, offset,AUDIO_PIN);


    //
    uint32_t period = 64934;
    int recordedCharLen = 10;



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
        if(c == 'q'){
            printf("Bye! \n");
            break;
        }

        switch(c){
            case 'r':
                //TODO: Finalize teh record function
                record_music(recordedCharLen);
                break;
            case 'p':
                set_sys_clock_khz(66000, true);
                play_mode(pio, sm,DATA_AUDIO, DATA_LENGTH_AUDIO);
                break;
            case 'f':
                free_mode(pio, sm);
                break;
            case 'l':
                load_music(recordedCharLen, pio, sm, period);
                break;
        }

//        printf("\n\n\n\n");
        sleep_ms(1000);

    }





}



