/********************************************************************/
// HC12 Program:  PLL Timing header
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Hajay J. Lawson
// Details:       Allows change of PLL speed to 20MHz, 24Mhz, and 40MHz          
// Date:          1/3/24
/********************************************************************/

#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "clock.h"

int BUS_SPEED = 0;

void Clock_EnableOutput(ClockOutDiv div)
{
    
}

void Clock_Set8MHZ(void)
{
    // PLL division
    SYNR = 0;
    REFDV = 1;

    // Seudo stop osc
    CLKSEL_PSTP = 1;

    // Enable PLL
    PLLCTL = 0b11111111;

    // Wait until PLL locks
    while (!CRGFLG_LOCK);

    // Use PLL for bus speed
    CLKSEL_PLLSEL = 1;
}

void Clock_Set20MHZ(void)
{
    // PLL division
    SYNR = 4;
    REFDV = 3;

    // Seudo stop osc
    CLKSEL_PSTP = 1;

    // Enable PLL
    PLLCTL = 0b11111111;

    // Wait until PLL locks
    while (!CRGFLG_LOCK);

    // Use PLL for bus speed
    CLKSEL_PLLSEL = 1;
}

void Clock_Set24MHZ(void)
{
    // PLL division
    SYNR = 2;
    REFDV = 1;

    // Seudo stop osc
    CLKSEL_PSTP = 1;

    // Enable PLL
    PLLCTL = 0b11111111;

    // Wait until PLL locks
    while (!CRGFLG_LOCK);

    // Use PLL for bus speed
    CLKSEL_PLLSEL = 1;
}

void Clock_Set40MHZ(void)
{
    // PLL division
    SYNR = 4;
    REFDV = 1;

    // Seudo stop osc
    CLKSEL_PSTP = 1;

    // Enable PLL
    PLLCTL = 0b11111111;

    // Wait until PLL locks
    while (!CRGFLG_LOCK);

    // Use PLL for bus speed
    CLKSEL_PLLSEL = 1;
}

unsigned long Clock_GetBusSpeed(void)
{
    // Calculate bus speed
    BUS_SPEED = 8 * ((SYNR + 1) / (REFDV + 1));
}