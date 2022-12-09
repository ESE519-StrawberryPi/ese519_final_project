//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#include "pico/stdlib.h"
//#include "hardware/pio.h"
//#include "pwm.pio.h"
//#include "resources/audio.h"
//#include "hardware/clocks.h"
//#include "hardware/flash.h"
//#include "hardware/sync.h"
//
//#include "resources/notes_1.h"
//#include "resources/notes_2.h"
//#include "resources/notes_3.h"
//
//// We're going to erase and reprogram a region 256k from the start of flash.
//// Once done, we can access this at XIP_BASE + 256k.
////#define FLASH_TARGET_OFFSET (256 * 1024)
////
////const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);
//// struct PWMArr {
////     uint32_t *data;
////     uint32_t length;
//// };
//
//
//
//
//// //  Params: length of notes
//// //  Return: the pointer to the PWM data array.
//// struct PWMArr* record(int length){
//
////     // record the note
////     char *note = (char *) malloc(length * sizeof(char));
////     printf("Please enter the note: ");
//
////     int idx = 0;
////     while(idx < length){
////         note[idx] = getchar_timeout_us(4 * 1000 * 1000);
////         idx++;
////     }
//
////     // map to the PWM data array
////     PWMArr *pwmArr;
////     pwmArr->length = 0;
////     pwmArr->data = NULL;
//
////     noteToPWM(note, length, pwmArr);
//
////     // return the PWM data array, you also need the length of the array
////     return pwmArr;
//// }
//
//// //  Params: the note, the length of the note, the pointer to the PWM data array.
//// //  Return: NULL
//// struct Map {
////     char key;
////     struct Value {
////         uint8_t *data;
////         uint32_t length;
////     } value;
//// }
//// // set up the map
//// const mapLen = 3;
//// struct Map map[mapLen];
//// map[0].key = 'a';
//// map[0].value.data = DATA_1;
//// map[0].value.length = DATA_LENGTH_1;
//// map[1].key = 's';
//// map[1].value.data = DATA_2;
//// map[1].value.length = DATA_LENGTH_2;
//// map[2].key = 'd';
//// map[2].value.data = DATA_3;
//// map[2].value.length = DATA_LENGTH_3;
//
//// void noteToPWM(char *note, int noteLength, struct PWMArr *pwmArr, struct Map *map){
////     int idx = 0;
////     int maxLen = noteLength * 26000;
////     pwmArr->length = maxLen;
////     uint8_t newArr[maxLen];
////     for(int i = 0; i < noteLength; i++){
////         int curKey = note[i];
////         int curLen;
////         uint8_t *curData;
////         // get curKey and curLen
////         for(int j = 0; j < mapLen; j++){
////             if(map[j].key == note[i]){
////                 curLen = map[j].value.length;
////                 curData = map[j].value.data;
////             }
////         }
//
////         // Fill data in the pwmArr.
////         for(int j = 0; j < curLen; j++){
////             newArr[idx] = curData[j];
////         }
//
//
////     }
//
//// }
//void print_buf(const uint8_t *buf, size_t len) {
//    for (size_t i = 0; i < len; ++i) {
//        printf("%c", buf[i]);
//        if (i % 16 == 15)
//            printf("\n");
//        else
//            printf(" ");
//    }
//}
//
//// save the PWM data array to the flash memory
//bool save(char *charArr){
//
//    // Plus 1 here is to take the terminator into account.
//    size_t len = strlen(charArr) + 1;
//    // printf("Len: %d\n", len);
//    char* temp= (char *) malloc(len * sizeof(char));
//    strcpy(temp, charArr);
//    temp[len] = '\0';
//    printf("Copied Array:\n");
//    printf("%s\n",temp);
//
//    // Transfer the length of data into
//    // the integer multiple of the size of the sector.
//    size_t SPACE_SIZE = ((len / FLASH_SECTOR_SIZE) + 1 ) * FLASH_SECTOR_SIZE;
//    // size_t SPACE_SIZE=len;
//
//    printf("spaceSize: %d\n", SPACE_SIZE);
//
//    temp=(char*) realloc(temp, 1400);
//
//    printf("realloc successfully.\n");
//
//
//    print_buf(temp, len);
//    // Erase the flash memory.
//    // Before erasing, disable the interrupts and save the breakpoint.
//    // Recover the breakpoint and enable the interrupts after erasing.
//    uint32_t ints = save_and_disable_interrupts();
//    flash_range_erase(FLASH_TARGET_OFFSET, SPACE_SIZE);
//    restore_interrupts(ints);
//
//    printf("\nErase successfully.\n");
//
//    // print_buf(flash_target_contents, SPACE_SIZE);
//
//    // printf("\nData printed.\n");
//
//    // Write the data char array into the flash memory.
//    // Similar to erase.
//    ints = save_and_disable_interrupts();
//    flash_range_program(FLASH_TARGET_OFFSET, (uint8_t*)temp, SPACE_SIZE);
//    restore_interrupts(ints);
//    printf("Write Successfully.\n");
//    print_buf(flash_target_contents, len);
//
//    // Check if stored data is correct
//    // return false is mismatch and erase the data written.
//    bool mismatch = false;
//    for (int i = 0; i < len; i++) {
//        if (charArr[i] != flash_target_contents[i])
//            mismatch = true;
//    }
//    if (mismatch){
//        printf("Save failed!\n");
//        ints = save_and_disable_interrupts();
//        flash_range_erase(FLASH_TARGET_OFFSET, SPACE_SIZE);
//        restore_interrupts(ints);
//        return false;
//    }
//    else{
//        printf("Save successful!\n");
//        return true;
//    }
//}
//
//
//// load the PWM data array from the flash memory
//char* load(char *read_result){
//
//    printf("Read back target region:\n");
//    print_buf(flash_target_contents, FLASH_PAGE_SIZE);
//
//    // Possibly by doubles scanning the flash memory.
//    // Calculate the length of the data during the first scan.
//    // Read the data into memory array during the second scan.
//    int index = 0;
//    while(flash_target_contents[index] != '\0'){
//        index++;
//    }
//    printf("\nindex: %d\n", index);
//    read_result = (char *) malloc(index + 1);
//    for(int i = 0; i < index; i++){
//        read_result[i] = flash_target_contents[i];
//    }
//    read_result[index] = '\0';
//    return read_result;
//
//}
//
////int main(){
////
////    stdio_init_all();
////
////    sleep_ms(10000);
////    printf("Hello, world!\n");
////
////    char *charArr;
////    charArr=load(charArr);
////
////    printf("%s\n", charArr);
////    printf("Relaod Successfully.\n");
////
////    char test_arr[]= {'b','a','b','c','a','a','b','c','a','a','b','c','\0'};
////
////    // size_t test_arr_length=sizeof(test_arr)/sizeof(test_arr[0]);
////    // char *char_p=malloc(test_arr_length);
////    // int i=0;
////    // strcpy(char_p,test_arr);
////
////    // printf("%s\n", char_p);
////    // printf("%d\n", strlen(char_p));
////    bool result = save(test_arr);
////
////    // printf("%d\n", result);
////    charArr=load(charArr);
////
////    printf("%s\n", charArr);
////    printf("Relaod Successfully.\n");
////}
//
