/*
 * Excersice1.c
 *
 *  Created on: Sep 11, 2024
 *      Author: MSIFPT
 */
#include "Excersice1.h"
#include "main.h"
void init_exc1() {
	HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, YELOW_LED_Pin, RESET);
}

int check = 1;

void exc1_run() {
	if (check == 0) {
		HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, YELOW_LED_Pin, RESET);
		check = 1;
	}
	else {
		HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, YELOW_LED_Pin, SET);
		check = 0;
	}
}
