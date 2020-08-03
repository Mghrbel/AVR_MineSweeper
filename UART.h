/**********************************************************************/
/* File   : UART.h                                                    */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#ifndef UART_H_
#define UART_H_

void UART_vidInit (void);
void UART_vidSendData (u8 Data);
u8 UART_u8RecieveData (void);

#endif /* UART_H_ */
