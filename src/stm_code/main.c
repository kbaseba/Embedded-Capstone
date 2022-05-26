//interfaces ultrasonic sensor
//reference: https://github.com/Ruturajn/Ultrasonic-Sensor-Interfacing-with-stm32f407-DISC/blob/main/main.c
//PA6 echo
//PA5 trig
//VCC 5V

#include "stm32f4xx.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define ARM_MATH_CM4


void GPIO_Init(void);
void TIM2_us_Delay(uint32_t delay); //TIM2 for generating 10us pulse for trig pin



uint32_t data;
double time,dist,on;
bool on1; //dist sensor on
bool on2; //camera on
double output[] = {0, 0};

void GPIO_Init(){
	//Configuring PA5 for generating pulse sent to trig pin
	RCC->AHB1ENR |= 1; //Enable GPIOA clock
	GPIOA->MODER |= 1<<10; //Set the PA5 pin to output mode

	//Configuring output from echo pin to be sent to the board (PA6 pin)
	GPIOA->MODER &= ~(0x00003000); //Set PA6 to input mode

	//configuring button (distance sensor control)
	GPIO_InitTypeDef pushbutton;
	pushbutton.Pin = GPIO_PIN_0;
	pushbutton.Mode = GPIO_MODE_INPUT;
	pushbutton.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &pushbutton);

	//external button (temperature sensor control) PA1 to input
	GPIOA->MODER &= ~((1<<2) | (1<<3));
}


void TIM2_us_Delay(uint32_t delay){
	RCC->APB1ENR |=1; //Start the clock for the timer peripheral
	TIM2->ARR = (int)(delay/0.0625); // Total period of the timer
	TIM2->CNT = 0;
	TIM2->CR1 |= 1; //Start the Timer
	while(!(TIM2->SR & TIM_SR_UIF)){} //Polling the update interrupt flag
	TIM2->SR &= ~(0x0001); //Reset the update interrupt flag
}

int _write(int file, char *ptr, int len){
	int i = 0;
	for(i=0;i<len;i++)
		ITM_SendChar((*ptr++));
	return len;
}

int main(){
	RCC->CFGR |= 0<<10; // set APB1 = 16 MHz
	GPIO_Init();
	GPIOA->BSRR = 0x00000000;// Setting trig pin to low to initialize the module

	while(1){
		//1. Sending 10us pulse to
		GPIOA->BSRR &= 0x00000000; //PA5 is low
		TIM2_us_Delay(2);

		GPIOA->BSRR |= 0x00000020;//PA5 set to High
		TIM2_us_Delay(10);// wait for 10us

		GPIOA->BSRR |= 0x00200000;// Make PA5 low again

		//2. Measure the pulse width of the pulse sent from the echo pin by polling IDR for port A
		while (GPIOA->IDR & 64){
			data = data+1;
		}

		//3.Converting the gathered data into distance in cm
		if (data>0){
			time = data*(0.0625*0.000001);
			dist = ((time*340)/2)*1000;
			output[1] = dist;
		}
		if (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0))
		{
			output[0] = 1;
			on1 = true;
		} else {
			output[0] = 0;
			on1 = false;
		}
		if (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1))
				{
					on2 = false;
				} else {
					on2 = true;
		}

		char dist_str[10];
		snprintf(dist_str, 10, "%f", dist); //convert dist to string

		char json[100];
		strcpy(json, "{ \"range\" : ");
		strcat(json, dist_str);
		strcat(json, " , \"range_on\" : ");
		strcat(json, on1 ? "true" : "false");
		strcat(json, " , \"camera_on\" : ");
		strcat(json, on2 ? "true" : "false");
		strcat(json, " }"); //create json format output

		//printf("%s", json);

		TIM2_us_Delay(4);
		data = 0;
		//strcpy (json, "");
	}

}
