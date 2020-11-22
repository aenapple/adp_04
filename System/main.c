/**********************************************************************************/
/**
*  @file
*  main.c - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "..\code\HardDrivers\Gpio.hpp"
#include "..\code\HardDrivers\Adc.hpp"
#include "..\code\HardDrivers\Tim.hpp"
#include "..\code\HardDrivers\Exti.hpp"
#include "MainTask.hpp"
#include "..\code\Tasks\MovingTask.hpp"
//#include "..\code\GraphicalInterface\GraphicalInterfaceTask.hpp"


extern TSystem System;
extern TGpio Gpio;
extern TAdc Adc;
extern TMainTask MainTask;
extern TMovingTask MovingTask;
//extern TGraphicalInterfaceTask GraphicalInterfaceTask;
extern TTim Tim;
extern TExti Exti;
/**********************************************************************************/


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void main(void)
{
  System.Init();
  Gpio.Init();
  Tim.Init();
  Exti.Init();
  Adc.Init();
  
  MainTask.CreateTask();
  MovingTask.CreateTask();
  //GraphicalInterfaceTask.CreateTask();
  
  
  vTaskStartScheduler();
  
  
  while(true)
  {
    vTaskDelay(1000);
    //LedIndicator.TurnOff();
    //LedIndicator.TurnOn();
      
  }
  
}
//--- end main ---------------------------------------------------------------------

/**********************************************************************************/
