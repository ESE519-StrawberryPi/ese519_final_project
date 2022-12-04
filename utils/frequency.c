//
// Created by Haoze Wu on 12/2/22.
//

#include "../config.h"

void SetPwmFreq(float freq) {
#define TOP_MAX 65534
#define DIV_MAX ((0xFF << 4) + 0xF)
    uint32_t clock = 125000000;
    uint32_t div = 1 << 4;
    uint32_t top = ((clock << 4) / div / freq) - 1;
    while ((top > TOP_MAX) && (div < DIV_MAX)) {
        top = ((clock << 4) / ++div / freq) - 1;
    };
    float out = (float)(clock << 4) / div / (top+1);
    printf("Freq = %f, ",       freq);
    printf("Top = %d, ",        top);
    printf("Div = 0x%02X.%X, ", div >> 4, div & 0xF);
    printf("Out = %f\n",        out);
}

int main(void) {
//    sleep_ms(50000);
    SetPwmFreq(7.75);
}