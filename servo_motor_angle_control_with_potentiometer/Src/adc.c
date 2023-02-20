/*
 * adc.c
 *
 *      Author: Baris Cakir
 */

#include "adc.h"

void adc_init(){
	//A port clock enable
	RCC->AHB1ENR |= (1U<<0);

	//PA0 analog mode
	GPIOA->MODER |= (1U<<0);
	GPIOA->MODER |= (1U<<1);

	//ADC clock enable
	RCC->APB2ENR |= (1U<<8);

	ADC->CR1 |= (1u<<24);
	ADC->CR2 &= ~(1u<<0);
	ADC->SQR3 |= 0;
	ADC->CR2 |= (1U<<0);



}


void start_conversation(){
	ADC->CR2 |= (1U<<30);
}

uint32_t adc_read(){
	//wait for conversation to be complete
	while(!(ADC->SR & (1U<<1)))
		;
	//converted data data
	return ADC->DR;
}

