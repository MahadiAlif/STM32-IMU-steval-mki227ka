/*
 * imu_driver.h
 *
 *  Created on: Nov 3, 2024
 *      Author: User
 */
#ifndef IMU_DRIVER_H
#define IMU_DRIVER_H

#include "stm32f4xx_hal.h"  // Adjust to your STM32 series header
#include <stdint.h>


extern SPI_HandleTypeDef hspi4;
// Define any constants and register addresses for LSM6DSV16X
#define LSM6DSV16X_WHO_AM_I     0x0F
#define WHO_AM_I_RESPONSE       0x6C  // Expected value from WHO_AM_I register

// Function prototypes for reading and writing registers
void LSM6DSV16X_WriteReg(uint8_t reg, uint8_t data);
uint8_t LSM6DSV16X_ReadReg(uint8_t reg);

#endif // IMU_DRIVER_H
