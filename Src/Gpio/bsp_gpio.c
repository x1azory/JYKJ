/**
 * @file bsp_gpio.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bsp_gpio.h"

/**
 * @brief notice : when GPIO set mode_in, other config is not use,we just cfg it  to maintain aesthetics.
 * 
 */


GPIO_InitTypeDef Gpio_Group_B[Gpio_B_MAX] = 
{
/*   GPIO_Pin        GPIO_Speed            GPIO_Mode        */
    {GPIO_Pin_6,     GPIO_Speed_50MHz,     GPIO_Mode_Out_PP},   /* Mcu_Work_Led */
    {GPIO_Pin_9,     GPIO_Speed_50MHz,     GPIO_Mode_Out_PP},   /* KEY_Num2     */
    {GPIO_Pin_10,    GPIO_Speed_50MHz,     GPIO_Mode_Out_PP},   /* KEY_Num3     */
};



void bsp_Gpio_Init(void)
{
    uint8_t i = 0;

    /* Enable Clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |\
                           RCC_APB2Periph_GPIOB \
                           ,ENABLE);

    for(; i<Gpio_B_MAX; i++)
    {
        GPIO_Init(GPIOB,&Gpio_Group_B[i]);
    }
}


void bsp_MainFunction(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_6);
}

/**
 * @brief End of line
 * 
 */
