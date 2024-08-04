/**
 * @file bsp_can.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bsp_can.h"

/**
 * @brief bxCAN from APB1
 * 
 */
CAN_InitTypeDef Can_Init_st = 
{
    /*.CAN_Prescaler = */9,
    /*.CAN_Mode      = */CAN_Mode_Normal,
    /*.CAN_SJW       = */CAN_SJW_1tq,
    /*.CAN_BS1       = */CAN_BS1_6tq,
    /*.CAN_BS2       = */CAN_BS2_1tq,  
    /*.CAN_TTCM      = */DISABLE,    
    /*.CAN_ABOM      = */DISABLE,    
    /*.CAN_AWUM      = */DISABLE,    
    /*.CAN_NART      = */DISABLE,    
    /*.CAN_RFLM      = */DISABLE,    
    /*.CAN_TXFP      = */DISABLE
};

void bsp_can_vInit(void)
{
    CAN_DeInit(CAN1);
    /* standby pin low */
    bsp_can_Set_Mode(COMM_ON);
    /* clock enbale */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1,ENABLE);
    /* AF may not necessary */

    /* cAN Init */
    CAN_Init(CAN1,&Can_Init_st);

    /* Interrupt enable */
    CAN_NVIC_Configuration();
    CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);
}

void CAN_NVIC_Configuration(void) 
{
    NVIC_InitTypeDef NVIC_InitStructure;
  	/* Configure the NVIC Preemption Priority Bits */ 
  	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	/* enabling interrupt */
  	NVIC_InitStructure.NVIC_IRQChannel=USB_LP_CAN1_RX0_IRQn;;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  	NVIC_Init(&NVIC_InitStructure);
}


void bsp_can_Set_Mode(Can_Mode_ten mode)
{
    if(COMM_ON == mode)
    {
        /* PA8 pull down, then can standby enable */
        GPIO_WriteBit(GPIOA,GPIO_Pin_8,Bit_RESET);
    }
    else
    {
        GPIO_WriteBit(GPIOA,GPIO_Pin_8,Bit_SET);
    }
}


void bsp_Can_Transmit(void)
{
    static CanTxMsg Msg_A  = {0x132,0,CAN_ID_STD,CAN_RTR_Data,8,1,2,3,4,5,6,7,8};
    Msg_A.Data[1]++;
    CAN_Transmit(CAN1,&Msg_A);
}

CanRxMsg can_rx_msg;
void CAN1_RX1_IRQHandler(void)
{
    CAN_Receive(CAN1,CAN_FIFO0,&can_rx_msg);
}

/**
 * @brief End
 * 
 */
