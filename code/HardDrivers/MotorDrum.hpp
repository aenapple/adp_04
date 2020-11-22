/**********************************************************************************/
/**
*  @file
*  MotorDrum.hpp - declaration of class TMotorDrum.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MotorDrumH
#define __MotorDrumH

/**********************************************************************************/
#include "Motor.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMotorDrum : public TMotor
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  TMotorDrum(void);
  void IRQ_HandlerStep(void);
  void StartForward(unsigned char);
  void StartBackward(unsigned char);
  void Stop(void);
  void SetIdlingMode(void);
  void IncrementStepCounter(void);
  unsigned short GetStepCounter(void);
  ESystemStatus GetStateHome1PositionSensor(void);
  ESystemStatus GetStateHome2PositionSensor(void);
  void SetPosition(unsigned char);
  unsigned char GetPosition(void);
  
  
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  
  
private:
  ////// variables //////
  volatile unsigned short stepCounter;
  unsigned char position;
  
  
  
  ////// constants //////

  ////// functions //////
  
  
  

};
//--- end class TMotorDrum ---------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
