/**********************************************************************/
/* File   : Project_cfg.h                                             */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#ifndef PROJECT_CFG_H_
#define PROJECT_CFG_H_

#define ADC_PORT 									MY_PORTA
#define ADC_Channel0 								PIN0

#define LCD_DATA_PORT 								MY_PORTB
#define LCD_CTRL_PORT 								MY_PORTC
#define LCD_Rs_PIN 									PIN0
#define LCD_Rw_PIN 									PIN1
#define LCD_E_PIN 									PIN2

#define Motors_PORT 								MY_PORTC
#define Motor_RF_PIN 								PIN3
#define Motor_RB_PIN 								PIN4
#define Motor_LF_PIN 								PIN5
#define Motor_LB_PIN 								PIN6

#define Buzzer_PORT									MY_PORTC
#define Buzzer_PIN									PIN7

#define BlueTooth_PORT 								MY_PORTD
#define BlueTooth_TX_PIN 							PIN0
#define BlueTooth_RX_PIN 							PIN1

#define MetalSensor_PORT 							MY_PORTD
#define MetalSensor_Signal_PIN 						PIN2

#define UltraSonic_PORT 							MY_PORTD
#define UltraSonic_Echo_PIN 						PIN3
#define UltraSonic_Trig_PIN 						PIN4

#endif /* PROJECT_CFG_H_ */
