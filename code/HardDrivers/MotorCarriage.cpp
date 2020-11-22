/**********************************************************************************/
/**
*  @file
*  MotorCarriage.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MotorCarriage.hpp"
#include "Tim.hpp"

TMotorCarriage MotorCarriage;
extern TTim Tim;
/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMotorCarriage::TMotorCarriage(void)
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
void TMotorCarriage::IRQ_HandlerStep(void)
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
void TMotorCarriage::StartForward(unsigned char pwm)
{
  this->SetIdlingMode();
  
  Tim.StartTim4(ModeTim4_StartOc3, (100 - pwm));
  GPIO_ResetBits(GPIOB, GPIO_Pin_0);
  
  this->stepCounter= 0;
}
//--- end StartForward -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorCarriage::StartBackward(unsigned char pwm)
{
  this->SetIdlingMode();
  
  Tim.StartTim4(ModeTim4_StartOc3, pwm);
  GPIO_SetBits(GPIOB, GPIO_Pin_0);
  
  this->stepCounter= 0;
}
//--- end StartBackward ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .`
*
*  @return ... .
*/
void TMotorCarriage::Stop(void)
{
  Tim.StopTim4(ModeTim4_StopOc3Level1);
  GPIO_SetBits(GPIOB, GPIO_Pin_0);
}
//--- end Stop ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorCarriage::SetupNewSpeed(unsigned char pwm)
{

}
//--- end SetupNewSpeed ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .`
*
*  @return ... .
*/
void TMotorCarriage::SetIdlingMode(void)
{
  this->Delay(10);
  Tim.StopTim4(ModeTim4_StopOc3Level0);
  GPIO_ResetBits(GPIOB, GPIO_Pin_0);
  this->Delay(10);
}
//--- end Stop ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorCarriage::IncrementStepCounter(void)
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
unsigned short TMotorCarriage::GetStepCounter(void)
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
ESystemStatus TMotorCarriage::GetStateStartPositionSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_8) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateStartPositionSensor ----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMotorCarriage::GetStateEndPositionSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_9) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateEndPositionSensor ------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMotorCarriage::GetStateLengthCassetteSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateLengthCassetteSensor ---------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
SemaphoreHandle_t TMotorCarriage::GetHandleSemaphoreStep(void)
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
ESystemStatus TMotorCarriage::TakeStepSemaphore(unsigned short timeOut)
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
void TMotorCarriage::GiveStepSemaphore(void)
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
void TMotorCarriage::GiveStepSemaphoreFromIsr(void)
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
void TMotorCarriage::SetPosition(unsigned char position)
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
unsigned char TMotorCarriage::GetPosition(void)
{
  return(this->position);
}
//--- end GetPosition --------------------------------------------------------------

/**********************************************************************************/
