/*
 * Excersice6.c
 *
 *  Created on: Sep 17, 2024
 *      Author: MSIFPT
 */

#include "Excersice8.h"

#include "main.h"

void initLED() {
	// Thiết lập tất cả các chân PB0 -> PB11 là đầu ra
	    for (int pin = 0; pin <= 11; pin++) {
	        GPIO_InitTypeDef GPIO_InitStruct = {0};
	        GPIO_InitStruct.Pin = (1 << pin);    // Thiết lập từng chân từ PB0 -> PB11
	        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	        GPIO_InitStruct.Pull = GPIO_NOPULL;
	        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);  // Thiết lập cho port B
	    }
}

void setNumberOnClock(int num) {
	HAL_GPIO_WritePin(GPIOB, (1 << num), GPIO_PIN_SET);
}
