#include "reading_interpreter.h"

enum in reading_interpreter(uint16_t x, uint16_t y){ 
    enum in input = IDLE; 
    char value = ' ';
    uint16_t r=4;
    uint16_t c=4;
    int i,j;
    //divide row and column into 4 x 4
    for(j=0; j<r; j++){
        for(i=0; i<c; i++){
            if(x >= btn[i][j].x && x <= (btn[i][j].x+btn[i][j].width)){
                if(y >= btn[i][j].y && y <= (btn[i][j].y+btn[i][j].height)){
                    value = btn[i][j].value;
              
                    switch(value){
                        default:
                            input = IDLE;
                            return input;
                            break;
                        case '7':
                            input = SEVEN;
                            return input;
                            break;
                        case '8':
                            input = EIGHT;
                            return input;
                            break;
                        case '9':
                            input = NINE;
                            return input;
                            break;
                        case '+':
                            input = PLUS;
                            return input;
                            break;

                        case '4':
                            input = FOUR;
                            return input;
                            break;
                        case '5':
                            input = FIVE;
                            return input;
                            break;
                        case '6':
                            input = SIX;
                            return input;
                            break;
                        case '-':
                            input = MINUS;
                            return input;
                            break;

                        case '1':
                            input = ONE;
                            return input;
                            break;
                        case '2':
                            input = TWO;
                            return input;
                            break;
                        case '3':
                            input = THREE;
                            return input;
                            break;
                        case 'x':
                            input = MULT;
                            return input;
                            break;

                        case '0':
                            input = ZERO;
                            return input;
                            break;
                        case 'C':
                            input = CLR;
                            return input;
                            break;
                        case '=':
                            input = EQU;
                            return input;
                            break;
                        case '/':
                            input = DIV;
                            return input;
                            break;
                    }
                }
            }
        }
    }

    return input;
}
