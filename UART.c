/**********************************************************************/
/* File   : UART.c                                                    */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"

void UART_vidInit (void)
{
	//UBRR = 78 To get 9600 Baud rate
		UBRRL = 78;
		UBRRH = 0;
	//Initialization (Asynchronous,no parity,1 stop bit,8 Data bit)
		UCSRC = 0x86;
	//Transmitter & Receiver enable and RX Complete Interrupt Enable
		UCSRB = 0x98;
}

void UART_vidSendData (u8 Data)
{
	while (GET_BIT(UCSRA,5) == 0x00) ;				//Hold for Data Register (UDR) to be empty
	UDR = Data ;
}

u8 UART_u8RecieveData (void)
{
	u8 Data ;
	while (GET_BIT(UCSRA,7) == 0x00) ;				//Hold for Receive Complete flag to be 1
	Data = UDR ;
	SET_BIT(UCSRA,7);
	return Data ;
}
