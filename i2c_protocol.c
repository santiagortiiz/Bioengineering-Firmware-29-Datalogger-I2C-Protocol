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
#include "i2c_protocol.h"

/*** VARIABLES ***/

/*** FUNCTIONS ***/
void I2C_WriteTransaction(uint8 device_address, uint8 register_address, uint8 data){
    I2C_MasterSendStart(device_address, 0);     // Send the Start signal, the address and the write command
    I2C_MasterWriteByte(register_address);      // Send the address of the register
    I2C_MasterWriteByte(data);                  // Send the data to be written
    I2C_MasterSendStop();                       // Send the Stop signal
}

uint16 I2C_ReadTransaction(uint8 device_address, uint8 register_address, uint8 request2bytes){
    uint16 byte_received;
    
    /* Write Transaction */
    I2C_MasterSendStart(device_address, 0);     // Send the Start signal, the address and the write command
    I2C_MasterWriteByte(register_address);      // Send the address of the register   
    
    /* Read transaction */
    I2C_MasterSendRestart(device_address, 1);   // Send the Re-Start signal
    
    if (request2bytes){                         // If request the slave 2 bytes
        byte_received = I2C_MasterReadByte(I2C_ACK_DATA) << 8;
        byte_received |= I2C_MasterReadByte(I2C_ACK_DATA);
    }
    else {                                      // If request the slave 1 byte
        byte_received = I2C_MasterReadByte(I2C_NAK_DATA);
    }
    
    /* End transaction */
    I2C_MasterSendStop();                       // Send the Stop signal
    
    return byte_received;
}

/*** INTERRUPTS ***/

/* [] END OF FILE */
