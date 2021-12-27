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

#ifndef UART_COMMUNICATION_H
    #define UART_COMMUNICATION_H
    
    #include "project.h"

    /*** MACROS ***/
    #define SECONDS     buffer[0]
    #define MINUTES     buffer[1]
    #define FORMAT      buffer[2]
    #define AM_PM       buffer[3]
    #define HOUR        buffer[4]
    #define WKDAY       buffer[5]
    #define DATE        buffer[6]
    #define MONTH       buffer[7]
    #define LEAP_YEAR   buffer[8]
    #define YEAR        buffer[9]
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern uint8 python_sync_up;
    extern uint8 receivedTime;
    extern uint8 buffer[10];
    
    /*** FUNCTION PROTOTYPES ***/
    void timeUpdate(void);
    void pythonSync(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(uartRx);
    
#endif

/* [] END OF FILE */
