#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pwm.pio.h"
#include "audio.h"
#include "hardware/clocks.h"

#include "notes_1.h"
#include "notes_2.h"
#include "notes_3.h"


struct PWMArr {
    uint32_t *data;
    uint32_t length;
};




//  Params: length of notes
//  Return: the pointer to the PWM data array.
struct PWMArr* record(int length){

    // record the note
    char *note = (char *) malloc(length * sizeof(char));
    printf("Please enter the note: ");
    
    int idx = 0;
    while(idx < length){
        note[idx] = getchar_timeout_us(4 * 1000 * 1000);
        idx++;
    }

    // map to the PWM data array
    PWMArr *pwmArr;
    pwmArr->length = 0;
    pwmArr->data = NULL;

    noteToPWM(note, length, pwmArr);

    // return the PWM data array, you also need the length of the array
    return pwmArr;
}

//  Params: the note, the length of the note, the pointer to the PWM data array.
//  Return: NULL
struct Map {
    char key;
    struct Value {
        uint8_t *data;
        uint32_t length;
    } value;
}
// set up the map
struct Map map[3];
map[0].key = 'a';
map[0].value.data = DATA_1;
map[0].value.length = DATA_LENGTH_1;
map[1].key = 's';
map[1].value.data = DATA_2;
map[1].value.length = DATA_LENGTH_2;
map[2].key = 'd';
map[2].value.data = DATA_3;
map[2].value.length = DATA_LENGTH_3;

void noteToPWM(char *note, int noteLength, struct PWMArr *pwmArr){
    
    for(int i = 0; i < noteLength; i++){

    }

}

// save the PWM data array to the flash memory
void save(struct PWMArr *pwmArr){

}


// load the PWM data array from the flash memory
struct PWMArr* load(){

}

