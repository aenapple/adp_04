/**********************************************************************************/
/**
*  @file
*  MotorLever.hpp - declaration of class TMotorLever.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MotorLeverH
#define __MotorLeverH

/**********************************************************************************/
#include "Motor.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMotorLever : public TMotor
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  TMotorLever(void);
  void IRQ_HandlerStep(void);
  void StartForward(unsigned char);
  void StartBackward(unsigned char);
  void Stop(void);
  void SetIdlingMode(void);
  void IncrementStepCounter(void);
  unsigned short GetStepCounter(void);
  ESystemStatus GetStateStartPositionSensor(void);
  void SetPosition(unsigned char);
  unsigned char GetPosition(void);
  
  
  
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  
  
private:
  ////// variables //////
  unsigned char direction;
  unsigned char position;
  volatile unsigned short stepCounter;
  
  ////// constants //////

  ////// functions //////
  
  
  

};
//--- end class TMotorLever --------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
