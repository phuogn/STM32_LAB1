/*
 * Excersice10.c
 *
 *  Created on: Sep 18, 2024
 *      Author: MSIFPT
 */
#include "Excersice10.h"
#include "main.h"

void displayClock(int hour, int minute, int second) {
    // Tắt tất cả các LED trước
    for (int pin = 0; pin <= 11; pin++) {
        HAL_GPIO_WritePin(GPIOB, (1 << pin), GPIO_PIN_RESET);  // Tắt tất cả LED
    }

    // Tính toán vị trí của đèn LED cho giờ, phút, giây
    int hourPos = hour % 12;      // Vị trí của LED tương ứng với giờ
    int minutePos = minute / 5;   // Chia phút thành các khoảng 5 phút
    int secondPos = second / 5;   // Chia giây thành các khoảng 5 giây

    // Bật LED tương ứng với giờ, phút và giây
    HAL_GPIO_WritePin(GPIOB, (1 << hourPos), GPIO_PIN_SET);    // Bật LED cho giờ
    HAL_GPIO_WritePin(GPIOB, (1 << minutePos), GPIO_PIN_SET);  // Bật LED cho phút
    HAL_GPIO_WritePin(GPIOB, (1 << secondPos), GPIO_PIN_SET);  // Bật LED cho giây
}
