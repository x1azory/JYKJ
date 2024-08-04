/**
 * @file bsp.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bsp_gpio.h"
#include "bsp_can.h"
#include "core_cm3.h"
#include "stm32f10x_it.h"

typedef enum
{
    Task_5ms_ = 0,
    Task_10ms_,
    Task_Tol,
}Task_ten;


typedef struct 
{
    uint8_t Task_;
    uint32_t Period;
}Task_tst;

extern Task_tst Task_st[Task_Tol];
extern void bsp_vInit(void);
extern void bsp_vMainFunction(void);


/**
 * @brief End of files
 * 
 */
