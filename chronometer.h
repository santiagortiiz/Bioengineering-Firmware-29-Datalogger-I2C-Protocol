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

#ifndef CHRONOMETER_H
    #define CHRONOMETER_H
    
    #include "project.h"

    /*** MACROS ***/
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern uint16 ms;
    
    /*** FUNCTION PROTOTYPES ***/
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(msCounter);
    
#endif

/* [] END OF FILE */
