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

#ifndef I2C_PROTOCOL_H
    #define I2C_PROTOCOL_H
    
    #include "project.h"

    /*** MACROS ***/
    #define REQUEST_1_BYTE 0
    #define REQUEST_2_BYTES 1
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    void I2C_WriteTransaction(uint8 device_address, uint8 register_address, uint8 data);
    
    /*** FUNCTION PROTOTYPES ***/
    uint16 I2C_ReadTransaction(uint8 device_address, uint8 register_address, uint8 request2bytes);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */
