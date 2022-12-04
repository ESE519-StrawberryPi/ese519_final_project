//
// Created by Xuanbiao Zhu on 12/3/22.
//

#include "play.h"
#include "sl_utils.h"
#include "audio_generator.h"

void record_music(int charArrLen){
    // record the music
    char *charArr = (char *) malloc(charArrLen * sizeof(char));
    int index = 0;
    while(index < charArrLen - 1){
        char c = getchar_timeout_us(4 * 1000 * 1000);
        charArr[index] = c;
        // if no input, you get PICO_ERROR_TIMEOUT = -1
        if(c == PICO_ERROR_TIMEOUT){
            charArr[index] = '\n';
        }
        index++;
    }
    charArr[index] = '\0';
    printf("Record music successfully!\n");
    save(charArr);
    printf("Save music successfully! \n");
}

void load_music(int charArrLen, PIO pio, uint sm, uint32_t period){
    // read the music.
    char *charArr = (char *) malloc(charArrLen * sizeof(char));
    load(charArr);
    printf("Load music successfully! \n");

    // play the recorded music;
    int index = 0;
    while(index < charArrLen - 1) {
        char c = charArr[index];
        // play a note
        if(charArr[index] == '\0') break;

        play_a_note(pio, sm, period, c);
        index++;
    }
    printf("Replay the music successfully!\n");
}
