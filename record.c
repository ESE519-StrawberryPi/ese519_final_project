#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pwm.pio.h"
#include "audio.h"
#include "hardware/clocks.h"
#include "hardware/flash.h"
#include "hardware/sync.h"

#include "notes_1.h"
#include "notes_2.h"
#include "notes_3.h"
 
// We're going to erase and reprogram a region 256k from the start of flash.
// Once done, we can access this at XIP_BASE + 256k.
#define FLASH_TARGET_OFFSET (256 * 1024)

const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);

// struct PWMArr {
//     uint32_t *data;
//     uint32_t length;
// };




// //  Params: length of notes
// //  Return: the pointer to the PWM data array.
// struct PWMArr* record(int length){

//     // record the note
//     char *note = (char *) malloc(length * sizeof(char));
//     printf("Please enter the note: ");
    
//     int idx = 0;
//     while(idx < length){
//         note[idx] = getchar_timeout_us(4 * 1000 * 1000);
//         idx++;
//     }

//     // map to the PWM data array
//     PWMArr *pwmArr;
//     pwmArr->length = 0;
//     pwmArr->data = NULL;

//     noteToPWM(note, length, pwmArr);

//     // return the PWM data array, you also need the length of the array
//     return pwmArr;
// }

// //  Params: the note, the length of the note, the pointer to the PWM data array.
// //  Return: NULL
// struct Map {
//     char key;
//     struct Value {
//         uint8_t *data;
//         uint32_t length;
//     } value;
// }
// // set up the map
// const mapLen = 3;
// struct Map map[mapLen];
// map[0].key = 'a';
// map[0].value.data = DATA_1;
// map[0].value.length = DATA_LENGTH_1;
// map[1].key = 's';
// map[1].value.data = DATA_2;
// map[1].value.length = DATA_LENGTH_2;
// map[2].key = 'd';
// map[2].value.data = DATA_3;
// map[2].value.length = DATA_LENGTH_3;

// void noteToPWM(char *note, int noteLength, struct PWMArr *pwmArr, struct Map *map){
//     int idx = 0;
//     int maxLen = noteLength * 26000;
//     pwmArr->length = maxLen;
//     uint8_t newArr[maxLen];
//     for(int i = 0; i < noteLength; i++){
//         int curKey = note[i];
//         int curLen;
//         uint8_t *curData; 
//         // get curKey and curLen         
//         for(int j = 0; j < mapLen; j++){
//             if(map[j].key == note[i]){
//                 curLen = map[j].value.length;
//                 curData = map[j].value.data;
//             }
//         }
        
//         // Fill data in the pwmArr. 
//         for(int j = 0; j < curLen; j++){
//             newArr[idx] = curData[j];
//         }


//     }

// }

// save the PWM data array to the flash memory
void save(char *charArr){
    // Note that a whole number of sectors must be erased at a time.
    printf("\nErasing target region...\n");
    uint32_t ints = save_and_disable_interrupts();
    flash_range_erase(FLASH_TARGET_OFFSET, FLASH_SECTOR_SIZE);
    restore_interrupts(ints);
    printf("Done. Read back target region:\n");
    print_buf(flash_target_contents, FLASH_PAGE_SIZE);
 
    printf("\nProgramming target region...\n");
    ints = save_and_disable_interrupts();
    flash_range_program(FLASH_TARGET_OFFSET, charArr, FLASH_PAGE_SIZE);
    restore_interrupts(ints);
    printf("Done. Read back target region:\n");
    print_buf(flash_target_contents, FLASH_PAGE_SIZE);
}


// load the PWM data array from the flash memory
struct PWMArr* load(){

}

