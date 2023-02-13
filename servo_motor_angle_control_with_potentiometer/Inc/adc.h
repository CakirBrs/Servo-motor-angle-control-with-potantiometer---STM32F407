/*
 * adc.h
 *
 *  Created on: 11 Şub 2023
 *      Author: metab
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f407xx.h"

void adc_init();
uint32_t adc_read();
void start_conversation();

#endif /* ADC_H_ */
