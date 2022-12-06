
#include "DEV_Config.h"
#include "st7735_driver.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ST7735_Init();
    while(true){
    ST7735_DrawImage(0, 0, 80, 160, arducam_logo);
    sleep_ms(1000);
    }
}