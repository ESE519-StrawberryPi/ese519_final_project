//
// Created by Haoze Wu on 12/9/22.
//

#include "pico/stdlib.h"

#include "zrx543_driver.h"

// Define the Row GPIO PIN
const uint R1 = 20;
const uint R2 = 25;
const uint R3 = 24;
const uint R4 = 26;

// Define the Column GPIO PIN
const uint C1 = 27;
const uint C2 = 28;
const uint C3 = 29;
const uint C4 = 5;

void init_gpio(){

    gpio_init(R1);
    gpio_set_dir(R1,GPIO_OUT);

    gpio_init(C1);
    gpio_set_dir(C1,GPIO_IN);

    gpio_init(C2);
    gpio_set_dir(C2,GPIO_IN);

    gpio_init(C3);
    gpio_set_dir(C3,GPIO_IN);

    gpio_init(C4);
    gpio_set_dir(C4,GPIO_IN);

}

char getKey(){
    sleep_ms(125);
    gpio_put(R1,true);



    if(gpio_get(C1)){
        printf("a");
        return 'a';
    }
    if(gpio_get(C2)){
        printf("s");
        return 's';
    }
    if(gpio_get(C3)){
        printf("d");
        return 'd';
    }
    if(gpio_get(C4)){
        printf("f");
        return 'f';
    }


    return 'm';
}
