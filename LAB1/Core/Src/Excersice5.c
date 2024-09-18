/*
 * Excersice5.c
 *
 *  Created on: Sep 16, 2024
 *      Author: MSIFPT
 */


#include "main.h"
#include "Excersice5.h"

int green = 1, red = 0, yelow = 0;
int indexs = 0;
int num = 5;
int num2 = 9;

void traffic_red(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin) {
	HAL_GPIO_WritePin(GPIOx, green_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, yellow_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, red_pin, GPIO_PIN_SET);
}

void traffic_yelow(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin) {
	HAL_GPIO_WritePin(GPIOx, green_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, yellow_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOx, red_pin, GPIO_PIN_RESET);
}

void traffic_green(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin) {
	HAL_GPIO_WritePin(GPIOx, green_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOx, yellow_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, red_pin, GPIO_PIN_RESET);
}

void exc5_run() {
	if (green == 1) {
		traffic_green(GPIOB, LED_10_Pin, LED_9_Pin, LED_8_Pin);
		traffic_green(GPIOB, LED_4_Pin, LED_3_Pin, LED_2_Pin);
	}
	if (yelow == 1) {
		traffic_yelow(GPIOB, LED_10_Pin, LED_9_Pin, LED_8_Pin);
		traffic_yelow(GPIOB, LED_4_Pin, LED_3_Pin, LED_2_Pin);
	}
	if (red == 1) {
		traffic_red(GPIOB, LED_10_Pin, LED_9_Pin, LED_8_Pin);
		traffic_red(GPIOB, LED_4_Pin, LED_3_Pin, LED_2_Pin);
	}
}

void init_exc5() {
	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, SET);
	traffic_green(GPIOB, LED_10_Pin, LED_9_Pin, LED_8_Pin);
	traffic_green(GPIOB, LED_4_Pin, LED_3_Pin, LED_2_Pin);
	traffic_red(GPIOB, LED_7_Pin, LED_6_Pin, LED_5_Pin);
	traffic_red(GPIOB, LED_1_Pin, LED_12_Pin, LED_11_Pin);
}

void display_7SEG() {
    // Mảng lưu giá trị các đoạn cho các số từ 0 đến 9
    uint8_t segments[10] = {
        0xC0, // 0 -> các đoạn a b c d e f (g tắt)
        0xF9, // 1 -> các đoạn b c (a, d, e, f, g tắt)
        0xA4, // 2 -> các đoạn a b d e g (c, f tắt)
        0xB0, // 3 -> các đoạn a b c d g (e, f tắt)
        0x99, // 4 -> các đoạn b c f g (a, d, e tắt)
        0x92, // 5 -> các đoạn a c d f g (b, e tắt)
        0x82, // 6 -> các đoạn a c d e f g (b tắt)
        0xF8, // 7 -> các đoạn a b c (d, e, f, g tắt)
        0x80, // 8 -> tất cả các đoạn a b c d e f g đều sáng
        0x90  // 9 -> các đoạn a b c f g (d, e tắt)
    };

    // Thiết lập các chân GPIO tương ứng PA7 -> PA13 cho các đoạn a -> g
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (segments[num] & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Chân PA7 -> đoạn a
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, (segments[num] & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Chân PA8 -> đoạn b
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, (segments[num] & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Chân PA9 -> đoạn c
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (segments[num] & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA10 -> đoạn d
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (segments[num] & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA11 -> đoạn e
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (segments[num] & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA12 -> đoạn f
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (segments[num] & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA13 -> đoạn g
    num--;
    if (num < 0) {
    	if (green == 1) {
    		yelow = 1;
    		green = 0;
    		num = 3;
    	}
    	else if (red == 1) {
    		green = 1;
    		red = 0;
    		num = 5;
    	}
    	else if (yelow == 1) {
    		yelow = 0;
    		red = 1;
    		num = 9;
    	}
    }
}

void display_7SEG2() {
    // Mảng lưu giá trị các đoạn cho các số từ 0 đến 9
    uint8_t segments[10] = {
        0xC0, // 0 -> các đoạn a b c d e f (g tắt)
        0xF9, // 1 -> các đoạn b c (a, d, e, f, g tắt)
        0xA4, // 2 -> các đoạn a b d e g (c, f tắt)
        0xB0, // 3 -> các đoạn a b c d g (e, f tắt)
        0x99, // 4 -> các đoạn b c f g (a, d, e tắt)
        0x92, // 5 -> các đoạn a c d f g (b, e tắt)
        0x82, // 6 -> các đoạn a c d e f g (b tắt)
        0xF8, // 7 -> các đoạn a b c (d, e, f, g tắt)
        0x80, // 8 -> tất cả các đoạn a b c d e f g đều sáng
        0x90  // 9 -> các đoạn a b c f g (d, e tắt)
    };

    // Thiết lập các chân GPIO tương ứng PA7 -> PA13 cho các đoạn a -> g
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (segments[num2] & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Chân PA7 -> đoạn a
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (segments[num2] & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Chân PA8 -> đoạn b
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (segments[num2] & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Chân PA9 -> đoạn c
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (segments[num2] & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA10 -> đoạn d
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (segments[num2] & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA11 -> đoạn e
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (segments[num2] & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA12 -> đoạn f
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (segments[num2] & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Chân PA13 -> đoạn g
    num2--;
    if (num2 < 0) {
        if (num == 9) {
        	num2 = 5;
        	traffic_green(GPIOB, LED_7_Pin, LED_6_Pin, LED_5_Pin);
        	traffic_green(GPIOB, LED_1_Pin, LED_12_Pin, LED_11_Pin);
        }
        else if (num == 3) {
        	num2 = 3;
        	traffic_yelow(GPIOB, LED_7_Pin, LED_6_Pin, LED_5_Pin);
        	traffic_yelow(GPIOB, LED_1_Pin, LED_12_Pin, LED_11_Pin);
        }
        else if (num == 5) {
        	num2 = 9;
        	traffic_red(GPIOB, LED_7_Pin, LED_6_Pin, LED_5_Pin);
        	traffic_red(GPIOB, LED_1_Pin, LED_12_Pin, LED_11_Pin);
        }
    }

}
