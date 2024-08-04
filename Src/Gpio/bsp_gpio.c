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

GPIO_InitTypeDef Gpio_Group_A[Gpio_A_MAX] = 
{
    /*   GPIO_Pin        GPIO_Speed            GPIO_Mode        */
    {GPIO_Pin_12,     GPIO_Speed_50MHz,     GPIO_Mode_AF_PP      },   /* Can_Tx_Pin      */
    {GPIO_Pin_11,     GPIO_Speed_50MHz,     GPIO_Mode_IPU},           /* Can_Rx_Pin      */
    {GPIO_Pin_8,      GPIO_Speed_50MHz,     GPIO_Mode_Out_PP     },   /*Can_Standby_Pin  */
};


GPIO_InitTypeDef Gpio_Group_B[Gpio_B_MAX] = 
{
/*   GPIO_Pin        GPIO_Speed            GPIO_Mode        */
    {GPIO_Pin_6,     GPIO_Speed_50MHz,     GPIO_Mode_Out_PP     },   /* Mcu_Work_Led */
    {GPIO_Pin_2,     GPIO_Speed_50MHz,     GPIO_Mode_IPD},           /* KEY_Num2     */
    /*{GPIO_Pin_10,    GPIO_Speed_50MHz,     GPIO_Mode_IN_FLOATING}, */  /* KEY_Num3     */
};



void bsp_Gpio_Init(void)
{
    uint8_t i = 0;

    /* Enable Clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |\
                           RCC_APB2Periph_GPIOB \
                           ,ENABLE);

    for(; i<Gpio_A_MAX; i++)
    {
        GPIO_Init(GPIOA,&Gpio_Group_A[i]);
    }

    for(i = 0; i<Gpio_B_MAX; i++)
    {
        GPIO_Init(GPIOB,&Gpio_Group_B[i]);
    }
    
}


void Gpio_vMainFunction(void)
{
    if(Mcu_Tick%10000<1000)
    {
        GPIO_SetBits(GPIOB,GPIO_Pin_6);
    }
    else
    {
        GPIO_ResetBits(GPIOB,GPIO_Pin_6);
    }
}

/**
 * @brief End of line
 * 
 */
