/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        This B. You
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "lib.h"

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

uint ledCount = 0;
uint lastPressed = 0b00000000;

/********************************************************************/
// Constants
/********************************************************************/

const uint tier = 1;

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
  SWL_Init();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {

    if(tier == 0){
      if(SWL_Pushed(SWL_LEFT)){
        SWL_ON(SWL_RED);
      }else{
        SWL_OFF(SWL_RED);
      }
    }

    if(tier == 1){
      if(SWL_Pushed(SWL_LEFT)){
        SWL_ON(SWL_RED);
      }else{
        SWL_OFF(SWL_RED);
      }

      if(SWL_Pushed(SWL_CTR)){
        SWL_ON(SWL_YELLOW);
      }else{
        SWL_OFF(SWL_YELLOW);
      }

      if(SWL_Pushed(SWL_RIGHT)){
        SWL_ON(SWL_GREEN);
      }else{
        SWL_OFF(SWL_GREEN);
      }
    }

    if(tier == 2){
      
    }
    
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
