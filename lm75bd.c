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
#include "lm75bd.h"
#include "i2c_protocol.h"

/*** VARIABLES ***/
uint8 LM75BD_configuration;
uint32 LM75BD_temperature;

/*** FUNCTIONS ***/
uint8 LM75BD_GetConfiguration(void){
    return I2C_ReadTransaction(LM75BD_ADDRESS, CONF_REGISTER, REQUEST_1_BYTE);
}

uint32 LM75BD_GetTemperature(void){
    uint32 temp;
    temp = I2C_ReadTransaction(LM75BD_ADDRESS, TEMP_REGISTER, REQUEST_2_BYTES) >> 5;
    temp *= 125;    // Sensor Sensitivity = 0.125°C
    return temp;    // Return Temperature*1000 to show 3 decimals
}

/*** INTERRUPTS ***/

/* [] END OF FILE */
