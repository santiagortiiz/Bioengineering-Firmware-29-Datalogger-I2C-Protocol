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
#include "project.h"

#include "chronometer.h"
#include "interface.h"
#include "uart_communication.h"

#include "mcp7940.h"
#include "lm75bd.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_counter_StartEx(msCounter);
    isr_rx_StartEx(uartRx);

    /* COMPONENT INITIALIZATION */
    LCD_Start();
    UART_Start();
    Counter_Start();
    I2C_Start();
                  
    for(;;)
    {
        /* Time Update Routine */
        if (receivedTime){                                  // When the user update the time this routine is executed
            receivedTime = 0;
            MenuUART(CONFIRM_UPDATE);                       // Comfirm the reception of the actual time
            timeUpdate();                                   // Update the time of the RTC
        }
        
        /* Data Adquisition Routine */
        if (ms%1000 == 0){                                  // Each second Do:
            
            time.hour = MCP7940_GetHour();                  // Time reading from the RTC
            time.minutes = MCP7940_GetMinutes();
            time.seconds = MCP7940_GetSeconds();
            time.weekday = MCP7940_GetWeekDay();
            time.date = MCP7940_GetDate();
            time.month = MCP7940_GetMonth();
            time.year   = MCP7940_GetYear();
            
            LM75BD_temperature = LM75BD_GetTemperature();   // Temperature reading from the LM75BD
            
            /* Data Display Routine */
            MenuLCD(SHOW_TEMPERATURE);
            MenuLCD(SHOW_TIME);
            MenuLCD(SHOW_PY_STATE);
            
            if (python_sync_up){
                MenuUART(SEND_TIME);
                MenuUART(SEND_DATE);
                MenuUART(SEND_TEMPERATURE);
            }
        }
        
    }
}

/* [] END OF FILE */
