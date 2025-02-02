/*
 * Excersice2.c
 *
 *  Created on: Sep 11, 2024
 *      Author: MSIFPT
 */

#include "main.h"
#include "Excersice2.h"

void init_exc2() {
	HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, YELOW_LED_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, RESET);
}

int count = 0;
int color = 0;

void exc2_run() {
	switch(color) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, YELOW_LED_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, SET);
		count++;
		if (count == 3) {
			color = 1;
			count = 0;
		}
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, YELOW_LED_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, RESET);
		count++;
		if (count == 2) {
			color = 2;
			count = 0;
		}
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, YELOW_LED_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, RESET);
		count++;
		if (count == 5) {
			color = 0;
			count = 0;
		}
		break;
	default:
		color = 0;
		break;
	}
}
