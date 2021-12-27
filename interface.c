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
#include "interface.h"
#include "uart_communication.h"
#include "lm75bd.h"
#include "mcp7940.h"

/*** VARIABLES ***/

/*** FUNCTIONS ***/
void MenuLCD(uint8 menu_index){
    switch(menu_index){
        case SHOW_TEMPERATURE:
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("Temp.");                       
            LCD_Position(1,0);
            LCD_PrintNumber(LM75BD_temperature/1000);       // Temperature display routine by digits
            LCD_PutChar('.');
            LCD_PrintNumber(LM75BD_temperature/100%10);
            LCD_PrintNumber(LM75BD_temperature/10%10);
            LCD_PrintNumber(LM75BD_temperature%10);
            LCD_PutChar(LCD_CUSTOM_0);
            LCD_PutChar('C');
            break;
            
        case SHOW_TIME:
            LCD_Position(0,11);
            switch(time.weekday){
                case 1:
                    LCD_PrintString("Monday");
                    break;
                case 2:
                    LCD_PrintString("Tuesday");
                    break;
                case 3:
                    LCD_PrintString("Wednesday");
                    break;
                case 4:
                    LCD_PrintString("Thursday");
                    break;
                case 5:
                    LCD_PrintString("Friday");
                    break;
                case 6:
                    LCD_PrintString("Saturday");
                    break;
                case 7:
                    LCD_PrintString("Sunday");
                    break;
            }
            
            LCD_Position(1,12);
            LCD_PrintNumber(time.date);
            LCD_PutChar('/');
            LCD_PrintNumber(time.month);
            LCD_PutChar('/');
            LCD_PrintNumber(time.year);
            
            LCD_Position(2,10);
            LCD_PrintNumber(time.hour);
            LCD_PutChar(':');
            LCD_PrintNumber(time.minutes);
            LCD_PutChar(':');
            LCD_PrintNumber(time.seconds);
            
            LCD_Position(2,18);
            switch(time.am_pm){
                case 0:
                    LCD_PrintString("am");
                    break;
                case 1:
                    LCD_PrintString("pm");
                    break;
            }
            
            switch(time.leap_year){
                case 0:
                    LCD_Position(3,8);
                    LCD_PrintString("Leap Year:");
                    LCD_PrintString("No");
                    break;
                case 1:
                    LCD_Position(3,7);
                    LCD_PrintString("Leap Year:");
                    LCD_PrintString("Yes");
                    break;
            }
            break;
            
            case SHOW_PY_STATE:
                LCD_Position(2,0);
                LCD_PrintString("Python");
                LCD_Position(3,0);
                if (python_sync_up){
                    LCD_PrintString("ON");
                }
                else{
                    LCD_PrintString("OFF");
                }
                break;
    }
}

void MenuUART(uint8 menu_index){
    switch(menu_index){
        case CONFIRM_UPDATE:
            UART_PutChar(0xFF);
            break;
        case SEND_TIME: 
            UART_PutChar(time.am_pm);
            UART_PutChar(time.hour);
            UART_PutChar(time.minutes);
            UART_PutChar(time.seconds);
            break;
        case SEND_DATE:
            UART_PutChar(time.date);
            UART_PutChar(time.month);
            UART_PutChar(time.year);
            break;
        case SEND_TEMPERATURE:  
            UART_PutChar(LM75BD_temperature/1000);
            UART_PutChar(LM75BD_temperature/100%10);
            UART_PutChar(LM75BD_temperature/10%10);
            UART_PutChar(LM75BD_temperature%10);
            break;
    }
}

/* [] END OF FILE */
