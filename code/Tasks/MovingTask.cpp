/**********************************************************************************/
/**
*  @file
*  MovingTask.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MovingTask.hpp"
#include "..\code\HardDrivers\MotorLockDrum.hpp"
#include "..\code\HardDrivers\MotorDrum.hpp"
#include "..\code\HardDrivers\MotorCarriage.hpp"
#include "..\code\HardDrivers\MotorLever.hpp"
#include "..\code\HardDrivers\Gpio.hpp"
#include "..\code\HardDrivers\Adc.hpp"
#include "..\code\HardDrivers\Tim.hpp"

TMovingTask MovingTask;
extern TSystem System;
extern TMotorLockDrum MotorLockDrum;
extern TMotorDrum MotorDrum;
extern TMotorCarriage MotorCarriage;
extern TMotorLever MotorLever;
extern TGpio Gpio;
extern TAdc Adc;
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
void TMovingTask::Execute(void *p)
{
  ETaskMovingQueue bufferQueue;
  
  MovingTask.Delay(20);
  MovingTask.Reset();
  MotorDrum.SetPosition(MOTOR_DRUM_POSITION_NONE);
  MotorLockDrum.SetPosition(MOTOR_LOCK_DRUM_POSITION_NONE);
  MotorLever.SetPosition(MOTOR_LEVER_POSITION_NONE);
  MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_NONE);
  
  while(true)
  {
    if(xQueueReceive(MovingTask.xQueue, &bufferQueue, 100) == errQUEUE_EMPTY) continue;
    
    MovingTask.TakeEndActionSemaphore(0);  // reset semaphore
    
    switch(bufferQueue)
    {
      case ETaskMovingReset:
        MovingTask.Reset();
        break;
        
      case ETaskMovingCarriageToStartPosition:
        MovingTask.SetupCarriageToStartPosition();
        break;
        
      case ETaskMovingCarriageToEndPosition:
        MovingTask.SetupCarriageToEndPosition();
        break;
        
      case ETaskMovingLeverToStartPosition:
        MovingTask.SetupLeverToStartPosition();
        break;
        
      case ETaskMovingLeverToEndPosition:
        MovingTask.SetupLeverToEndPosition();
        break;
        
      case ETaskMovingDrumToHome1Position:
        MovingTask.SetupDrumToHome1Position();
        break;
        
      case ETaskMovingDrumToHome2Position:
        MovingTask.SetupDrumToHome2Position();
        break;
        
      case ETaskMovingScanCassettes:
        MovingTask.ScanCassettes();
        break;
        
      case ETaskMovingCarriageToPosition1:
        MovingTask.SetupCarriageToPosition(MOTOR_CARRIAGE_POSITION_CAS1);
        break;
        
      case ETaskMovingCarriageToPosition2:
        MovingTask.SetupCarriageToPosition(MOTOR_CARRIAGE_POSITION_CAS2);
        break;
        
      case ETaskMovingCarriageToPosition3:
        MovingTask.SetupCarriageToPosition(MOTOR_CARRIAGE_POSITION_CAS3);
        break;
        
      case ETaskMovingCarriageToPosition4:
        MovingTask.SetupCarriageToPosition(MOTOR_CARRIAGE_POSITION_CAS4);
        break;
        
      case ETaskMovingCarriageToPosition5:
        MovingTask.SetupCarriageToPosition(MOTOR_CARRIAGE_POSITION_CAS5);
        break;
        
      case ETaskMovingCarriageToPosition6:
        MovingTask.SetupCarriageToPosition(MOTOR_CARRIAGE_POSITION_CAS6);
        break;
        
    }
    
    MovingTask.GiveEndActionSemaphore();
    
    /*
    MovingTask.Delay(1000);
    
    
    MotorCarriage.StartForward(50);
    MovingTask.Delay(1200);
    MotorCarriage.Stop();
    
    
    MovingTask.Delay(1000);
  
    MotorCarriage.SetIdlingMode();
    MovingTask.Delay(10);
    
    MotorCarriage.StartBackward(50);
    MovingTask.Delay(1000);
    MotorCarriage.Stop();
    
    MotorCarriage.SetIdlingMode();
    */
    
  }
  
}
//--- end Execute ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::CreateTask(void)
{
  xTaskCreate(this->Execute, "MOVING TASK", TASK_MOVING_SIZE_STACK, NULL, TASK_MOVING_PRIORITY, NULL);
  this->xQueue= xQueueCreate(TASK_MOVING_QUEUE_LENGHT, TASK_MOVING_QUEUE_ITEM_SIZE);
  this->semaphoreEndAction= this->CreateSemaphore();
}
//--- end CreateTask ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
QueueHandle_t TMovingTask::GetQueueHandle(void)
{
  return(this->xQueue);
}
//--- end GetQueueHandle -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
SemaphoreHandle_t TMovingTask::GetHandleSemaphoreEndAction(void)
{
  return(this->semaphoreEndAction);
}
//--- end GetHandleSemaphoreEndAction ----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::TakeEndActionSemaphore(unsigned short timeOut)
{
  return(this->TakeSemaphore(this->semaphoreEndAction, timeOut));
}
//--- end TakeEndActionSemaphore ---------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::GiveEndActionSemaphore(void)
{
  this->GiveSemaphore(this->semaphoreEndAction);
}
//--- end GiveEndActionSemaphore ---------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::GiveEndActionSemaphoreFromIsr(void)
{
  this->GiveSemaphoreFromIsr(this->semaphoreEndAction);
}
//--- end GiveEndActionSemaphoreFromIsr --------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::Reset(void)
{
  MotorCarriage.SetIdlingMode();
  MotorLever.SetIdlingMode();
  MotorDrum.SetIdlingMode();
  
  this->SetState(SystemStatus_ResultOk);
  return(SystemStatus_ResultOk);
}
//--- end Reset --------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::SetState(ESystemStatus state)
{
  this->state= state;
}
//--- end SetState -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::GetState(void)
{
  return(this->state);
}
//--- end GetState -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupCarriageToStartPosition(void)
{
  ESystemStatus result;
  unsigned short stepsCarriageMotor;
  
  if(MotorLever.GetPosition() != MOTOR_LEVER_POSITION_START)
  {
    result= MovingTask.SetupLeverToStartPosition();
    if(result != SystemStatus_ResultOk) return(result);
  }
  
  Gpio.OpticSensorOn();
  this->Delay(10);
  if(MotorCarriage.GetStateStartPositionSensor() == SystemStatus_SensorIsOn)
  {
    Gpio.OpticSensorOff();
    MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_CAS1);
    this->SetState(SystemStatus_ResultOk);
    return(SystemStatus_ResultOk);
  }
  
  MotorCarriage.StartBackward(100);
  MotorCarriage.TakeStepSemaphore(0);  // reset semaphore
  stepsCarriageMotor= 0;
  while(true)
  {
    ////// Waiting step motor 40 mSec. //////
    if(MotorCarriage.TakeStepSemaphore(40) == SystemSemaphore_TakeError) { result= SystemError_StepCarriageMotor; break; }
    
    stepsCarriageMotor++;
    if(stepsCarriageMotor > MOTOR_CARRIAGE_MAX_STEPS) { result= SystemError_StartSensorCarriageMotor; break; }
    
    if(MotorCarriage.GetStateStartPositionSensor() == SystemStatus_SensorIsOn) { result= SystemStatus_ResultOk; break; }
  }
  
  MotorCarriage.Stop();
  Gpio.OpticSensorOff();
  
  this->SetState(result);
  this->stepCounter= stepsCarriageMotor;
  
  if(result == SystemStatus_ResultOk) MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_CAS1);
  else MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_NONE);
  
  return(result);
}
//--- end SetupCarrigeToStartPosition ----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupCarriageToEndPosition(void)
{
  ESystemStatus result;
  unsigned short stepsCarriageMotor;
  
  Gpio.OpticSensorOn();
  this->Delay(10);
  if(MotorCarriage.GetStateEndPositionSensor() == SystemStatus_SensorIsOn)
  {
    Gpio.OpticSensorOff();
    MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_END);
    this->SetState(SystemStatus_ResultOk);
    return(SystemStatus_ResultOk);
  }
  
  MotorCarriage.StartForward(100);
  MotorCarriage.TakeStepSemaphore(0);  // reset semaphore
  stepsCarriageMotor= 0;
  while(true)
  {
    ////// Waiting step motor 40 mSec. //////
    if(MotorCarriage.TakeStepSemaphore(40) == SystemSemaphore_TakeError) { result= SystemError_StepCarriageMotor; break; }
    
    stepsCarriageMotor++;
    if(stepsCarriageMotor > MOTOR_CARRIAGE_MAX_STEPS) { result= SystemError_EndSensorCarriageMotor; break; }
    
    if(MotorCarriage.GetStateEndPositionSensor() == SystemStatus_SensorIsOn) { result= SystemStatus_ResultOk; break; }
  }
  
  MotorCarriage.Stop();
  Gpio.OpticSensorOff();
  
  // DEBUG
  //result= SystemStatus_ResultOk;
  // DEBUG
  this->SetState(result);
  this->stepCounter= stepsCarriageMotor;
  
  if(result == SystemStatus_ResultOk) MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_END);
  else MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_NONE);
  
  return(result);
}
//--- end SetupCarrigeToEndPosition ------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupLeverToStartPosition(void)
{
  ESystemStatus result;
  unsigned short stepsLeverMotor;
  
  Gpio.OpticSensorOn();
  this->Delay(10);
  if(MotorLever.GetStateStartPositionSensor() == SystemStatus_SensorIsOn)
  {
    Gpio.OpticSensorOff();
    MotorLever.SetPosition(MOTOR_LEVER_POSITION_START);
    this->SetState(SystemStatus_ResultOk);
    return(SystemStatus_ResultOk);
  }
  
  MotorLever.StartBackward(100);
  MotorLever.TakeStepSemaphore(0);  // reset semaphore
  stepsLeverMotor= 0;
  
  while(true)
  {
    ////// Waiting step motor 40 mSec. //////
    if(MotorLever.TakeStepSemaphore(40) == SystemSemaphore_TakeError) { result= SystemError_StepLeverMotor; break; }
    
    stepsLeverMotor++;
    if(stepsLeverMotor > MOTOR_LEVER_MAX_STEPS) { result= SystemError_StartSensorLeverMotor; break; }
    
    if(MotorLever.GetStateStartPositionSensor() == SystemStatus_SensorIsOn) { result= SystemStatus_ResultOk; break; }
  }
  
  MotorLever.Stop();
  Gpio.OpticSensorOff();
  
  this->SetState(result);
  this->stepCounter= stepsLeverMotor;
  
  if(result == SystemStatus_ResultOk) MotorLever.SetPosition(MOTOR_LEVER_POSITION_START);
  else MotorLever.SetPosition(MOTOR_LEVER_POSITION_NONE);
  
  return(result);
}
//--- end SetupLeverToStartPosition ------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupLeverToEndPosition(void)
{
  ESystemStatus result;
  unsigned short stepsLeverMotor;
  
  if(MotorLever.GetPosition() != MOTOR_LEVER_POSITION_START)
  {
    result= this->SetupLeverToStartPosition();
    if(result != SystemStatus_ResultOk) return(result);
  }
  
  Gpio.OpticSensorOn();
  this->Delay(10);
  MotorLever.StartForward(100);
  MotorLever.TakeStepSemaphore(0);  // reset semaphore
  stepsLeverMotor= 0;
  
  while(true)
  {
    ////// Waiting step motor 40 mSec. //////
    if(MotorLever.TakeStepSemaphore(40) == SystemSemaphore_TakeError) { result= SystemError_StepLeverMotor; break; }
    
    stepsLeverMotor++;
    if(stepsLeverMotor > MOTOR_LEVER_MAX_STEPS) { result= SystemError_StartSensorLeverMotor; break; }
    
    //if(stepsLeverMotor > MOTOR_LEVER_END_STEPS) { result= SystemStatus_ResultOk; break; }
    
  }
  
  MotorLever.Stop();
  Gpio.OpticSensorOff();
  
  if(stepsLeverMotor > MOTOR_LEVER_END_STEPS) result= SystemStatus_ResultOk;
  
  this->SetState(result);
  this->stepCounter= stepsLeverMotor;
  
  if(result == SystemStatus_ResultOk) MotorLever.SetPosition(MOTOR_LEVER_POSITION_END);
  else MotorLever.SetPosition(MOTOR_LEVER_POSITION_NONE);
  
  return(result);
}
//--- end SetupLeverToEndPosition --------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupLeverToScanPosition(void)
{
  ESystemStatus result;
  unsigned short stepsLeverMotor;
  
  if(MotorLever.GetPosition() != MOTOR_LEVER_POSITION_START)
  {
    result= this->SetupLeverToStartPosition();
    if(result != SystemStatus_ResultOk) return(result);
  }
  
  Gpio.OpticSensorOn();
  this->Delay(10);
  MotorLever.StartForward(100);
  MotorLever.TakeStepSemaphore(0);  // reset semaphore
  stepsLeverMotor= 0;
  
  while(true)
  {
    ////// Waiting step motor 40 mSec. //////
    if(MotorLever.TakeStepSemaphore(40) == SystemSemaphore_TakeError) { result= SystemError_StepLeverMotor; break; }
    
    stepsLeverMotor++;
    if(stepsLeverMotor > MOTOR_LEVER_SCAN_STEPS) { result= SystemStatus_ResultOk; break; }
    
    //if(stepsLeverMotor > MOTOR_LEVER_END_STEPS) { result= SystemStatus_ResultOk; break; }
    
  }
  
  MotorLever.Stop();
  Gpio.OpticSensorOff();
  
  this->SetState(result);
  this->stepCounter= stepsLeverMotor;
  
  if(result == SystemStatus_ResultOk) MotorLever.SetPosition(MOTOR_LEVER_POSITION_SCAN);
  else MotorLever.SetPosition(MOTOR_LEVER_POSITION_NONE);
  
  return(result);
}
//--- end SetupLeverToScanPosition -------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupDrumToHome1Position(void)
{
  ESystemStatus result;
  unsigned short stepsDrumMotor;
  
  if(MotorDrum.GetPosition() == MOTOR_DRUM_POSITION_HOME1)
  {
    this->Delay(10);
    this->SetState(SystemStatus_ResultOk);
    return(SystemStatus_ResultOk);
  }
  
  result= this->UnlockDrum();
  if(result != SystemStatus_ResultOk) return(result);
  
  Gpio.OpticSensorOn();
  this->Delay(10);
  
  if(MotorDrum.GetPosition() == MOTOR_DRUM_POSITION_NONE) MotorDrum.StartForward(100);
  else MotorDrum.StartBackward(100);
  
  MotorDrum.TakeStepSemaphore(0);  // reset semaphore
  stepsDrumMotor= 0;
  this->Delay(200);
  
  while(true)
  {
    ////// Waiting step motor 200 mSec. //////
    if(MotorDrum.TakeStepSemaphore(200) == SystemSemaphore_TakeError) { result= SystemError_StepDrumMotor; break; }
    
    stepsDrumMotor++;
    if(stepsDrumMotor > MOTOR_DRUM_MAX_STEPS) { result= SystemError_Home1SensorDrumMotor; break; }
    
    if((MotorDrum.GetStateHome1PositionSensor() == SystemStatus_SensorIsOn) && (MotorDrum.GetStateHome2PositionSensor() == SystemStatus_SensorIsOn)) { result= SystemStatus_ResultOk; break; }
  }
  
  MotorDrum.Stop();
  Gpio.OpticSensorOff();
  
  this->SetState(result);
  this->stepCounter= stepsDrumMotor;
  
  if(result == SystemStatus_ResultOk)
  {
    MotorDrum.SetPosition(MOTOR_DRUM_POSITION_HOME1);
    result= this->LockDrum();
  }
  
  return(result);
}
//--- end SetupDrumToHome1Position -------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupDrumToHome2Position(void)
{
  ESystemStatus result;
  unsigned short stepsDrumMotor;
  
  if(MotorDrum.GetPosition() == MOTOR_DRUM_POSITION_HOME2)
  {
    this->Delay(10);
    this->SetState(SystemStatus_ResultOk);
    return(SystemStatus_ResultOk);
  }
  
  result= this->UnlockDrum();
  if(result != SystemStatus_ResultOk) return(result);
  
  if(MotorDrum.GetPosition() == MOTOR_DRUM_POSITION_NONE) 
  {
    result= this->SetupDrumToHome1Position();
    if(result != SystemStatus_ResultOk) return(result);
  }
  
  Gpio.OpticSensorOn();
  this->Delay(10);
  MotorDrum.StartForward(100);
  MotorDrum.TakeStepSemaphore(0);  // reset semaphore
  stepsDrumMotor= 0;
  this->Delay(200);
  
  while(true)
  {
    ////// Waiting step motor 200 mSec. //////
    if(MotorDrum.TakeStepSemaphore(200) == SystemSemaphore_TakeError) { result= SystemError_StepDrumMotor; break; }
    
    stepsDrumMotor++;
    if(stepsDrumMotor > MOTOR_DRUM_MAX_STEPS) { result= SystemError_Home2SensorDrumMotor; break; }
    
    if((MotorDrum.GetStateHome1PositionSensor() == SystemStatus_SensorIsOn) && (MotorDrum.GetStateHome2PositionSensor() == SystemStatus_SensorIsOff)) { result= SystemStatus_ResultOk; break; }
  }
  
  MotorDrum.Stop();
  Gpio.OpticSensorOff();
  
  this->SetState(result);
  this->stepCounter= stepsDrumMotor;
  
  if(result == SystemStatus_ResultOk)
  {
    MotorDrum.SetPosition(MOTOR_DRUM_POSITION_HOME2);
    result= this->LockDrum();
  }
  
  return(result);
}
//--- end SetupDrumToHome2Position -------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::ScanDrum(void)
{
  ESystemStatus result;
  unsigned short stepsDrumMotor;
  QueueSetMemberHandle_t activatedSemaphore;
  
  result= this->SetupDrumToHome2Position();
  if(result != SystemStatus_ResultOk) return(result);
  
  result= this->SetupLeverToScanPosition();
  if(result != SystemStatus_ResultOk) return(result);
  
  result= this->UnlockDrum();
  if(result != SystemStatus_ResultOk) return(result);
  
  Gpio.OpticSensorOn();
  Gpio.TurnOnScanLed();
  this->Delay(10);
  
  MotorDrum.StartBackward(60);

  this->indexScanArray= 0;
  System.QueueSet2MembersAddToSet(Tim.GetHandleSemaphoreScanDrum());
  System.QueueSet2MembersAddToSet(MotorDrum.GetHandleSemaphoreStep());
  
  //MotorDrum.TakeStepSemaphore(0);  // reset semaphore
  stepsDrumMotor= 0;
  //this->NoScanOneStep();
  //Tim.StartTim3(60);
  
  while(true)
  {
    ////// Waiting step motor 200 mSec. //////
    //if(MotorDrum.TakeStepSemaphore(200) == SystemSemaphore_TakeError) { result= SystemError_StepDrumMotor; break; }
    //if(Tim.TakeScanDrumSemaphore(200) == SystemSemaphore_TakeError) { result= SystemError_StepDrumMotor; break; }
    
    activatedSemaphore= System.QueueSet2MembersSelectFromSet(200);
    if(activatedSemaphore == MotorDrum.GetHandleSemaphoreStep())
    {
      stepsDrumMotor++;
      MotorDrum.TakeStepSemaphore(0);
      
      if(stepsDrumMotor == 60)
      {
        this->NoScanOneStep();
        Tim.StartTim3(50);
      }
      
      if(stepsDrumMotor > MOTOR_DRUM_MAX_STEPS) { result= SystemError_Home1SensorDrumMotor; break; }
    
      if(stepsDrumMotor > (MOTOR_DRUM_MAX_STEPS / 2))
      {
        if((MotorDrum.GetStateHome1PositionSensor() == SystemStatus_SensorIsOn) && (MotorDrum.GetStateHome2PositionSensor() == SystemStatus_SensorIsOff)) { result= SystemStatus_ResultOk; break; }
      }
      
      continue;
    }
    
    
    
    
    if(activatedSemaphore == Tim.GetHandleSemaphoreScanDrum())
    {
      //if((stepsDrumMotor % 2) == 0) 
      Tim.TakeScanDrumSemaphore(0);
      this->ScanOneStep();
      
      Tim.StartTim3(50);
    
    //this->Delay(20);
    //this->ScanOneStep();
    //this->NoScanOneStep();
    }
      
  }
  
  MotorDrum.Stop();
  Gpio.OpticSensorOff();
  Gpio.TurnOffScanLed();
  Adc.StopConversionAdc1();
  this->LockDrum();
  
  System.QueueSet2MembersRemoveFromSet(MotorDrum.GetHandleSemaphoreStep());
  System.QueueSet2MembersRemoveFromSet(Tim.GetHandleSemaphoreScanDrum());
  
  this->SetState(result);
  this->stepCounter= stepsDrumMotor;
  
  //this->Calculate();
  
  if(result == SystemStatus_ResultOk)
  {
    MotorDrum.SetPosition(MOTOR_DRUM_POSITION_HOME1);
    result= this->LockDrum();
  }
  
  
  
  return(result);
}
//--- end ScanDrum -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::Calculate(void)
{
  unsigned short i, k;
  unsigned short indexScanArray;
    
  indexScanArray= 0;
  for(i=0; i < 240; i++)
  {
    
    for(k=0; k < 128; k++)
    {
      if(this->calibrateArray[k] > this->scanArray[indexScanArray]) this->scanArray[indexScanArray]= this->calibrateArray[k] - this->scanArray[indexScanArray];
      else this->scanArray[indexScanArray]= 0;
      indexScanArray++;
    }
    
  }

  
}
//--- end Calculate ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::Calibrate(void)
{
  unsigned short i, k;
  //unsigned short tempArray[128];
  
  
  //for(i=0; i < 128; i++) this->calibrateArray[i]= 0;
  
  k= 0;
  while(true)
  //for(k=0; k < 10; k++)
  {
    Gpio.SetImageSensorSi();
    
    for(i=0; i < 129; i++)
    {
      __NOP;
      __NOP;
      __NOP;
      __NOP;
        
      Gpio.SetImageSensorClk();
        
      __NOP;
      __NOP;
      __NOP;
      __NOP;
        
      Gpio.ResetImageSensorSi();
        
      __NOP;
      __NOP;
      __NOP;
      __NOP;
        
      Gpio.ResetImageSensorClk();
      
      if(k > 1)
      {
        if(k == 2) this->calibrateArray[i]= Adc.ReadAdc1();
        else
        {
          if(i <= 127)
          {
            this->calibrateArray[i] += Adc.ReadAdc1();
            this->calibrateArray[i] /= 2;
          }
          
        }
        
      }
        
      __NOP;
      __NOP;
      __NOP;
      __NOP;
    
    }
    
    this->Delay(100);
    
  }
  
}
//--- end Calibrate ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::ScanOneStep(void)
{
  unsigned short i;
  
  Gpio.SetImageSensorSi();
  
  for(i=0; i < 129; i++)
  {
    __NOP;
    __NOP;
    __NOP;
    __NOP;
        
    Gpio.SetImageSensorClk();
        
    __NOP;
    __NOP;
    __NOP;
    __NOP;
        
    Gpio.ResetImageSensorSi();
        
    __NOP;
    __NOP;
    __NOP;
    __NOP;
        
    Gpio.ResetImageSensorClk();
    
    if(i <= 127)
    {
      this->scanArray[indexScanArray]= Adc.ReadAdc1();
      if(this->indexScanArray < (240*128-1)) this->indexScanArray++;
    }
        
    __NOP;
    __NOP;
    __NOP;
    __NOP;
    
    
      
  }
  
  
  
  
  
}
//--- end ScanOneStep --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMovingTask::NoScanOneStep(void)
{
  unsigned short i;
  
  Gpio.SetImageSensorSi();
  
  for(i=0; i < 129; i++)
  {
    __NOP;
    __NOP;
    __NOP;
    __NOP;
        
    Gpio.SetImageSensorClk();
        
    __NOP;
    __NOP;
    __NOP;
    __NOP;
        
    Gpio.ResetImageSensorSi();
        
    __NOP;
    __NOP;
    __NOP;
    __NOP;
        
    Gpio.ResetImageSensorClk();
    
    __NOP;
    __NOP;
    __NOP;
    __NOP;
    
    
      
  }
  
  
  
  
  
}
//--- end NoScanOneStep ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::UnlockDrum(void)
{
  ESystemStatus result;
  unsigned short i;
  
  if(MotorLockDrum.GetPosition() == MOTOR_LOCK_DRUM_POSITION_UNLOCK)
  {
    this->Delay(10);
    this->SetState(SystemStatus_ResultOk);
    return(SystemStatus_ResultOk);
  }
  
  Gpio.OpticSensorOn();
  MotorLockDrum.StartBackward(100);
  for(i=0; i < 100; i++) // time-out 1 Sec
  {
    this->Delay(10);
    
    if(MotorLockDrum.GetStateUnlockSensor() == SystemStatus_SensorIsOn) { result= SystemStatus_ResultOk; break; }
    
    if(i == 98) { result= SystemError_Home2SensorDrumMotor; break; }
  }
  
  MotorLockDrum.Stop();
  Gpio.OpticSensorOff();
  
  MotorLockDrum.SetPosition(MOTOR_LOCK_DRUM_POSITION_UNLOCK);
  this->SetState(result);
  
  return(result);
}
//--- end UnlockDrum ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::LockDrum(void)
{
  ESystemStatus result;
  unsigned short i;
  
  if(MotorLockDrum.GetPosition() == MOTOR_LOCK_DRUM_POSITION_LOCK)
  {
    this->Delay(10);
    this->SetState(SystemStatus_ResultOk);
    return(SystemStatus_ResultOk);
  }
  
  Gpio.OpticSensorOn();
  MotorLockDrum.StartForward(100);
  for(i=0; i < 100; i++) // time-out 1 Sec
  {
    this->Delay(10);
    
    if(MotorLockDrum.GetStateLockSensor() == SystemStatus_SensorIsOn) { result= SystemStatus_ResultOk; break; }
    
    if(i == 98) { result= SystemError_Home2SensorDrumMotor; break; }
  }
  
  MotorLockDrum.Stop();
  Gpio.OpticSensorOff();
  
  MotorLockDrum.SetPosition(MOTOR_LOCK_DRUM_POSITION_LOCK);
  this->SetState(result);
  
  return(result);
}
//--- end LockDrum -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::ScanCassettes(void)
{
  ESystemStatus result;
  unsigned short stepsCarriageMotor;
  unsigned short i;
  unsigned char cassetteNumber;
  unsigned char flagLevel;
  
  // DEBUG
  //MovingTask.SetupLeverToStartPosition();
  //this->Delay(500);
  //MovingTask.SetupLeverToEndPosition();
  //Gpio.OpticSensorOn();
  //this->Delay(4000);
  //MovingTask.SetupLeverToStartPosition();
  //return(SystemStatus_ResultOk);
  // DEBUG
  
  if(MotorCarriage.GetPosition() != MOTOR_CARRIAGE_POSITION_CAS1)
  {
    result= this->SetupCarriageToStartPosition();
    if(result != SystemStatus_ResultOk) return(result);
    this->Delay(200);
  }
  
  if(MotorDrum.GetPosition() != MOTOR_DRUM_POSITION_HOME1)
  {
    result= this->SetupDrumToHome1Position();
    if(result != SystemStatus_ResultOk) return(result);
    this->Delay(200);
  }
  
  Gpio.OpticSensorOn();
  MotorCarriage.StartForward(100);
  stepsCarriageMotor= 0;
  while(true)
  {
    ////// Waiting step motor 40 mSec. //////
    if(MotorCarriage.TakeStepSemaphore(40) == SystemSemaphore_TakeError) { result= SystemError_StepCarriageMotor; break; }
    
    if(MotorCarriage.GetStateLengthCassetteSensor() == SystemStatus_SensorIsOn) this->arrayCassettesSteps[stepsCarriageMotor]= 1;
    else this->arrayCassettesSteps[stepsCarriageMotor]= 0;
    
    stepsCarriageMotor++;
    if(stepsCarriageMotor > MOTOR_CARRIAGE_MAX_STEPS) { result= SystemError_StartSensorCarriageMotor; break; }
    
    if(MotorCarriage.GetStateEndPositionSensor() == SystemStatus_SensorIsOn) { result= SystemStatus_ResultOk; break; }
  }
  this->arrayCassettesSteps[stepsCarriageMotor]= 0xFF;
  
  MotorCarriage.Stop();
  
  
  // DEBUG
  /*
  for(int i=0; i < 100; i++)
  {
    result= MotorCarriage.GetStateLengthCassetteSensor();
    stepsCarriageMotor= 1;
  }
  */
  // DEBUG
  
  Gpio.OpticSensorOff();
  
  if(result == SystemStatus_ResultOk) MotorCarriage.SetPosition(MOTOR_CARRIAGE_POSITION_END);
  this->SetState(result);
  this->stepCounter= stepsCarriageMotor;
  this->motorCarriageMaxSteps= stepsCarriageMotor;
  
  i= 0;
  cassetteNumber= 0;
  this->numberCassettes= 0;
  flagLevel= 0;
  while(true)
  {
    if(flagLevel == 0)
    {
      if(this->arrayCassettesSteps[i] > 0) flagLevel= 1;
      
      //i++;
      //if(i > this->motorCarriageMaxSteps) break;
      
    }
    else
    {
      if(this->arrayCassettesSteps[i] == 0)
      {
        flagLevel= 0;
        this->stepsPosition[this->numberCassettes]= i;
        cassetteNumber++;
        this->numberCassettes++;
        
      }
      
    }
    
    i++;
    if(i > this->motorCarriageMaxSteps) break;
    
  }
  
  return(result);
}
//--- end ScanCassettes ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMovingTask::SetupCarriageToPosition(unsigned char position)
{
  ESystemStatus result;
  unsigned short stepsCarriageMotor;
  unsigned short stepsStopCarriageMotor;
  unsigned char flagStop;
  
  if(position == MOTOR_CARRIAGE_POSITION_CAS1)
  {
    this->SetupCarriageToStartPosition();
    this->SetupLeverToEndPosition();
    this->Delay(200);
    this->SetupLeverToStartPosition();
  
    return(SystemStatus_ResultOk);
  }
  
  Gpio.OpticSensorOn();
  MotorCarriage.StartForward(100);
  stepsCarriageMotor= 0;
  
  if(position == MOTOR_CARRIAGE_POSITION_CAS2) stepsStopCarriageMotor= this->stepsPosition[position-2] + 26;
  if(position == MOTOR_CARRIAGE_POSITION_CAS3) stepsStopCarriageMotor= this->stepsPosition[position-2] - this->stepsPosition[position-3];
  flagStop= 0;
  while(true)
  {
    ////// Waiting step motor 40 mSec. //////
    if(MotorCarriage.TakeStepSemaphore(40) == SystemSemaphore_TakeError) { result= SystemError_StepCarriageMotor; break; }
    
    stepsCarriageMotor++;
    if(stepsCarriageMotor > stepsStopCarriageMotor) { result= SystemStatus_ResultOk; break; }
    /*
    {
      if(flagStop == 0) flagStop= 1;
      else
      {
        if(MotorCarriage.GetStateLengthCassetteSensor() == SystemStatus_SensorIsOn) { result= SystemStatus_ResultOk; break; }
      }
      
    }
    */
    
  }
  
  MotorCarriage.Stop();
  Gpio.OpticSensorOff();
  
  // DEBUG
  if(position == MOTOR_CARRIAGE_POSITION_CAS3)
  {
    //this->SetupLeverToScanPosition();
    this->ScanDrum();
    return(result);
  }
  else 
  // DEBUG
    this->SetupLeverToEndPosition();
  this->Delay(200);
  this->SetupLeverToStartPosition();
  
  
  return(result);
}
//--- end SetupCarriageToPosition --------------------------------------------------

/**********************************************************************************/
