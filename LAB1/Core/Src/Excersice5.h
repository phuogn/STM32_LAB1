/*
 * Excersice5.h
 *
 *  Created on: Sep 16, 2024
 *      Author: MSIFPT
 */

#ifndef SRC_EXCERSICE5_H_
#define SRC_EXCERSICE5_H_



#endif /* SRC_EXCERSICE5_H_ */

void traffic_red(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin);
void traffic_yelow(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin);
void traffic_green(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin);
void init_exc5();
void exc5_run();
void display_7SEG();
