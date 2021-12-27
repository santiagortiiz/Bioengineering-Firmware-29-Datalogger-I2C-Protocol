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

#ifndef MCP7940_H
    #define MCP7940_H
    
    #include "project.h"

    /*** MACROS ***/
    #define MCP7940_ADDRESS 0b01101111
    #define STOP_BYTE       0b00000000
    
    #define RTCSEC      0x00
    #define RTCMIN      0x01
    #define RTCHOUR     0x02
    #define RTCWKDAY    0x03
    #define RTCDATE     0x04
    #define RTCMTH      0x05
    #define RTCYEAR     0x06
    #define CONTROL     0x07
    #define OSCTRIM     0x08
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    typedef struct TimeStruct{
        uint8 seconds:8;
        uint8 minutes:8;
        uint8 format_12_24:8;
        uint8 am_pm:8;
        uint8 hour:8;
        uint8 weekday:8;
        uint8 date:8;
        uint8 month:8;
        uint8 leap_year:8;
        uint8 year:8;
    } Time;
    extern Time time;
    
    /*** FUNCTION PROTOTYPES ***/
    void MCP7940_Start(void);
    void MCP7940_Stop(void);
    void MCP7940_TimeConfiguration(uint8 seconds, uint8 minutes, uint8 format_24_12, uint8 am_pm, uint8 hour, 
                                    uint8 weekday, uint8 date, uint8 month, uint8 leap_year, uint8 year);
    
    void MCP7940_SetSeconds(uint8 seconds);
    void MCP7940_SetMinutes(uint8 minutes);
    void MCP7940_SetHour(uint8 format_24_12, uint8 am_pm, uint8 hour);
    void MCP7940_SetWeekDay(uint8 weekday);
    void MCP7940_SetDate(uint8 date);
    void MCP7940_SetMonth(uint8 month, uint8 leap_year);
    void MCP7940_SetYear(uint8 year);

    uint8 MCP7940_GetSeconds(void);
    uint8 MCP7940_GetMinutes(void);
    uint8 MCP7940_GetHour(void);
    uint8 MCP7940_GetWeekDay(void);
    uint8 MCP7940_GetDate(void);
    uint8 MCP7940_GetMonth(void);
    uint8 MCP7940_GetYear(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */
