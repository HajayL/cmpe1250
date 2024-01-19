/********************************************************************/
// HC12 Program:  Alternating Lights - Switches between red and green
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Hajay J. Lawson
// Details:       Swtiches between red and green depending on the loop count               
// Date:          19/1/24 (DD/MM/YY)
// Revision History : None



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>

/********************************************************************/
// Global Variables
/********************************************************************/

static uint uiMainLoopCount = 0;

/********************************************************************/
// Functions
/********************************************************************/

void RED(){
  if(uiMainLoopCount < 0x1000){ // Runs if under the hex value 0x1000
    PT1AD1 |= 1 << 7; // Shifts memory value by 7
  }else{
    PT1AD1 &= 0x7F;   // Ands with hex if the loopCount is above value
  }
}

void GREEN(){
if(uiMainLoopCount >= 0x1000){ // Runs if above value
    PT1AD1 |= 0x20;       // Ors the current value memory values with 0x20
  }else{
    PT1AD1 &= 0b11011111; // Ands current memory value with the binary value 0b11011111
  }
}

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
    
  /********************************************************************/
    // one-time initializations
  /********************************************************************/

  PT1AD1 &= 0x1F; // Ands the current memory value with 0x1F
  DDR1AD1 = 0xE0; // Sets The RAM memory position to 0xE0

  /********************************************************************/
    // main program loop
  /********************************************************************/

  for (;;)
  {
    ++uiMainLoopCount;  // Increments loop count
    RED();              // Runs the Red method
    GREEN();            // Runs the GREEN method
  }                   
}