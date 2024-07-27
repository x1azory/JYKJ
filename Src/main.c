/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bsp_gpio.h"

int main(void)
{
    bsp_Gpio_Init();

		while (1)
		{
			bsp_MainFunction();
		}

   
}


/**
 * @brief end of file
 * 
 */
