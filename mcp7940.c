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
#include "mcp7940.h"
#include "i2c_protocol.h"

/*** VARIABLES ***/
Time time;

/*** FUNCTIONS ***/
void MCP7940_Start(void){
    uint8 seconds = 0;
    seconds = time.seconds;
    seconds = seconds ^ 0b10000000;                             // Set the bit which enable the oscillator
    I2C_WriteTransaction(MCP7940_ADDRESS, RTCSEC, seconds);
}

void MCP7940_Stop(void){
    I2C_WriteTransaction(MCP7940_ADDRESS, RTCSEC, STOP_BYTE);   // Clear the bit which enable the oscillator (disable)
}

void MCP7940_TimeConfiguration(uint8 seconds, uint8 minutes, uint8 format_24_12, uint8 am_pm, uint8 hour, uint8 weekday, uint8 date, uint8 month, uint8 leap_year, uint8 year){
    MCP7940_Stop();
    MCP7940_SetSeconds(seconds);
    MCP7940_SetMinutes(minutes);
    MCP7940_SetHour(format_24_12, am_pm, hour);
    MCP7940_SetWeekDay(weekday);
    MCP7940_SetDate(date);
    MCP7940_SetMonth(month, leap_year);
    MCP7940_SetYear(year);
    MCP7940_Start();
}

/* Configuration Routines */
void MCP7940_SetSeconds(uint8 seconds){
    if (seconds < 60){
        seconds = seconds/10 << 4  | seconds%10;
        time.seconds = seconds;
        //I2C_WriteTransaction(MCP7940_ADDRESS, RTCSEC, seconds);
    }
}

void MCP7940_SetMinutes(uint8 minutes){
    if (minutes < 60){
        minutes = minutes/10 << 4  | minutes%10;
        I2C_WriteTransaction(MCP7940_ADDRESS, RTCMIN, minutes);
    }
}

void MCP7940_SetHour(uint8 format_24_12, uint8 am_pm, uint8 hour){
    switch(format_24_12){
        case 0:                                 // 24 hours
            if (hour < 24){
                hour = hour/10 << 4 | hour%10;
                hour = hour & 0b00111111;
                I2C_WriteTransaction(MCP7940_ADDRESS, RTCHOUR, hour);
            }
            break;
        case 1:                                 // 12 hours
            if (hour < 13){
                hour = hour/10 << 4 | hour%10;
                if (am_pm == 0){
                    hour = hour | 0b01011111;   // Set 12/~24 bit
                    hour = hour & 0b01011111;   // Clear AM/PM bit
                    I2C_WriteTransaction(MCP7940_ADDRESS, RTCHOUR, hour);
                }
                else if (am_pm == 1){
                    hour = hour | 0b01100000;   // Set 12/~24 bit and Set AM/PM bit 
                    I2C_WriteTransaction(MCP7940_ADDRESS, RTCHOUR, hour);
                }
            }
            break;
    }
}

void MCP7940_SetWeekDay(uint8 weekday){
    if (weekday < 8){
        I2C_WriteTransaction(MCP7940_ADDRESS, RTCWKDAY, weekday);
    }
}

void MCP7940_SetDate(uint8 date){
    date = date/10 << 4 | date%10;
    I2C_WriteTransaction(MCP7940_ADDRESS, RTCDATE, date);
}

void MCP7940_SetMonth(uint8 month, uint8 leap_year){
    if (month < 13){
        month = month/10 << 4 | month%10;
        if (leap_year){
            month = month | 0b00100000;
            I2C_WriteTransaction(MCP7940_ADDRESS, RTCMTH, month);
        }
        
        else {
            month = month & 0b00011111;
            I2C_WriteTransaction(MCP7940_ADDRESS, RTCMTH, month);
        }
    }
}

void MCP7940_SetYear(uint8 year){
    if (year < 100){
        year = year/10 << 4 | year%10;
        I2C_WriteTransaction(MCP7940_ADDRESS, RTCYEAR, year);
    }
}

/* Reading Routines */
uint8 MCP7940_GetSeconds(void){
    volatile uint8 byte;
    uint8 seconds;
    uint8 seconds_tens;
    uint8 seconds_ones;
    
    byte = I2C_ReadTransaction(MCP7940_ADDRESS, RTCSEC, REQUEST_1_BYTE);
    seconds_tens = byte >> 4 & 0b00000111; 
    seconds_ones = byte & 0b00001111;
    
    seconds = seconds_tens*10 + seconds_ones;
    return seconds;
}

uint8 MCP7940_GetMinutes(void){
    volatile uint8 byte;
    uint8 minutes;
    uint8 minutes_tens;
    uint8 minutes_ones;
    
    byte = I2C_ReadTransaction(MCP7940_ADDRESS, RTCMIN, REQUEST_1_BYTE);
    minutes_tens = byte >> 4 & 0b00000111; 
    minutes_ones = byte & 0b00001111;
    
    minutes = minutes_tens*10 + minutes_ones;
    return minutes;
}

uint8 MCP7940_GetHour(void){
    volatile uint8 byte;
    uint8 hour;
    uint8 hour_tens;
    uint8 hour_ones;
    
    byte = I2C_ReadTransaction(MCP7940_ADDRESS, RTCHOUR, REQUEST_1_BYTE);
    time.format_12_24 = byte >> 6 & 1;
    time.am_pm = byte >> 5 & 1;
    hour_tens = byte >> 4 & 0b00000001; 
    hour_ones = byte & 0b00001111;
    
    hour = hour_tens*10 + hour_ones;
    return hour;
}

uint8 MCP7940_GetWeekDay(void){
    uint8 byte;
    uint8 weekday;
    
    byte = I2C_ReadTransaction(MCP7940_ADDRESS, RTCWKDAY, REQUEST_1_BYTE);
    
    weekday = byte & 0b00000111;
    return weekday;
}

uint8 MCP7940_GetDate(void){
    uint8 byte;
    uint8 date;
    uint8 date_tens;
    uint8 date_ones;
    
    byte = I2C_ReadTransaction(MCP7940_ADDRESS, RTCDATE, REQUEST_1_BYTE);
    date_tens = byte >> 4 & 0b00000011; 
    date_ones = byte & 0b00001111;
    
    date = date_tens*10 + date_ones;
    return date;
}

uint8 MCP7940_GetMonth(void){
    uint8 byte;
    uint8 month;
    uint8 month_tens;
    uint8 month_ones;
    
    byte = I2C_ReadTransaction(MCP7940_ADDRESS, RTCMTH, REQUEST_1_BYTE);
    time.leap_year = byte >> 5 & 1;
    month_tens = byte >> 4 & 0b00000011; 
    month_ones = byte & 0b00001111;
    
    month = month_tens*10 + month_ones;
    return month;
}

uint8 MCP7940_GetYear(void){
    uint8 byte;
    uint8 year;
    uint8 year_tens;
    uint8 year_ones;
    
    byte = I2C_ReadTransaction(MCP7940_ADDRESS, RTCYEAR, REQUEST_1_BYTE);
    year_tens = byte >> 4 & 0b00000011; 
    year_ones = byte & 0b00001111;
    
    year = year_tens*10 + year_ones;
    return year;
}

/*** INTERRUPTS ***/

/* [] END OF FILE */
