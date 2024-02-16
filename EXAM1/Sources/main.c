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

ulong wait = 0;
uint count = 0;
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
  SWL_Init();
  // SWL_ON(SWL_ALL);

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
    
    /*
      By using a toggle loop with a delay that has a test number, you can get the the ms of the cycle. By dividing this in half and seting up a ratio with another number
      you can get the ratio of time to loop cycles and compare them by checking if the results of the sides equal to each other.

      Once this is verfied, it proves that the numbers are related and the resulting number is the difference in relation.

      after getting this number, multiplying it to the time wanted (a result of manipulating the ratio) will give you the amount of cycle loops needed to get that target time * 2

      I used the test numbers 2000 & 3000
      and got 16ms and 24ms respectively 

      I then set up the ratio

      2000     3000
      ----  =  ----
      16ms     24ms

      and ended with

      125k = 125k - The difference of the relation * 2

      I then did

      125k / 2 * 5ms
      and
      125k / 2 * 15ms

      to get the length of delay

      625 / 2
      and
      3750 / 2

      This number did not result in the desired value and was off from the needed value so I tweaked the number slowly to get closer to the desired value
    
    */

    SWL_OFF(SWL_RED);

    wait = 0;

    while(wait++ < 974/2){

    }

    SWL_ON(SWL_RED);

    wait = 0;

    while(wait++ < 2926/2){

    }

    // --------------------------- Part B

    count = 0;

    if(SWL_Pushed(SWL_UP))  count++;
    if(SWL_Pushed(SWL_RIGHT))  count++;
    if(SWL_Pushed(SWL_DOWN))  count++;
    if(SWL_Pushed(SWL_LEFT))  count++;
    if(SWL_Pushed(SWL_CTR))  count++;

    if (count == 2)
    {
      SWL_ON(SWL_YELLOW);
      SWL_OFF(SWL_GREEN);
    }else{
      SWL_ON(SWL_GREEN);
      SWL_OFF(SWL_YELLOW);
    }
    

  }
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
