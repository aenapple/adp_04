/**********************************************************************************/
/**
*  @file
*  MotorLever.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MotorLever.hpp"
#include "Tim.hpp"

TMotorLever MotorLever;
extern TTim Tim;
/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMotorLever::TMotorLever(void)
{
  this->semaphoreStep= this->CreateSemaphore();
}
//--- end TMotorCarriage -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLever::IRQ_HandlerStep(void)
{
  this->GiveStepSemaphoreFromIsr();
  this->IncrementStepCounter();
}
//--- end IRQ_HandlerStep ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLever::StartForward(unsigned char pwm)
{
  this->SetIdlingMode();
  
  Tim.StartTim4(ModeTim4_StartOc4, pwm);
  GPIO_SetBits(GPIOB, GPIO_Pin_1);
  
  this->direction= 1;
  this->stepCounter= 0;

}
//--- end StartForward -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLever::StartBackward(unsigned char pwm)
{
  this->SetIdlingMode();
  
  Tim.StartTim4(ModeTim4_StartOc4, (100 - pwm));
  GPIO_ResetBits(GPIOB, GPIO_Pin_1);
  
  this->direction= 0;
  this->stepCounter= 0;

}
//--- end StartBackward ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .`
*
*  @return ... .
*/
void TMotorLever::Stop(void)
{
  Tim.StopTim4(ModeTim4_StopOc4Level1);
  GPIO_SetBits(GPIOB, GPIO_Pin_1);
}
//--- end Stop ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .`
*
*  @return ... .
*/
void TMotorLever::SetIdlingMode(void)
{
  this->Delay(10);
  Tim.StopTim4(ModeTim4_StopOc4Level0);
  GPIO_ResetBits(GPIOB, GPIO_Pin_1);
  this->Delay(10);
}
//--- end Stop ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLever::IncrementStepCounter(void)
{
  this->stepCounter++;
}
//--- end IncrementStepCounter -----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned short TMotorLever::GetStepCounter(void)
{
  return(this->stepCounter);
}
//--- end GetStepCounter -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMotorLever::GetStateStartPositionSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_7) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateStartPositionSensor ----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
SemaphoreHandle_t TMotorLever::GetHandleSemaphoreStep(void)
{
  return(this->semaphoreStep);
}
*/
//--- end GetHandleSemaphoreStep ----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
ESystemStatus TMotorLever::TakeStepSemaphore(unsigned short timeOut)
{
  return(this->TakeSemaphore(this->semaphoreStep, timeOut));
}
*/
//--- end TakeStepSemaphore ---------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
void TMotorLever::GiveStepSemaphore(void)
{
  this->GiveSemaphore(this->semaphoreStep);
}
*/
//--- end GiveStepSemaphore ---------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
void TMotorLever::GiveStepSemaphoreFromIsr(void)
{
  if(this->flagStart > 0) this->GiveSemaphoreFromIsr(this->semaphoreStep);
}
*/
//--- end GiveStepSemaphoreFromIsr --------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLever::SetPosition(unsigned char position)
{
  this->position= position;
}
//--- end SetPosition --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TMotorLever::GetPosition(void)
{
  return(this->position);
}
//--- end GetPosition --------------------------------------------------------------

/**********************************************************************************/
