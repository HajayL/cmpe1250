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

unsigned int lastPressed = 0b00000000;

/********************************************************************/
// Constants
/********************************************************************/

const uint tier = 2;

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
  unsigned int onLEDs = 2;

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
      }

      if(SWL_Pushed(SWL_CTR)){
        SWL_ON(SWL_YELLOW);
      }

      if(SWL_Pushed(SWL_RIGHT)){
        SWL_ON(SWL_GREEN);
      }

      if(SWL_Pushed(SWL_UP) || SWL_Pushed(SWL_DOWN)){
        SWL_OFF(SWL_ALL);
      }
    }

    if(tier == 2){
      if(SWL_Pushed(SWL_LEFT) && (lastPressed && SWL_LEFT) <= 0){
        if((PT1AD1 && SWL_RED) <= 0 && onLEDs < 2){
          SWL_TOG(SWL_RED);
          onLEDs += 1;
        } else if((PT1AD1 && SWL_RED) > 0){
          SWL_TOG(SWL_RED);
          onLEDs -= 1;
        }
        
        lastPressed += SWL_LEFT;
      }

      if(!SWL_Pushed(SWL_LEFT) && (lastPressed && SWL_LEFT) > 0){
        lastPressed -= SWL_LEFT;
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
