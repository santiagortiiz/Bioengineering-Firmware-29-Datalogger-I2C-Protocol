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

#ifndef INTERFACE_H
    #define INTERFACE_H
    
    #include "project.h"

    /*** MACROS ***/
    #define SHOW_TEMPERATURE 0
    #define SHOW_TIME 1
    #define SHOW_PY_STATE 2
    
    #define CONFIRM_UPDATE 0
    #define SEND_TIME 1
    #define SEND_DATE 2
    #define SEND_TEMPERATURE 3
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    
    /*** FUNCTION PROTOTYPES ***/
    void MenuLCD(uint8);
    void MenuUART(uint8);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */
