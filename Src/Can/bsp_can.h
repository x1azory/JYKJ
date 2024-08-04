/**
 * @file bsp_can.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bsp_gpio.h"
#include "stm32f10x_can.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_it.h"
#include "misc.h"

typedef enum
{
    COMM_ON = 0,
    COMM_OFF
}Can_Mode_ten;



extern void bsp_can_Set_Mode(Can_Mode_ten mode);
extern void CAN_NVIC_Configuration(void) ;
extern void bsp_can_vInit(void);
extern void bsp_Can_Transmit(void);
/**
 * @brief End
 * 
 */
