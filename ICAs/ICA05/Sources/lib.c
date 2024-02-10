#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "lib.h"

void SWL_Init(){
    DDR1AD1 = SWL_ALL;
    PT1AD1 = 0b00000000;
    ATD1DIEN1 = 0b00011111;
}

void SWL_ON(SWL_LEDColour led){
    PT1AD1 |= led;
}

void SWL_OFF(SWL_LEDColour led){
    PT1AD1 &= ~led;
}

void SWL_TOG(SWL_LEDColour led){
    PT1AD1 ^= led;
}

int SWL_Pushed(SWL_SwitchPos pos){
    return (PT1AD1 & pos) > 0;
}