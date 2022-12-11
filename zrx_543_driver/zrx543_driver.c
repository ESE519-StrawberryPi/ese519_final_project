//
// Created by Haoze Wu on 12/9/22.
//

#include "pico/stdlib.h"

#include "zrx543_driver.h"

// Define the Row GPIO PIN
const uint R1 = 2;
const uint R2 = 3;
const uint R3 = 4;
const uint R4 = 5;

// Define the Column GPIO PIN
//const uint C0 = 17;
const uint C1 = 18;
const uint C2 = 19;
const uint C3 = 20;
const uint C4 = 21;

const uint PINS[]={R1,R2,R3,R4,C1,C2,C3,C4,};

const char row_1[] = {'1','2','3','A'};
const char row_2[] = {'4','5','6','B'};
const char row_3[] = {'7','8','9','C'};
const char row_4[] = {'*','0','#','D'};

void init_gpio(){


    for(uint gpio=0; gpio<8; gpio++){
        gpio_init(PINS[gpio]);
        gpio_set_dir(PINS[gpio],GPIO_OUT);
        gpio_put(PINS[gpio],false);
    }

//    gpio_init(R1);
    gpio_set_dir(R1,GPIO_OUT);

//    gpio_init(R2);
    gpio_set_dir(R2,GPIO_OUT);

//    gpio_init(R3);
    gpio_set_dir(R3,GPIO_OUT);

//    gpio_init(R4);
    gpio_set_dir(R4,GPIO_OUT);

//    gpio_init(C1);
    gpio_set_dir(C1,GPIO_IN);

//    gpio_init(C2);
    gpio_set_dir(C2,GPIO_IN);

//    gpio_init(C3);
    gpio_set_dir(C3,GPIO_IN);

//    gpio_init(C4);
    gpio_set_dir(C4,GPIO_IN);

}

char get_row_key(const char* row_data){
    if(gpio_get(C1)){
        return row_data[0];
    }
    if(gpio_get(C1)){
        return row_data[0];
    }
    if(gpio_get(C2)){
        return row_data[1];
    }
    if(gpio_get(C3)){
        return row_data[2];
    }
    if(gpio_get(C4)){
        return row_data[3];
    }

    return 'm';
}

char getKey(){
//    printf("====================\n");
    char result ;

//    printf("ROW1\n");
    gpio_put(R1,true);
    result = get_row_key(row_1);
    gpio_put(R1,false);
    if(result != 'm') return result;

//    printf("ROW2\n");
    gpio_put(R2,true);
    result = get_row_key(row_2);
    gpio_put(R2,false);
    if(result != 'm') return result;

//    printf("ROW3\n");
    gpio_put(R3,true);
    result = get_row_key(row_3);
    gpio_put(R3,false);
    if(result != 'm') return result;

//    printf("ROW4\n");
    gpio_put(R4,true);
    result = get_row_key(row_4);
    gpio_put(R4,false);
    if(result != 'm') return result;

    return 'm';

}
