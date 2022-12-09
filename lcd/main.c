#include "DEV_Config.h"
#include "st7735_driver.h"
#include "music_pictures.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ST7735_Init();
    int i = 0;
    while(true){
    if(i==22){
        i=0;
    }
    ST7735_DrawImage(0, 0, 80, 160, dou[i]);
    i++;
    sleep_ms(100);
    }
}
}