/**********************************************************************************/
/**
*  @file
*  MotorLockDrum.hpp - declaration of class TMotorLockDrum.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MotorLockDrumH
#define __MotorLockDrumH

/**********************************************************************************/
#include "Motor.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMotorLockDrum : public TMotor
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void IRQ_HandlerStep(void);
  void StartForward(unsigned char);
  void StartBackward(unsigned char);
  void Stop(void);
  void SetIdlingMode(void);
  void SetPosition(unsigned char);
  unsigned char GetPosition(void);
  ESystemStatus GetStateLockSensor(void);
  ESystemStatus GetStateUnlockSensor(void);
  
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  
  
private:
  ////// variables //////
  unsigned char position;
  
  ////// constants //////

  ////// functions //////
  
  
  

};
//--- end class TMotorLockDrum -----------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
