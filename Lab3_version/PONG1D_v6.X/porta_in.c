#include "porta_in.h"
void porta_in_init(){
    ANSELA = 0;
    TRISA = 0x3f;
    CNPUA = 0x3f;
    //CNPDA = 0;
    
}


uint8_t porta_in_read(){
    uint8_t input = PORTA;
    return input;
}

