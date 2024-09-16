/*
 * Excersice4.c
 *
 *  Created on: Sep 13, 2024
 *      Author: MSIFPT
 */
#include "Excersice4.h"
#include "main.h"

void init_exc4() {
	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, SET);
}

void display7SEG(int num) {
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
}

