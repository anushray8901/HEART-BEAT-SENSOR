/**
  @File Name
    eusart1.h

  @Description
    This header file provides APIs for driver for EUSART1.
    Generation Information :
        Device            :  PIC16F877A    
*/

#ifndef _EUSART1_H
#define _EUSART1_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


/**
  Section: Macro Declarations
*/

#define EUSART1_DataReady  (PIR1bits.RC1IF)

/**
  Section: EUSART1 APIs
*/

/**
  @Summary
    Initialization routine that takes inputs from the EUSART1 GUI.

  @Description
    This routine initializes the EUSART1 driver.
    This routine must be called before any other EUSART1 routine is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    
*/
void EUSART1_Initialize(void);

/**
  @Summary
    Read a byte of data from the EUSART1.

  @Description
    This routine reads a byte of data from the EUSART1.

  @Preconditions
    EUSART1_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if the receiver is not empty before calling this function.

  @Param
    None

  @Returns
    A data byte received by the driver.
*/
uint8_t EUSART1_Read(void);

 /**
  @Summary
    Writes a byte of data to the EUSART1.

  @Description
    This routine writes a byte of data to the EUSART1.

  @Preconditions
    EUSART1_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if transmitter is not busy before calling this function.

  @Param
    txData  - Data byte to write to the EUSART1

  @Returns
    None
*/
void EUSART1_Write(uint8_t txData);

void put_string(const unsigned char* str); //print string.

void UART_RxString(char *string_ptr);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // _EUSART1_H
/**
 End of File
*/
