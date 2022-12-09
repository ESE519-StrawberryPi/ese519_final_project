//
// Created by Haoze Wu on 12/3/22.
//

#include "sl_utils.h"

const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);

void print_buf(const uint8_t *buf, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%c", buf[i]);
        if (i % 16 == 15)
            printf("\n");
        else
            printf(" ");
    }
}

// save the PWM data array to the flash memory
bool save(char *charArr){

    // Plus 1 here is to take the terminator into account.
    size_t len = strlen(charArr) + 1;
    // printf("Len: %d\n", len);
    char* temp= (char *) malloc(len * sizeof(char));
    strcpy(temp, charArr);
    temp[len] = '\0';
//    printf("Copied Array:\n");
//    printf("%s\n",temp);

    // Transfer the length of data into
    // the integer multiple of the size of the sector.
    size_t SPACE_SIZE = ((len / FLASH_SECTOR_SIZE) + 1 ) * FLASH_SECTOR_SIZE;
    // size_t SPACE_SIZE=len;

//    printf("spaceSize: %d\n", SPACE_SIZE);

    temp=(char*) realloc(temp, 1400);

//    printf("realloc successfully.\n");


    print_buf(temp, len);
    // Erase the flash memory.
    // Before erasing, disable the interrupts and save the breakpoint.
    // Recover the breakpoint and enable the interrupts after erasing.
    uint32_t ints = save_and_disable_interrupts();
    flash_range_erase(FLASH_TARGET_OFFSET, SPACE_SIZE);
    restore_interrupts(ints);

    printf("\nErase successfully.\n");

    // Write the data char array into the flash memory.
    // Similar to erase.
    ints = save_and_disable_interrupts();
    flash_range_program(FLASH_TARGET_OFFSET, (uint8_t*)temp, SPACE_SIZE);
    restore_interrupts(ints);
    printf("Write Successfully.\n");
    print_buf(flash_target_contents, len);

    // Check if stored data is correct
    // return false is mismatch and erase the data written.
    bool mismatch = false;
    for (int i = 0; i < len; i++) {
        if (charArr[i] != flash_target_contents[i])
            mismatch = true;
    }
    if (mismatch){
        printf("Save failed!\n");
        ints = save_and_disable_interrupts();
        flash_range_erase(FLASH_TARGET_OFFSET, SPACE_SIZE);
        restore_interrupts(ints);
        return false;
    }
    else{
        printf("Save successful!\n");
        return true;
    }
}


// load the PWM data array from the flash memory
char* load(char *read_result){

    printf("Read back target region:\n");
    print_buf(flash_target_contents, FLASH_PAGE_SIZE);

    // Possibly by doubles scanning the flash memory.
    // Calculate the length of the data during the first scan.
    // Read the data into memory array during the second scan.
    int index = 0;
    while(flash_target_contents[index] != '\0'){
        index++;
    }
    printf("\nindex: %d\n", index);
    read_result = (char *) malloc(index + 1);
    for(int i = 0; i < index; i++){
        read_result[i] = flash_target_contents[i];
    }
    read_result[index] = '\0';
    print_buf(flash_target_contents,index);
    return read_result;

}