/******************************************************************************/
/*          *** STM32F2xx (CORTEX M3) vector table ***                        */
/******************************************************************************/
#include "..\code\HardDrivers\MotorCarriage.hpp"
#include "..\code\HardDrivers\MotorLever.hpp"
#include "..\code\HardDrivers\MotorDrum.hpp"
#include "..\code\HardDrivers\Tim.hpp"

extern TMotorCarriage MotorCarriage;
extern TMotorLever MotorLever;
extern TMotorDrum MotorDrum;
extern TTim Tim;
extern "C" void __iar_program_start(void);
extern "C" void SystemInit(void);
extern unsigned char CSTACK$$Limit;

/********************* RTOS HANDLERS ******************************************/
#ifdef __FREE_RTOS
extern "C" void xPortPendSVHandler(void);
extern "C" void xPortSysTickHandler(void);
extern "C" void vPortSVCHandler(void);
#endif

/********************* SERVICE HANDLERS ***************************************/
__weak void Reset_Handler(void)
{
  SystemInit();
  __iar_program_start();
}
__weak void NMI_Handler(void)
{
  while(true) { }
};
__weak void HardFault_Handler(void)
{
  while(true) { }
};
__weak void MemManage_Handler(void)
{
  while(true) { }
};
__weak void BusFault_Handler(void)
{
  while(true) { }
};
__weak void UsageFault_Handler(void)
{
  while(true) { }
};
__weak void SVC_Handler(void)
{
  while(true) { }
}
__weak void DebugMonitor_Handler(void)
{
  while(true) { }
}
__weak void PendSV_Handler(void)
{
  while(true) { }
}
__weak void SysTick_Handler(void)
{
  while(true) { }
}

/********************** REGULAR HANDLERS **************************************/
__weak void WWDG_IRQ_Handler(void)
{
  while(true) { }
};
__weak void PVD_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TAMP_STAMP_IRQ_Handler(void)
{
  while(true) { }
};
__weak void RTC_WKUP_IRQ_Handler(void)
{
  while(true) { }
};
__weak void FLASH_IRQ_Handler(void)
{
  while(true) { }
};
__weak void RCC_IRQ_Handler(void)
{
  while(true) { }
};
__weak void EXTI0_IRQ_Handler(void)
{
  while(true) { }
};
__weak void EXTI1_IRQ_Handler(void)
{
  while(true) { }
};
__weak void EXTI2_IRQ_Handler(void)
{
  MotorDrum.IRQ_HandlerStep();
  EXTI_ClearITPendingBit(EXTI_Line2);
  //while(true) { }
};
__weak void EXTI3_IRQ_Handler(void)
{
  MotorCarriage.IRQ_HandlerStep();
  EXTI_ClearITPendingBit(EXTI_Line3);
  //while(true) { }
};
__weak void EXTI4_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream0_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream1_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream2_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream3_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream4_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream5_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream6_IRQ_Handler(void)
{
  while(true) { }
};
__weak void ADC_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN1_TX_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN1_RX0_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN1_RX1_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN1_SCE_IRQ_Handler(void)
{
  while(true) { }
};
__weak void EXTI9_5_IRQ_Handler(void)
{
  MotorLever.IRQ_HandlerStep();
  EXTI_ClearITPendingBit(EXTI_Line6);
  //while(true) { }
};
__weak void TIM1_BRK_TIM9_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM1_UP_TIM10_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM1_TRG_COM_TIM11_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM1_CC_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM2_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM3_IRQ_Handler(void)
{
  Tim.IRQ_HandlerTim3();
  //while(true) { }
};
__weak void TIM4_IRQ_Handler(void)
{
  while(true) { }
};
__weak void I2C1_EV_IRQ_Handler(void)
{
  while(true) { }
};
__weak void I2C1_ER_IRQ_Handler(void)
{
  while(true) { }
};
__weak void I2C2_EV_IRQ_Handler(void)
{
  while(true) { }
};
__weak void I2C2_ER_IRQ_Handler(void)
{
  while(true) { }
};
__weak void SPI1_IRQ_Handler(void)
{
  while(true) { }
};
__weak void SPI2_IRQ_Handler(void)
{
  while(true) { }
};
__weak void USART1_IRQ_Handler(void)
{
  while(true) { }
};
__weak void USART2_IRQ_Handler(void)
{
  while(true) { }
};
__weak void USART3_IRQ_Handler(void)
{
  while(true) { }
};
__weak void EXTI15_10_IRQ_Handler(void)
{
  MotorCarriage.IRQ_HandlerStep();
  EXTI_ClearITPendingBit(EXTI_Line15);
  //while(true) { }
};
__weak void RTC_Alarm_IRQ_Handler(void)
{
  while(true) { }
};
__weak void OTG_FS_WKUP_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM8_BRK_TIM12_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM8_UP_TIM13_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM8_TRG_COM_TIM14_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM8_CC_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA1_Stream7_IRQ_Handler(void)
{
  while(true) { }
};
__weak void FSMC_IRQ_Handler(void)
{
  while(true) { }
};
__weak void SDIO_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM5_IRQ_Handler(void)
{
  while(true) { }
};
__weak void SPI3_IRQ_Handler(void)
{
  while(true) { }
};
__weak void UART4_IRQ_Handler(void)
{
  while(true) { }
};
__weak void UART5_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM6_DAC_IRQ_Handler(void)
{
  while(true) { }
};
__weak void TIM7_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream0_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream1_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream2_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream3_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream4_IRQ_Handler(void)
{
  while(true) { }
};
__weak void ETH_IRQ_Handler(void)
{
  while(true) { }
};
__weak void ETH_WKUP_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN2_TX_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN2_RX0_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN2_RX1_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CAN2_SCE_IRQ_Handler(void)
{
  while(true) { }
};
__weak void OTG_FS_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream5_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream6_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DMA2_Stream7_IRQ_Handler(void)
{
  while(true) { }
};
__weak void USART6_IRQ_Handler(void)
{
  while(true) { }
};
__weak void I2C3_EV_IRQ_Handler(void)
{
  while(true) { }
};
__weak void I2C3_ER_IRQ_Handler(void)
{
  while(true) { }
};
__weak void OTG_HS_EP1_OUT_IRQ_Handler(void)
{
  while(true) { }
};
__weak void OTG_HS_EP1_IN_IRQ_Handler(void)
{
  while(true) { }
};
__weak void OTG_HS_WKUP_IRQ_Handler(void)
{
  while(true) { }
};
__weak void OTG_HS_IRQ_Handler(void)
{
  while(true) { }
};
__weak void DCMI_IRQ_Handler(void)
{
  while(true) { }
};
__weak void CRYP_IRQ_Handler(void)
{
  while(true) { }
};
__weak void HASH_RNG_IRQ_Handler(void)
{
  while(true) { }
};

#ifdef __STM32F407
__weak void FPU_IRQ_Handler(void)
{
  while(true) { }
};
__weak void UART7_IRQ_Handler(void)
{
  while(true) { }
};
__weak void UART8_IRQ_Handler(void)
{
  while(true) { }
};
__weak void SPI4_IRQ_Handler(void)
{
  while(true) { }
};
__weak void SPI5_IRQ_Handler(void)
{
  while(true) { }
};
__weak void SPI6_IRQ_Handler(void)
{
  while(true) { }
};
#endif

/******************************************************************************/
/*                        *** INTERRUPT TABLE ***                             */
/******************************************************************************/
__root const void * const __vector_table[97+6] @ ".intvec" =
{
  &CSTACK$$Limit,
  (void*)Reset_Handler,

  ////// CORTEX interrupts. //////
  (void*)NMI_Handler,
  (void*)HardFault_Handler,
  (void*)MemManage_Handler,
  (void*)BusFault_Handler,
  (void*)UsageFault_Handler,
  0,  // Reserved
  0,  // Reserved
  0,  // Reserved
  0,  // Reserved

#ifdef __FREE_RTOS
  (void*)vPortSVCHandler,
#else
  (void*)SVC_Handler,
#endif

  (void*)DebugMonitor_Handler,
  0,  // Reserved

#ifdef __FREE_RTOS  
  (void*)xPortPendSVHandler,     // *** Used by FTOS ***
  (void*)xPortSysTickHandler,    // *** Used by FTOS ***
#else
  (void*)PendSV_Handler,
  (void*)SysTick_Handler,
#endif

  ////// External interrupts. //////
  (void*)WWDG_IRQ_Handler,
  (void*)PVD_IRQ_Handler,
  (void*)TAMP_STAMP_IRQ_Handler,
  (void*)RTC_WKUP_IRQ_Handler,
  (void*)FLASH_IRQ_Handler,
  (void*)RCC_IRQ_Handler,
  (void*)EXTI0_IRQ_Handler,
  (void*)EXTI1_IRQ_Handler,
  (void*)EXTI2_IRQ_Handler,
  (void*)EXTI3_IRQ_Handler,
  (void*)EXTI4_IRQ_Handler,
  (void*)DMA1_Stream0_IRQ_Handler,
  (void*)DMA1_Stream1_IRQ_Handler,
  (void*)DMA1_Stream2_IRQ_Handler,
  (void*)DMA1_Stream3_IRQ_Handler,
  (void*)DMA1_Stream4_IRQ_Handler,
  (void*)DMA1_Stream5_IRQ_Handler,
  (void*)DMA1_Stream6_IRQ_Handler,
  (void*)ADC_IRQ_Handler,
  (void*)CAN1_TX_IRQ_Handler,
  (void*)CAN1_RX0_IRQ_Handler,
  (void*)CAN1_RX1_IRQ_Handler,
  (void*)CAN1_SCE_IRQ_Handler,
  (void*)EXTI9_5_IRQ_Handler,
  (void*)TIM1_BRK_TIM9_IRQ_Handler,
  (void*)TIM1_UP_TIM10_IRQ_Handler,
  (void*)TIM1_TRG_COM_TIM11_IRQ_Handler,
  (void*)TIM1_CC_IRQ_Handler,
  (void*)TIM2_IRQ_Handler,
  (void*)TIM3_IRQ_Handler,
  (void*)TIM4_IRQ_Handler,
  (void*)I2C1_EV_IRQ_Handler,
  (void*)I2C1_ER_IRQ_Handler,
  (void*)I2C2_EV_IRQ_Handler,
  (void*)I2C2_ER_IRQ_Handler,
  (void*)SPI1_IRQ_Handler,
  (void*)SPI2_IRQ_Handler,
  (void*)USART1_IRQ_Handler,
  (void*)USART2_IRQ_Handler,
  (void*)USART3_IRQ_Handler,
  (void*)EXTI15_10_IRQ_Handler,
  (void*)RTC_Alarm_IRQ_Handler,
  (void*)OTG_FS_WKUP_IRQ_Handler,
  (void*)TIM8_BRK_TIM12_IRQ_Handler,
  (void*)TIM8_UP_TIM13_IRQ_Handler,
  (void*)TIM8_TRG_COM_TIM14_IRQ_Handler,
  (void*)TIM8_CC_IRQ_Handler,
  (void*)DMA1_Stream7_IRQ_Handler,
  (void*)FSMC_IRQ_Handler,
  (void*)SDIO_IRQ_Handler,
  (void*)TIM5_IRQ_Handler,
  (void*)SPI3_IRQ_Handler,
  (void*)UART4_IRQ_Handler,
  (void*)UART5_IRQ_Handler,
  (void*)TIM6_DAC_IRQ_Handler,
  (void*)TIM7_IRQ_Handler,
  (void*)DMA2_Stream0_IRQ_Handler,
  (void*)DMA2_Stream1_IRQ_Handler,
  (void*)DMA2_Stream2_IRQ_Handler,
  (void*)DMA2_Stream3_IRQ_Handler,
  (void*)DMA2_Stream4_IRQ_Handler,
  (void*)ETH_IRQ_Handler,
  (void*)ETH_WKUP_IRQ_Handler,
  (void*)CAN2_TX_IRQ_Handler,
  (void*)CAN2_RX0_IRQ_Handler,
  (void*)CAN2_RX1_IRQ_Handler,
  (void*)CAN2_SCE_IRQ_Handler,
  (void*)OTG_FS_IRQ_Handler,
  (void*)DMA2_Stream5_IRQ_Handler,
  (void*)DMA2_Stream6_IRQ_Handler,
  (void*)DMA2_Stream7_IRQ_Handler,
  (void*)USART6_IRQ_Handler,
  (void*)I2C3_EV_IRQ_Handler,
  (void*)I2C3_ER_IRQ_Handler,
  (void*)OTG_HS_EP1_OUT_IRQ_Handler,
  (void*)OTG_HS_EP1_IN_IRQ_Handler,
  (void*)OTG_HS_WKUP_IRQ_Handler,
  (void*)OTG_HS_IRQ_Handler,
  (void*)DCMI_IRQ_Handler,
  (void*)CRYP_IRQ_Handler,
  (void*)HASH_RNG_IRQ_Handler,
  
#ifdef __STM32F407
  (void*)FPU_IRQ_Handler,
  (void*)UART7_IRQ_Handler,
  (void*)UART8_IRQ_Handler,
  (void*)SPI4_IRQ_Handler,
  (void*)SPI5_IRQ_Handler,
  (void*)SPI6_IRQ_Handler
#endif
    
};
/******************************************************************************/

