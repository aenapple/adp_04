/**********************************************************************************/
/**
*  @file
*  Motor.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Motor.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
SemaphoreHandle_t TMotor::GetHandleSemaphoreStep(void)
{
  return(this->semaphoreStep);
}
//--- end GetHandleSemaphoreStep ---------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMotor::TakeStepSemaphore(unsigned short timeOut)
{
  return(this->TakeSemaphore(this->semaphoreStep, timeOut));
}
//--- end TakeStepSemaphore --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotor::GiveStepSemaphore(void)
{
  this->GiveSemaphore(this->semaphoreStep);
}
//--- end GiveStepSemaphore --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMotor::GiveStepSemaphoreFromIsr(void)
{
  this->GiveSemaphoreFromIsr(this->semaphoreStep);
}
//--- end GiveStepSemaphoreFromIsr -------------------------------------------------

/**********************************************************************************/
