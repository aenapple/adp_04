/**********************************************************************************/
/**
*  @file
*  MotorDrum.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MotorDrum.hpp"
#include "Tim.hpp"


TMotorDrum MotorDrum;
extern TTim Tim;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMotorDrum::TMotorDrum(void)
{
  this->semaphoreStep= this->CreateSemaphore();
}
//--- end TMotorDrum ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorDrum::IRQ_HandlerStep(void)
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
void TMotorDrum::StartForward(unsigned char pwm)
{
  this->SetIdlingMode();
  
  Tim.StartTim4(ModeTim4_StartOc1, pwm);
  GPIO_SetBits(GPIOB, GPIO_Pin_4);
  
  this->stepCounter= 0;
}
//--- end StartForward -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorDrum::StartBackward(unsigned char pwm)
{
  this->SetIdlingMode();
  
  Tim.StartTim4(ModeTim4_StartOc1, (100 - pwm));
  GPIO_ResetBits(GPIOB, GPIO_Pin_4);
  
  this->stepCounter= 0;
}
//--- end StartBackward ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorDrum::Stop(void)
{
  Tim.StopTim4(ModeTim4_StopOc1Level1);
  GPIO_SetBits(GPIOB, GPIO_Pin_4);
}
//--- end Stop ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .`
*
*  @return ... .
*/
void TMotorDrum::SetIdlingMode(void)
{
  this->Delay(10);
  Tim.StopTim4(ModeTim4_StopOc1Level0);
  GPIO_ResetBits(GPIOB, GPIO_Pin_4);
  this->Delay(10);
}
//--- end SetIdlingMode ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorDrum::IncrementStepCounter(void)
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
unsigned short TMotorDrum::GetStepCounter(void)
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
ESystemStatus TMotorDrum::GetStateHome1PositionSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_11) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateHome1PositionSensor ----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMotorDrum::GetStateHome2PositionSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_12) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateHome2PositionSensor ----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorDrum::SetPosition(unsigned char position)
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
unsigned char TMotorDrum::GetPosition(void)
{
  return(this->position);
}
//--- end GetPosition --------------------------------------------------------------

/**********************************************************************************/
