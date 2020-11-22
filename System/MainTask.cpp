/**********************************************************************************/
/**
*  @file
*  MainTask.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MainTask.hpp"
#include "..\code\HardDrivers\Gpio.hpp"
#include "..\code\HardDrivers\Tim.hpp"
#include "..\code\Tasks\MovingTask.hpp"
#include "..\code\HardDrivers\MotorDrum.hpp"
#include "..\code\HardDrivers\MotorLever.hpp"
//#include "..\code\HardDrivers\MotorLockDrum.hpp"
#include "..\code\HardDrivers\MotorCarriage.hpp"

TMainTask MainTask;
extern TGpio Gpio;
extern TTim Tim;
extern TMovingTask MovingTask;
extern TMotorDrum MotorDrum;
extern TMotorLever MotorLever;
//extern TMotorLockDrum MotorLockDrum;
extern TMotorCarriage MotorCarriage;
/**********************************************************************************/


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMainTask::Execute(void *p)
{
  QueueHandle_t xQueue;
  ETaskMovingQueue bufferQueue;  
  ESystemStatus result;
  unsigned short i;
  unsigned short k;
  
  result= MainTask.PowerUpInitialization();
  // DEBUG
  //Gpio.Power5vOn();
  //Gpio.OpticSensorOn();
  //Gpio.ResetImageSensorClk();
  //Gpio.ResetImageSensorSi();
  //result= SystemStatus_ResultOk;
  //MovingTask.UnlockDrum();
  // DEBUG
  
  while(true)
  {
    if(result != SystemStatus_ResultOk)
    {
      for(i=0; i < 3; i++)
      {
        MainTask.Delay(200);
        Gpio.LedIndicatorOn();
        MainTask.Delay(200);
        Gpio.LedIndicatorOff();
      }
      
      MainTask.Delay(1000);
      continue;
    }
    
    
    /*
    MainTask.Delay(1000);
    
    MotorCarriage.StartForward(100);
    
    MainTask.Delay(1000);
    
    MotorCarriage.Stop();
    
    MainTask.Delay(1000);
    
    MotorCarriage.StartBackward(100);
    
    MainTask.Delay(1000);
    
    MotorCarriage.Stop();
    
    continue;
    */
    
    //GPIO_ResetBits(GPIOA, GPIO_Pin_5);
    //Gpio.LedIndicatorOff();
    //Gpio.OpticSensorOff();
    
    /*
    MainTask.Delay(2000);
    
    MotorLever.StartForward(100);
    
    MainTask.Delay(500);
    
    MotorLever.Stop();
    
    MainTask.Delay(2000);
    
    MotorLever.StartBackward(30);
    
    MainTask.Delay(2000);
    
    MotorLever.Stop();
    
    //GPIO_SetBits(GPIOA, GPIO_Pin_5);
    
    //Gpio.LedIndicatorOn();
    
    
    //MainTask.Delay(2000);
    */
    
    
    xQueue= MovingTask.GetQueueHandle();
    bufferQueue= ETaskMovingScanCassettes;
    xQueueSend(xQueue, &bufferQueue, 0);
    MovingTask.TakeEndActionSemaphore(10000);
    
    MainTask.Delay(2000);

    bufferQueue= ETaskMovingCarriageToPosition1;
    xQueueSend(xQueue, &bufferQueue, 0);
    MovingTask.TakeEndActionSemaphore(10000);
    
    MainTask.Delay(2000);
    
    bufferQueue= ETaskMovingCarriageToPosition2;
    xQueueSend(xQueue, &bufferQueue, 0);
    MovingTask.TakeEndActionSemaphore(10000);
    
    MainTask.Delay(2000);
    
    bufferQueue= ETaskMovingCarriageToPosition3;
    xQueueSend(xQueue, &bufferQueue, 0);
    MovingTask.TakeEndActionSemaphore(10000);
    
    while(true) MainTask.Delay(2000);
    
    
    /*
    bufferQueue= ETaskMovingCarriageToEndPosition;
    xQueueSend(xQueue, &bufferQueue, 0);
    MovingTask.TakeEndActionSemaphore(10000);
  
    while(true) MainTask.Delay(20000);
    */
    
    //MainTask.PowerUpInitialization();
    
    //MovingTask.UnlockDrum();
    //Gpio.OpticSensorOn();
    //MotorDrum.StartBackward(40);
    
    
    
  }
  
}
//--- end Execute ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMainTask::CreateTask(void)
{
  xTaskCreate(this->Execute, "MAIN TASK", TASK_MAIN_SIZE_STACK, NULL, TASK_MAIN_PRIORITY, NULL);
}
//--- end CreateTask ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TMainTask::PowerUpInitialization(void)
{
  ESystemStatus result;
  QueueHandle_t xQueue;
  ETaskMovingQueue bufferQueue;
  
  MainTask.Delay(10);
  Gpio.Power5vOn();
  //Gpio.OpticSensorOn();
  
  xQueue= MovingTask.GetQueueHandle();
  
  ////// Setup cariagge to start position. //////
  bufferQueue= ETaskMovingCarriageToStartPosition;
  xQueueSend(xQueue, &bufferQueue, 0);
  MovingTask.TakeEndActionSemaphore(6000);
  result= MovingTask.GetState();
  if(result != SystemStatus_ResultOk) return(result);
  
  ////// Setup drum to home1 position. //////
  bufferQueue= ETaskMovingDrumToHome1Position;
  xQueueSend(xQueue, &bufferQueue, 0);
  MovingTask.TakeEndActionSemaphore(10000);
  
  return(MovingTask.GetState());
}
//--- end PowerUpInitialization ----------------------------------------------------

/**********************************************************************************/
