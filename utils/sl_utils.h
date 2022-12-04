//
// Created by Haoze Wu on 12/3/22.
//

#include "../config.h"

#ifndef FINAL_PROJECT_SL_UTILS_H
#define FINAL_PROJECT_SL_UTILS_H

#define FLASH_TARGET_OFFSET (256 * 1024)

const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);

void print_buf(const uint8_t *buf, size_t len);

bool save(char *charArr);

char* load(char *read_result);

#endif //FINAL_PROJECT_SL_UTILS_H
