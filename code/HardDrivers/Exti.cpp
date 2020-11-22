/**********************************************************************************/
/**
*  @file
*  Exti.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Exti.hpp"


TExti Exti;
/**********************************************************************************/


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TExti::Init(void)
{
  EXTI_InitTypeDef EXTI_InitStruct;
  NVIC_InitTypeDef NVIC_InitStruct;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  ////// PB3-STEP_COS is connected to EXTI_Line0. //////
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource3);
  
  EXTI_InitStruct.EXTI_Line= EXTI_Line3;
  EXTI_InitStruct.EXTI_LineCmd= ENABLE;            // Enable interrupt.
  EXTI_InitStruct.EXTI_Mode= EXTI_Mode_Interrupt;  // Interrupt mode.
  EXTI_InitStruct.EXTI_Trigger= EXTI_Trigger_Rising_Falling;
  EXTI_Init(&EXTI_InitStruct);                     // Add to EXTI.
 
  NVIC_InitStruct.NVIC_IRQChannel= EXTI3_IRQn;              // PB3-STEP_COS is connected to EXTI_Line3, which has EXTI3_IRQn vector.
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority= 0x01;  // Set priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelSubPriority= 0x00;         // Set sub priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;              // Enable interrupt.
  NVIC_Init(&NVIC_InitStruct);                              // Add to NVIC.
  
  ////// PA15-STEP_SIN is connected to EXTI_Line15. //////
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource15);
  
  EXTI_InitStruct.EXTI_Line= EXTI_Line15;
  //EXTI_InitStruct.EXTI_LineCmd= ENABLE;            // Enable interrupt.
  //EXTI_InitStruct.EXTI_Mode= EXTI_Mode_Interrupt;  // Interrupt mode.
  //EXTI_InitStruct.EXTI_Trigger= EXTI_Trigger_Rising_Falling;
  EXTI_Init(&EXTI_InitStruct);                       // Add to EXTI.
 
  NVIC_InitStruct.NVIC_IRQChannel= EXTI15_10_IRQn;          // PA15-STEP_SIN is connected to EXTI_Line15, which has EXTI15_10_IRQn vector.
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority= 0x01;  // Set priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelSubPriority= 0x01;         // Set sub priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;              // Enable interrupt.
  NVIC_Init(&NVIC_InitStruct);                              // Add to NVIC.
  
  ////// PA2 - DRUM_OPT(step) is connected to EXTI_Line2. //////
  EXTI_InitStruct.EXTI_Line= EXTI_Line2;
  //EXTI_InitStruct.EXTI_LineCmd= ENABLE;            // Enable interrupt.
  //EXTI_InitStruct.EXTI_Mode= EXTI_Mode_Interrupt;  // Interrupt mode.
  EXTI_InitStruct.EXTI_Trigger= EXTI_Trigger_Rising;
  EXTI_Init(&EXTI_InitStruct);                       // Add to EXTI.
 
  NVIC_InitStruct.NVIC_IRQChannel= EXTI2_IRQn;          // PA15-STEP_SIN is connected to EXTI_Line15, which has EXTI15_10_IRQn vector.
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority= 0x01;  // Set priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelSubPriority= 0x02;         // Set sub priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;              // Enable interrupt.
  NVIC_Init(&NVIC_InitStruct);                              // Add to NVIC.
  
  ////// PF6-LEVER_STEP is connected to EXTI_Line6. //////
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOF, EXTI_PinSource6);
  
  EXTI_InitStruct.EXTI_Line= EXTI_Line6;
  //EXTI_InitStruct.EXTI_LineCmd= ENABLE;            // Enable interrupt.
  //EXTI_InitStruct.EXTI_Mode= EXTI_Mode_Interrupt;  // Interrupt mode.
  EXTI_InitStruct.EXTI_Trigger= EXTI_Trigger_Rising_Falling;
  EXTI_Init(&EXTI_InitStruct);                       // Add to EXTI.
  
  NVIC_InitStruct.NVIC_IRQChannel= EXTI9_5_IRQn;            // PF6-LEVER_STEP is connected to EXTI_Line6, which has EXTI6_IRQn vector.
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority= 0x01;  // Set priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelSubPriority= 0x03;         // Set sub priority - can be 0..15.
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;              // Enable interrupt.
  NVIC_Init(&NVIC_InitStruct);                              // Add to NVIC.
  
}
//--- end Init ---------------------------------------------------------------------



/**********************************************************************************/
