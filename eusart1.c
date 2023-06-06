/**
  Section: Included Files
 */

#include <xc.h>
#include "eusart1.h"

/**
  Section: EUSART1 APIs
 */

/* This Function to Initialise the USART Driver */

void EUSART1_Initialize(void) {
    TRISC=0x80;      // Configure Rx pin as input and Tx as output  
  	TXSTA=0x20;      // Asynchronous mode, 8-bit data & enable transmitter
	RCSTA=0x90;      // 8-bit continous receive enable
	SPBRG=31;        // 9600 Baud rate at 20MHz
    RCSTAbits.CREN=1;
  }

/* This Function to Read one byte from the USART */

uint8_t EUSART1_Read(void) {

    while (PIR1bits.RCIF==0); {
    }
    return RCREG;
    PIR1bits.RCIF=0;
}

/* This Function to Write one byte to the USART */

void EUSART1_Write(uint8_t txData) {
    while (0 == PIR1bits.TXIF) {
    }

    TXREG = txData; // Write the data byte to the USART.
}

/* This Function to Write string to the USART */

void put_string(const unsigned char* str) {
    while (*str != NULL) {
        while (0 == PIR1bits.TXIF) {
        }

        TXREG = *str++; // Write the data byte to the USART.
    }
}

/* This Function to Read string from the USART */

void UART_RxString(char *string_ptr)
 {
     char ch;
     while(1)
       {
          ch=EUSART1_Read();    //Receive a char
 
        if((ch=='\r') || (ch=='\n')) //read till enter key is pressed
           {				     //once enter key is pressed
              *string_ptr=0;            //null terminate the string
                break;			     //and break the loop
             }
         *string_ptr=ch;                //copy the char into string.
         string_ptr++;			    //and increment the pointer
      }
 }

/**
  End of File
 */