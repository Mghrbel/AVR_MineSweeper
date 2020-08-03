/**********************************************************************/
/* File   : LCD.c                                                     */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#include "STD_TYPES.h"
#include "DIO.h"
#include "LCD_int.h"
#include "Project_cfg.h"

#define F_CPU 12000000UL
#include<util/delay.h>



//Initialization function
void LCD_vidInit (void)
{
	_delay_ms(30);         //waiting 30 ms for VDD to reach 4.5v
	LCD_vidSendCommand(Two_Line_Display);
	_delay_ms(1);          //waiting for 39 micro sec
	LCD_vidSendCommand(Disp_On_Curs_Off);
	_delay_ms(1);          //waiting for 39 micro sec
	LCD_vidSendCommand(Clr);
	_delay_ms(2);          //waiting for more than 1.53 ms
	LCD_vidSendCommand(Entery_Mode);
}




//Sending instruction to LCD function
void LCD_vidSendCommand (u8 command)
{
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_Rs_PIN,LOW);  //Rs pin = 0 Because of sending command
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_Rw_PIN,LOW);  //Rw pin = 0 Because of writing of LCD
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);  //E pin = 1 To start the pulse High

	DIO_SetPortValue(LCD_DATA_PORT,command);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);   //E pin = 0 To start falling edge
	_delay_ms(5);                           //delay for make sure command was sent during falling edge
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);  //E pin = 1 To finish the pulse (not important)
}





//Sending data to LCD function
void LCD_vidSendData (u8 data)
{
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_Rs_PIN,HIGH);  //Rs pin = 1 Because of sending data
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_Rw_PIN,LOW);   //Rw pin = 0 Because of writing of LCD
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);   //E pin = 1 To start the pulse High

	DIO_SetPortValue(LCD_DATA_PORT,data);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);   //E pin = 0 To start falling edge
	_delay_ms(5);                           //delay for make sure data was sent during falling edge
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);  //E pin = 1 To finish the pulse (not important)


}





//Sending string to LCD function
void LCD_vidSendString (u8 *str)
{
	u8 i = 0 ;
	while (str[i]!=0)                  //Check for each element sent is not the end(null)
	{
		LCD_vidSendData(str[i]);

		if (i==15)
		{
			LCD_vidGoToXY(Row1,Col0);
		}

		i++ ;
	}
}






//Sending number to LCD function
void LCD_vidSendNumber (u16 num)
{
	if ( num > 1000)
	{
		u16 digit = num / 1000 ;
		LCD_vidSendData(digit+48);
		num = num - digit * 1000 ;
		digit = num / 100 ;
		LCD_vidSendData(digit+48);
		num = num - digit * 100 ;
		digit = num / 10 ;
		LCD_vidSendData(digit+48);
		num = num - digit * 10 ;
		digit = num ;
		LCD_vidSendData(digit+48);
	}
	else if ( num > 100)
	{
		u16 digit = num / 100 ;
		LCD_vidSendData(digit+48);
		num = num - digit * 100 ;
		digit = num / 10 ;
		LCD_vidSendData(digit+48);
		num = num - digit * 10 ;
		digit = num ;
		LCD_vidSendData(digit+48);
	}
	else if (num > 10)
	{
		u16 digit = num / 10 ;
		LCD_vidSendData(digit+48);
		num = num - digit * 10 ;
		digit = num ;
		LCD_vidSendData(digit+48);
	}
	else
	{
		u16 digit = num ;
		LCD_vidSendData(digit+48);
	}
}







//Set cursor to specific location (row and column)
void LCD_vidGoToXY(u8 Row,u8 Col)
{
	u8 inst;
	inst = 0x80 | Col ;
	if (Row == Row1)
	{
		inst |= 0x40;
	}
	LCD_vidSendCommand(inst);
}
