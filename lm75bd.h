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

#ifndef LM75BD_H
    #define LM75BD_H
    
    #include "project.h"

    /*** MACROS ***/
    #define LM75BD_ADDRESS 0b01001000
    #define TEMP_REGISTER 0
    #define CONF_REGISTER 1
    #define THYST_REGISTER 2
    #define TOS_REGISTER 3
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern uint8 LM75BD_configuration;
    extern uint32 LM75BD_temperature;
    
    /*** FUNCTION PROTOTYPES ***/
    uint8 LM75BD_GetConfiguration(void);
    uint32 LM75BD_GetTemperature(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */
