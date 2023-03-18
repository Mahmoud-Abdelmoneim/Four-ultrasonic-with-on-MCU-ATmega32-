/*
 *
 * main.c
 *  Created on: 9 March 2023
 *      Author: Mahmoud Abdelmoniem
 *
 */
#include "main.h"

Ultrasonic_t ultrasonic1={
		.Trigger=PORTC_0
};
Ultrasonic_t ultrasonic2={
		.Trigger=PORTC_1
};
Ultrasonic_t ultrasonic3={
		.Trigger=PORTC_2
};
Ultrasonic_t ultrasonic4={
		.Trigger=PORTC_3
};
uint8 distance;


int main()
{
	sei();
	Dio_init();
	LCD_Init();
	Ultrasonic_init();
	uint8 dis[]="Distance:";

	LCD_Send_String_Pos(dis,1,1);
	while(1){

		distance=UltrasonicReadDistance(&ultrasonic1);
		LCD_Send_String_Pos("                ",2,1);
		LCD_Send_Number_Pos(distance, 2, 1);
		_delay_ms(100);
		distance=UltrasonicReadDistance(&ultrasonic2);

		LCD_Send_Number_Pos(distance, 2, 5);

		_delay_ms(100);
		distance=UltrasonicReadDistance(&ultrasonic3);

		LCD_Send_Number_Pos(distance, 2, 9);
		_delay_ms(100);

	}

}
