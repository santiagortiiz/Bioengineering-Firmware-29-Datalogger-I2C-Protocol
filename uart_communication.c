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
#include "uart_communication.h"
#include "mcp7940.h"

/*** VARIABLES ***/
static volatile uint8 i;
uint8 python_sync_up = 0;

uint8 receivedTime = 0;
uint8 buffer[10];               // Store the parameters of the time when it
                                // will be configured

/*** FUNCTIONS ***/
void timeUpdate(void){          // Send the buffer's content
    MCP7940_TimeConfiguration(SECONDS, MINUTES, FORMAT, AM_PM, HOUR, 
                                WKDAY, DATE, MONTH, LEAP_YEAR, YEAR);
}

/*** INTERRUPTS ***/
CY_ISR(uartRx){
    if (python_sync_up){            // When the communication is working, it will
        if (UART_GetChar() == 0x00){// stop if the UART get 0x00
            python_sync_up = 0;
        }
    }
    else{
        buffer[i] = UART_GetChar(); // Store each received byte into the buffer
        i++;
        if (i == 10){               // When the buffer is full, a flag is activated
            i = 0;
            receivedTime = 1;
            python_sync_up = 1;
        }
    }
}

/* [] END OF FILE */
