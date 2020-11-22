/**********************************************************************************/
/**
*  @file
*  Task.hpp - declaration of class TTask.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __TaskH
#define __TaskH

/**********************************************************************************/
#include "System.hpp"

/**********************************************************************************/


/**********************************************************************************/
#define TASK_MAIN_SIZE_STACK    256*4
#define TASK_GUI_SIZE_STACK     256*4
#define TASK_MOVING_SIZE_STACK  256*4

////// configMAX_PRIORITIES = 6. //////
#define TASK_MAIN_PRIORITY    (configMAX_PRIORITIES - 3)
#define TASK_GUI_PRIORITY     (configMAX_PRIORITIES - 2)
#define TASK_MOVING_PRIORITY  (configMAX_PRIORITIES - 4)

#define TASK_MOVING_QUEUE_LENGHT      16
#define TASK_MOVING_QUEUE_ITEM_SIZE   1

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TTask : public TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  virtual void CreateTask(void)=0;
  
private:
  ////// variables //////

  ////// constants //////

  ////// functions //////


};
//--- end class TTask --------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
