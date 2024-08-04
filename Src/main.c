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

#include "bsp.h"


int main(void)
{
    bsp_vInit();

    while (1)
    {
        bsp_vMainFunction();

        if(Mcu_Tick==5000)
        {
            bsp_Can_Transmit();
        }
    }

   
}


/**
 * @brief end of file
 * 
 */
