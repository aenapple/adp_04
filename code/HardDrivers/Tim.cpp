/**********************************************************************************/
/**
*  @file
*  Tim.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Tim.hpp"
#include "Gpio.hpp"


TTim Tim;
extern TGpio Gpio;
/**********************************************************************************/



/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::Init(void)
{
  Tim.InitTim3();
  Tim.InitTim4();

}
//--- end Init ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::IRQ_HandlerTim3(void)
{
  this->StopTim3();
  
  this->GiveScanDrumSemaphoreFromIsr();

}
//--- end IRQ_HandlerTim3 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::StopTim3(void)
{
  TIM_ClearFlag(TIM3, TIM_FLAG_Update);         //Must first clear configuration the update flag
  TIM_ITConfig(TIM3, TIM_IT_Update, DISABLE);  //Enable interrupt, timer interrupt events - Events

  TIM_Cmd(TIM3, DISABLE);
  
  // DEBUG
  //Gpio.TurnOffScanLed();
  // DEBUG
}
//--- end StopTim3 -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::StartTim3(unsigned short time)
{
  TIM3_TimeBaseInitStructure.TIM_Period= time * 10;   // time in mSeconds
  TIM_TimeBaseInit(TIM3, &TIM3_TimeBaseInitStructure);
  
  TIM_ClearFlag(TIM3, TIM_FLAG_Update);       //Must first clear configuration the update flag
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);  //Enable interrupt, timer interrupt events - Events
  
  //this->TakeScanDrumSemaphore(0);
  TIM_Cmd(TIM3, ENABLE);

}
//--- end StartTim3 ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::InitTim3(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  TIM_DeInit(TIM3);
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  
  // Enable the TIM3 global Interrupt. //
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  TIM3_TimeBaseInitStructure.TIM_ClockDivision= TIM_CKD_DIV1;
  TIM3_TimeBaseInitStructure.TIM_CounterMode= TIM_CounterMode_Up;
  TIM3_TimeBaseInitStructure.TIM_Period= 100;
  TIM3_TimeBaseInitStructure.TIM_Prescaler= 8400;
  TIM_TimeBaseInit(TIM3, &TIM3_TimeBaseInitStructure);
  
  
  this->semaphoreScanDrum= this->CreateSemaphore();
  
  //TIM_Cmd(TIM3, ENABLE);
  
}
//--- end InitTim3 -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::InitTim4(void)
{
  TIM_DeInit(TIM4);
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  TIM4_TimeBaseInitStructure.TIM_ClockDivision= TIM_CKD_DIV1;
  TIM4_TimeBaseInitStructure.TIM_CounterMode= TIM_CounterMode_Up;
  TIM4_TimeBaseInitStructure.TIM_Period= 100;
  TIM4_TimeBaseInitStructure.TIM_Prescaler= 40;
  TIM_TimeBaseInit(TIM4, &TIM4_TimeBaseInitStructure);
  
}
//--- end InitTim4 -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::StartTim4(EModeTim4 mode, unsigned char pwm)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  
  ////// Init output TIM4-pins PB-port. //////
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  switch(mode)
  {
    case ModeTim4_StartOc1:
      GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4); // PB6/TIM4-CH1 - MT0F.
      GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;
      break;
    
    case ModeTim4_StartOc2:
      GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4); // PB7/TIM4-CH2 - MT1F.
      GPIO_InitStructure.GPIO_Pin =GPIO_Pin_7;
      break;
      
    case ModeTim4_StartOc3:
      GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM4); // PB8/TIM4-CH3 - MT2F.
      GPIO_InitStructure.GPIO_Pin =GPIO_Pin_8;
      break;
      
    case ModeTim4_StartOc4:
      GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4); // PB9/TIM4-CH4 - MT3F.
      GPIO_InitStructure.GPIO_Pin =GPIO_Pin_9;
      break;
      
  }
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  
  // Output PWM configuration. //
  TIM4_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM4_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM4_OCInitStructure.TIM_Pulse = pwm;  // 50%
  TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  
  switch(mode)
  {
    case ModeTim4_StartOc1:
      TIM_OC1Init(TIM4, &TIM4_OCInitStructure);
      TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
      break;
    
    case ModeTim4_StartOc2:
      TIM_OC2Init(TIM4, &TIM4_OCInitStructure);
      TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
      break;
      
    case ModeTim4_StartOc3:
      TIM_OC3Init(TIM4, &TIM4_OCInitStructure);
      TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
      break;
      
    case ModeTim4_StartOc4:
      TIM_OC4Init(TIM4, &TIM4_OCInitStructure);
      TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
      break;
      
  }
  

  TIM_Cmd(TIM4, ENABLE);
  
}
//--- end StartTim4 ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::StopTim4(EModeTim4 mode)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  TIM_Cmd(TIM4, DISABLE);
  
  ////// Init output TIM4-pins PB-port. //////
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  switch(mode)
  {
    case ModeTim4_StopOc1Level0:
    case ModeTim4_StopOc1Level1:
      GPIO_InitStructure.GPIO_Pin= GPIO_Pin_6;
      break;
    
    case ModeTim4_StopOc2Level0:
    case ModeTim4_StopOc2Level1:
      GPIO_InitStructure.GPIO_Pin= GPIO_Pin_7;
      break;
      
    case ModeTim4_StopOc3Level0:
    case ModeTim4_StopOc3Level1:
      GPIO_InitStructure.GPIO_Pin= GPIO_Pin_8;
      break;
      
    case ModeTim4_StopOc4Level0:
    case ModeTim4_StopOc4Level1:
      GPIO_InitStructure.GPIO_Pin= GPIO_Pin_9;
      break;
      
  }
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  switch(mode)
  {
    case ModeTim4_StopOc1Level0: GPIO_ResetBits(GPIOB, GPIO_Pin_6); break;
    case ModeTim4_StopOc1Level1: GPIO_SetBits(GPIOB, GPIO_Pin_6); break;
    
    case ModeTim4_StopOc2Level0: GPIO_ResetBits(GPIOB, GPIO_Pin_7); break;
    case ModeTim4_StopOc2Level1: GPIO_SetBits(GPIOB, GPIO_Pin_7); break;
    
    case ModeTim4_StopOc3Level0: GPIO_ResetBits(GPIOB, GPIO_Pin_8); break;
    case ModeTim4_StopOc3Level1: GPIO_SetBits(GPIOB, GPIO_Pin_8); break;
    
    case ModeTim4_StopOc4Level0: GPIO_ResetBits(GPIOB, GPIO_Pin_9); break;
    case ModeTim4_StopOc4Level1: GPIO_SetBits(GPIOB, GPIO_Pin_9); break;
      
  }
  
}
//--- end StopTim4 -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
SemaphoreHandle_t TTim::GetHandleSemaphoreScanDrum(void)
{
  return(this->semaphoreScanDrum);
}
//--- end GetHandleSemaphoreScanDrum -----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TTim::TakeScanDrumSemaphore(unsigned short timeOut)
{
  return(this->TakeSemaphore(this->semaphoreScanDrum, timeOut));
}
//--- end TakeScanDrumSemaphore ----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::GiveScanDrumSemaphore(void)
{
  this->GiveSemaphore(this->semaphoreScanDrum);
}
//--- end GiveScanDrumSemaphore ----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TTim::GiveScanDrumSemaphoreFromIsr(void)
{
  this->GiveSemaphoreFromIsr(this->semaphoreScanDrum);
}
//--- end GiveScanDrumSemaphoreFromIsr ---------------------------------------------

/**********************************************************************************/
