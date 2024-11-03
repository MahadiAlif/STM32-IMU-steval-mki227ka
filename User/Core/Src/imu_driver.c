/*
 * imu_driver.c
 *
 *  Created on: Nov 3, 2024
 *      Author: User
 */

/* USER CODE BEGIN 4 */
#include "imu_driver.h"  // Include your header file
#include <stdint.h>       // For uint8_t and other fixed-width integer types
#include "stm32f4xx_hal.h"

// Write to LSM6DSV16X Register
void LSM6DSV16X_WriteReg(uint8_t reg, uint8_t data)
{
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET); // CS Low
    uint8_t txData[2] = { reg & 0x7F, data }; // Write command
    HAL_SPI_Transmit(&hspi4, txData, 2, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET); // CS High
}

// Read from LSM6DSV16X Register
uint8_t LSM6DSV16X_ReadReg(uint8_t reg)
{
    uint8_t txData = reg | 0x80; // Read command
    uint8_t rxData = 0;
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET); // CS Low
    HAL_SPI_Transmit(&hspi4, &txData, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi4, &rxData, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET); // CS High
    return rxData;
}

/* USER CODE END 4 */



