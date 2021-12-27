/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*** INCLUDED COMPONENTS ***/
#include "chronometer.h"

/*** VARIABLES ***/
uint16 ms = 0;

/*** FUNCTIONS ***/

/*** INTERRUPTS ***/
CY_ISR(msCounter){
    ms++;                       // miliseconds counter
    if (ms == 60000) ms = 0;
}

/* [] END OF FILE */
