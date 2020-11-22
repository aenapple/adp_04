/**********************************************************************************/
/**
*  @file
*  MotorLockDrum.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MotorLockDrum.hpp"


TMotorLockDrum MotorLockDrum;
/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLockDrum::IRQ_HandlerStep(void)
{
  
}
//--- end IRQ_HandlerStep ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLockDrum::StartForward(unsigned char pwm)
{
  this->SetIdlingMode();
  GPIO_SetBits(GPIOB, GPIO_Pin_5);
}
//--- end StartForward -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLockDrum::StartBackward(unsigned char pwm)
{
  this->SetIdlingMode();
  GPIO_SetBits(GPIOB, GPIO_Pin_7);
}
//--- end StartBackward ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .`
*
*  @return ... .
*/
void TMotorLockDrum::Stop(void)
{
  GPIO_SetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_7);
}
//--- end Stop ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .`
*
*  @return ... .
*/
void TMotorLockDrum::SetIdlingMode(void)
{
  this->Delay(10);
  GPIO_ResetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_7);
  this->Delay(10);
}
//--- end SetIdlingMode ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMotorLockDrum::GetStateLockSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_9) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateLockSensor -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMotorLockDrum::GetStateUnlockSensor(void)
{
  if(GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_10) == Bit_SET) return(SystemStatus_SensorIsOff);
  
  return(SystemStatus_SensorIsOn);
}
//--- end GetStateUnlockSensor -----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotorLockDrum::SetPosition(unsigned char position)
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
unsigned char TMotorLockDrum::GetPosition(void)
{
  return(this->position);
}
//--- end GetPosition --------------------------------------------------------------

/**********************************************************************************/
