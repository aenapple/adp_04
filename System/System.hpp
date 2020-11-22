/**********************************************************************************/
/**
*  @file
*  System.hpp - declaration of class TSystem.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __SystemH
#define __SystemH

/**********************************************************************************/
#ifdef __FREE_RTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#endif

#ifdef __STM32F207
#include "stm32f2xx_gpio.h"
#include "stm32f2xx_rcc.h"

#define SemaphoreHandle_t  xSemaphoreHandle
#define QueueHandle_t  xQueueHandle
#define BaseType_t  portBASE_TYPE
#endif

#ifdef STM32F4XX
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#endif

#include <string.h>

/**********************************************************************************/


/**********************************************************************************/
typedef enum
{
  SystemStatus_ResultOk=0,
  SystemStatus_SensorIsOn,
  SystemStatus_SensorIsOff,
  SystemError_StepCarriageMotor,
  SystemError_StartSensorCarriageMotor,
  SystemError_EndSensorCarriageMotor,
  SystemError_StepLeverMotor,
  SystemError_StartSensorLeverMotor,
  SystemError_StepDrumMotor,
  SystemError_Home1SensorDrumMotor,
  SystemError_Home2SensorDrumMotor,
  SystemSemaphore_TakeError,
  SystemSemaphore_TakeOk,
} ESystemStatus;

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void Delay(unsigned long time);
  static void Init(void);
  static SemaphoreHandle_t CreateSemaphore(void);
  static ESystemStatus TakeSemaphore(SemaphoreHandle_t, unsigned short);
  static void GiveSemaphore(SemaphoreHandle_t);
  static void GiveSemaphoreFromIsr(SemaphoreHandle_t);
  
  static QueueSetMemberHandle_t QueueSet2MembersSelectFromSet(unsigned short);
  static ESystemStatus QueueSet2MembersAddToSet(QueueSetMemberHandle_t);
  static ESystemStatus QueueSet2MembersRemoveFromSet(QueueSetMemberHandle_t);
  static QueueSetMemberHandle_t QueueSet3MembersSelectFromSet(unsigned short);
  static ESystemStatus QueueSet3MembersAddToSet(QueueSetMemberHandle_t);
  static ESystemStatus QueueSet3MembersRemoveFromSet(QueueSetMemberHandle_t);
  
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  //virtual void CreateTask(void)=0;
  
private:
  ////// variables //////
  QueueSetHandle_t xQueueSet2Members;
  QueueSetHandle_t xQueueSet3Members;
  
  ////// constants //////

  ////// functions //////


};
//--- end class TSystem ------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
