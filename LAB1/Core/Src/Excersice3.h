/*
 * Excersice3.h
 *
 *  Created on: Sep 11, 2024
 *      Author: MSIFPT
 */

#ifndef SRC_EXCERSICE3_H_
#define SRC_EXCERSICE3_H_



#endif /* SRC_EXCERSICE3_H_ */

void control_traffic_red(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin);
void control_traffic_yelow(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin);
void control_traffic_green(GPIO_TypeDef* GPIOx, uint16_t green_pin, uint16_t yellow_pin, uint16_t red_pin);
void init_exc3();
void exc3_run();
