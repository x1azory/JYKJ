/**
 * @file bsp.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bsp.h"


/**
 * @brief mcu pll clock is 72M
 * 
 */

#define MCU_1MS   (72 * 1000000 / 1000)

void SysTick_Init(void)
{
    uint32_t u32tick = MCU_1MS;
    SysTick_Config(u32tick);
}

void bsp_vInit(void)
{
	SysTick_Init();
    bsp_Gpio_Init();
    bsp_can_vInit();

}

void bsp_vMainFunction(void)
{
    Gpio_vMainFunction();
}

/**
 * @brief End of Files
 * 
 */
