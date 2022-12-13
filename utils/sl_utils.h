//
// Created by Haoze Wu on 12/3/22.
//

#include "../config.h"

#ifndef FINAL_PROJECT_SL_UTILS_H
#define FINAL_PROJECT_SL_UTILS_H

#define FLASH_TARGET_OFFSET (256 * 1024)

/// Helper function to print an array with given length
/// \param buf Pointer to the array to be printed
/// \param len Length of the array
void print_buf(const uint8_t *buf, size_t len);

/// Save the data array to the flash memory
/// \param charArr Char array to be saved
/// \return Result of saving. True if successful, false otherwise.
bool save(char *charArr);

/// Load the data array from the flash memory
/// \param read_result Pointer a dynamic array to store the loaded data
/// \return Pointer to the loaded data array
char* load(char *read_result);

/// Override the get_char_timeout_ms function in pico/stdio.h, to receive a key from keypad within a given time.
/// \param timeout_us Timeout in microseconds
/// \return The key received from the keypad
int get_key_timeout_us(uint32_t timeout_us);

#endif //FINAL_PROJECT_SL_UTILS_H
