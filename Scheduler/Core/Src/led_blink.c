/*
 * led_blink.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Admin
 */

#include "led_blink.h"
#include "main.h"

void blink_GREEN(void) {
	HAL_GPIO_TogglePin(GREEN_GPIO_Port, GREEN_Pin);
}
void blink_PURPLE(void) {
	HAL_GPIO_TogglePin(PURPLE_GPIO_Port, PURPLE_Pin);
}
void blink_RED(void) {
	HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
}
void blink_WHITE(void) {
	HAL_GPIO_TogglePin(WHITE_GPIO_Port, WHITE_Pin);
}
void blink_YELLOW(void) {
	HAL_GPIO_TogglePin(YELLOW_GPIO_Port, YELLOW_Pin);
}
