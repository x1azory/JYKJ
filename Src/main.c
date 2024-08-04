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

        if( Task_st[Task_5ms_].Task_ == 1)
        {
            bsp_Can_Transmit();
            Task_st[Task_5ms_].Task_ = 0;
        }
    }

   
}


/**
 * @brief end of file
 * 
 */
