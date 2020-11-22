/**********************************************************************************/
/**
*  @file
*  System.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "System.hpp"

TSystem System;
/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSystem::Init(void)
{
  System.xQueueSet2Members= xQueueCreateSet(2);
  System.xQueueSet3Members= xQueueCreateSet(3);
  
}
//--- end Init ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSystem::Delay(unsigned long time)
{
  if(time > portTICK_RATE_MS) vTaskDelay(time/portTICK_RATE_MS);
  else vTaskDelay(1);
}
//--- end Delay --------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
SemaphoreHandle_t TSystem::CreateSemaphore(void)
{
  return(xSemaphoreCreateBinary());
}
//--- end CreateSemaphore ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TSystem::TakeSemaphore(SemaphoreHandle_t handleSemaphore, unsigned short timeOut)
{
  portBASE_TYPE result;
  
  if(timeOut > portTICK_RATE_MS) result= xSemaphoreTake(handleSemaphore, (timeOut / portTICK_RATE_MS));
  else result= xSemaphoreTake(handleSemaphore, 0);
  
  if(result == pdTRUE) return(SystemSemaphore_TakeOk);
  
  return(SystemSemaphore_TakeError);
}
//--- end TakeSemaphore ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSystem::GiveSemaphore(SemaphoreHandle_t handleSemaphore)
{
  xSemaphoreGive(handleSemaphore);
}
//--- end GiveSemaphore ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSystem::GiveSemaphoreFromIsr(SemaphoreHandle_t handleSemaphore)
{
  BaseType_t xHigherPriorityTaskWoken;
  
  xHigherPriorityTaskWoken= pdFALSE;
  xSemaphoreGiveFromISR(handleSemaphore, &xHigherPriorityTaskWoken );
  portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}
//--- end GiveSemaphoreFromIsr -----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
QueueSetMemberHandle_t TSystem::QueueSet2MembersSelectFromSet(unsigned short timeOut)
{
  QueueSetMemberHandle_t result;
  
  if(timeOut > portTICK_RATE_MS) result= xQueueSelectFromSet(System.xQueueSet2Members, (timeOut / portTICK_RATE_MS));
  else result= xQueueSelectFromSet(System.xQueueSet2Members, 0);
  
  return(result);
}
//--- end QueueSet2MembersSelectFromSet --------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TSystem::QueueSet2MembersAddToSet(QueueSetMemberHandle_t xQueueOrSemaphore)
{
  xQueueAddToSet(xQueueOrSemaphore, System.xQueueSet2Members);
  
  return(SystemStatus_ResultOk);
}
//--- end QueueSet2MembersAddToSet -------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TSystem::QueueSet2MembersRemoveFromSet(QueueSetMemberHandle_t xQueueOrSemaphore)
{
  xQueueRemoveFromSet(xQueueOrSemaphore, System.xQueueSet2Members);
  
  return(SystemStatus_ResultOk);
}
//--- end QueueSet2MembersRemoveFromSet --------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
QueueSetMemberHandle_t TSystem::QueueSet3MembersSelectFromSet(unsigned short timeOut)
{
  QueueSetMemberHandle_t result;
  
  if(timeOut > portTICK_RATE_MS) result= xQueueSelectFromSet(System.xQueueSet3Members, (timeOut / portTICK_RATE_MS));
  else result= xQueueSelectFromSet(System.xQueueSet3Members, 0);
  
  return(result);
}
//--- end QueueSet3MembersSelectFromSet --------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TSystem::QueueSet3MembersAddToSet(QueueSetMemberHandle_t xQueueOrSemaphore)
{
  xQueueAddToSet(xQueueOrSemaphore, System.xQueueSet3Members);
  
  return(SystemStatus_ResultOk);
}
//--- end QueueSet3MembersAddToSet -------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
ESystemStatus TSystem::QueueSet3MembersRemoveFromSet(QueueSetMemberHandle_t xQueueOrSemaphore)
{
  xQueueRemoveFromSet(xQueueOrSemaphore, System.xQueueSet3Members);
  
  return(SystemStatus_ResultOk);
}
//--- end QueueSet3MembersRemoveFromSet --------------------------------------------

/**********************************************************************************/
