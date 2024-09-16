/*
 * Excersice3.c
 *
 *  Created on: Sep 11, 2024
 *      Author: MSIFPT
 */

#include "main.h"
#include "Excersice3.h"


void control_traffic_red(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin) {
	HAL_GPIO_WritePin(GPIOx, green_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, yellow_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, red_pin, GPIO_PIN_SET);
}

void control_traffic_yelow(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin) {
	HAL_GPIO_WritePin(GPIOx, green_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, yellow_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOx, red_pin, GPIO_PIN_RESET);
}

void control_traffic_green(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin) {
	HAL_GPIO_WritePin(GPIOx, green_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOx, yellow_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, red_pin, GPIO_PIN_RESET);
}

void init_exc3() {

}

void exc3_run(int road, int index) {
	if (road == 1) {
		if (index < 3) {
			control_traffic_green(GPIOB, LED_10_Pin, LED_9_Pin, LED_8_Pin);
			control_traffic_green(GPIOB, LED_4_Pin, LED_3_Pin, LED_2_Pin);
			control_traffic_red(GPIOB, LED_7_Pin, LED_6_Pin, LED_5_Pin);
			control_traffic_red(GPIOB, LED_1_Pin, LED_12_Pin, LED_11_Pin);
		}
		else if (index >= 3 && index < 5) {
			control_traffic_yelow(GPIOB, LED_10_Pin, LED_9_Pin, LED_8_Pin);
			control_traffic_yelow(GPIOB, LED_4_Pin, LED_3_Pin, LED_2_Pin);
		}
		else if (index == 5) {
			index = -1;
			road = 0;
		}
		index++;
	}
	else {
		if (index < 3) {
			control_traffic_red(GPIOB, LED_10_Pin, LED_9_Pin, LED_8_Pin);
			control_traffic_red(GPIOB, LED_4_Pin, LED_3_Pin, LED_2_Pin);
			control_traffic_green(GPIOB, LED_7_Pin, LED_6_Pin, LED_5_Pin);
			control_traffic_green(GPIOB, LED_1_Pin, LED_12_Pin, LED_11_Pin);
		}
		if (index >= 3 && index < 5) {
			control_traffic_yelow(GPIOB, LED_7_Pin, LED_6_Pin, LED_5_Pin);
			control_traffic_yelow(GPIOB, LED_1_Pin, LED_12_Pin, LED_11_Pin);
		}
		if (index == 5) {
			road = 1;
			index = -1;
		}
		index++;
	}
}
