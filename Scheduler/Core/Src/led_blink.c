/*
 * led_blink.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Admin
 */

#include "led_blink.h"
#include "main.h"

void init_LED() {
	HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PURPLE_GPIO_Port, PURPLE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET);
}
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
