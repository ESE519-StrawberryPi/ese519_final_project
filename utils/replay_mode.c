//
// Created by Xuanbiao Zhu on 12/3/22.
//

#include "play.h"
#include "sl_utils.h"
#include "audio_generator.h"

void record_music(int charArrLen){
    // record the music
    printf("Starting recording...\n");
    char *charArr = (char *) malloc(charArrLen * sizeof(char));
    int index = 0;
    while(index < charArrLen - 1){
        char c = getchar_timeout_us(1 * 1000 * 10);
        // if no input, you get PICO_ERROR_TIMEOUT = -1
        if(c == 'q') {
            printf("Quit the record.\n");
            break;
        }else if(c == PICO_ERROR_TIMEOUT){
            charArr[index] = 'b';
        }else{
            charArr[index] = c;
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
    printf("Loading Stored samples.\n");
    char *charArr = (char *) malloc(charArrLen * sizeof(char));
    charArr = load(charArr);
    printf("Load music successfully! \n");
    printf("%s\n",charArr);

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
