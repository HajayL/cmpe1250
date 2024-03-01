/********************************************************************/
// HC12 Program:  PLL Timing
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Hajay J. Lawson
// Details:       Flickers a red LED based on the PLL clock speed           
// Date:          1/3/24
/********************************************************************/


/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "mainLib.h"
#include "clock.h"

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
int uCount = 0; // Outter loop
int count = 0;  // Inner loop

/********************************************************************/
// Constants
/********************************************************************/

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
  SWL_Init(); // Enable LEDS
  //Clock_Set20MHZ();
  Clock_Set24MHZ();
  //Clock_Set40MHZ();
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    SWL_TOG(SWL_RED); // Toggle red led
    for(uCount = 0; uCount < 100; uCount++){
      for(count = 0; count < 4000/3; count++){
        // 1ms * 100 (100ms) for 8MHz speed
      }
    }
    
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
