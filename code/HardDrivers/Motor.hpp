/**********************************************************************************/
/**
*  @file
*  Motor.hpp - declaration of class TMotor.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MotorH
#define __MotorH

/**********************************************************************************/
#include "System.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMotor : public TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  virtual void IRQ_HandlerStep(void)=0;
  virtual void StartForward(unsigned char)=0;
  virtual void StartBackward(unsigned char)=0;
  virtual void Stop(void)=0;
  virtual void SetIdlingMode(void)=0;
  
  SemaphoreHandle_t GetHandleSemaphoreStep(void);
  ESystemStatus TakeStepSemaphore(unsigned short);
  void GiveStepSemaphore(void);
  void GiveStepSemaphoreFromIsr(void);
  
protected:
  ////// variables //////
  SemaphoreHandle_t semaphoreStep;
  
  ////// constants //////

  
  ////// functions //////
  
  
private:
  ////// variables //////
 
  
  ////// constants //////

  
  ////// functions //////
  

};
//--- end class TMotor -------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
