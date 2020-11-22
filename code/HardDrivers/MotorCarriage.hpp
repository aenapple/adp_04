/**********************************************************************************/
/**
*  @file
*  MotorCarriage.hpp - declaration of class TMotorCarriage.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MotorCarriageH
#define __MotorCarriageH

/**********************************************************************************/
#include "Motor.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMotorCarriage : public TMotor
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  TMotorCarriage(void);
  void IRQ_HandlerStep(void);
  void StartForward(unsigned char);
  void StartBackward(unsigned char);
  void Stop(void);
  void SetupNewSpeed(unsigned char);
  void SetIdlingMode(void);
  void IncrementStepCounter(void);
  unsigned short GetStepCounter(void);
  ESystemStatus GetStateStartPositionSensor(void);
  ESystemStatus GetStateEndPositionSensor(void);
  ESystemStatus GetStateLengthCassetteSensor(void);
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
//--- end class TMotorCarriage -----------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
