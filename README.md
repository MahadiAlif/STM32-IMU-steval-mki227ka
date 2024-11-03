# STM32 IMU Project with STEVAL-MKI227KA

This project demonstrates SPI communication between an STM32F427IIH6 microcontroller and the **STEVAL-MKI227KA** evaluation board, which contains the **LSM6DSV16X** 6-axis IMU (Inertial Measurement Unit). The project reads data from the IMU, starting with the `WHO_AM_I` register to verify communication, and includes functions to read and write to other registers on the sensor.

## Table of Contents
- [Project Overview](#project-overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Cloning the Repository](#cloning-the-repository)
  - [Building and Flashing](#building-and-flashing)
- [Usage](#usage)
- [License](#license)

## Project Overview

The purpose of this project is to establish SPI communication between the STM32 microcontroller and the LSM6DSV16X IMU to read sensor data. The code includes the following functionalities:
- Initialization of SPI4 for communication with the IMU
- Functions for reading and writing to IMU registers
- Verifying connection by reading the `WHO_AM_I` register

## Hardware Requirements

- **STM32F427IIH6** microcontroller (or compatible STM32 board)
- **STEVAL-MKI227KA** evaluation board with LSM6DSV16X IMU
- SPI connections:
  - **SCK**: PB3 (SPI1_SCK)
  - **MISO**: PB4 (SPI1_MISO)
  - **MOSI**: PB5 (SPI1_MOSI)
  - **CS**: PC3 (Chip Select)
- Optional: LED or UART for status indication

## Software Requirements

- **STM32CubeIDE** (Version 1.16.1 or compatible)
- **STM32CubeMX** (Version 1.16.1 or compatible)
- **arm-none-eabi-gcc** compiler for building the project
- **Git** for version control

## Project Structure

```plaintext
STM32-IMU-steval-mki227ka/
├── Core/
│   ├── Inc/
│   │   ├── main.h              # Main header file
│   │   ├── imu_driver.h        # Header file for IMU driver functions
│   ├── Src/
│   │   ├── main.c              # Main application code
│   │   ├── imu_driver.c        # IMU driver code for SPI communication
├── Drivers/
│   ├── CMSIS/                  # CMSIS files for STM32F4
│   ├── STM32F4xx_HAL_Driver/   # HAL driver files for STM32F4
└── README.md                   # Project documentation
