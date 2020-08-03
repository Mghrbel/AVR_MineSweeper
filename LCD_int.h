/**********************************************************************/
/* File   : LCD_int.h                                                 */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_

//Define Rows addresses
#define Row0 0x00
#define Row1 0x01

//Define Columns addresses
#define Col0 0x00
#define Col1 0x01
#define Col2 0x02
#define Col3 0x03
#define Col4 0x04
#define Col5 0x05
#define Col6 0x06
#define Col7 0x07
#define Col8 0x08
#define Col9 0x09
#define Col10 0x0A
#define Col11 0x0B
#define Col12 0x0C
#define Col13 0x0D
#define Col14 0x0E
#define Col15 0x0F

//Define instructions
#define Two_Line_Display 0x38
#define Clr 0x01
#define Ret_Home 0x02
#define Entery_Mode 0x06
#define Disp_On 0x0C
#define Disp_On_Curs_On 0x0E
#define Disp_On_Curs_Off 0x0C


//Define cursor set instructions
#define Cursur_Right 0x14
#define Cursor_Left 0x10
#define second_line 0xc0
#define first_line 0x80

void LCD_vidInit (void) ;
void LCD_vidSendData (u8 data) ;
void LCD_vidSendCommand (u8 command) ;
void LCD_vidSendString (u8 *str);
void LCD_vidSendNumber (u16 num);
void LCD_vidGoToXY(u8 Row,u8 Col);


//void LCD_vidSetCursor (void);


#endif /* LCD_INT_H_ */
