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

    bsp_MainFunction();
    
    return 0;
}


/**
 * @brief end of file
 * 
 */
