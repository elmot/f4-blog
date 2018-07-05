//
// Created by elmot on 4.1.2018.
//
#include "main.h"
#include "stm32f4xx_hal.h"
#include <stdlib.h>
extern RNG_HandleTypeDef hrng;

void blinkLed() {
    uint32_t rnd = HAL_RNG_ReadLastRandomNumber(&hrng);
    HAL_RNG_GenerateRandomNumber(&hrng,&rnd);
    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, rnd & 1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, rnd & 2 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, rnd & 4 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, rnd & 8 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_Delay(100 + (rnd /16) % 200);

}
