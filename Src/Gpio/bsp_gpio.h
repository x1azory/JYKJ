/**
 * @file bsp_gpio.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BSP_GPIO_H
#define BSP_GPIO_H

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_it.h"

typedef enum
{
    Can_Tx_Pin = 0,
    Can_Rx_Pin,
    Can_Standby_Pin,
    Gpio_A_MAX
}Gpio_A_Type;

typedef enum
{
    Mcu_Work_Led = 0,
    KEY_Num2,
    KEY_Num3,
    Gpio_B_MAX
}Gpio_B_ten;

extern void bsp_Gpio_Init(void);
extern void Gpio_vMainFunction(void);

#endif
/**
 * @brief End of Line
 * 
 */
