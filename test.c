//
// Created by Haoze Wu on 12/10/22.
//

#include "utils/play.h"
#include "utils/audio_generator.h"
#include "zrx_543_driver/zrx543_driver.h"


#include "resources/audio.h"

int main(){
    stdio_init_all();
//    init_gpio();
//    uint gpio=0;
    sleep_ms(10000);
    init_gpio();
    while(true){
        sleep_ms(100);

        printf("%c\n", getKey());
//        printf("%d\n", gpio_get(gpio));
//        gpio++;
    }

}