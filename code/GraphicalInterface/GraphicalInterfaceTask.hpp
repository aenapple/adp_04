/**********************************************************************************/
/**
*  @file
*  GraphicalInterfaceTask.hpp - declaration of class TGraphicalInterfaceTask.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __GraphicalInterfaceTaskH
#define __GraphicalInterfaceTaskH

/**********************************************************************************/
#include "Task.hpp"
#include ".\Menus\Menu.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TGraphicalInterfaceTask : public TTask
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void CreateTask(void);
 
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  //TMenuMain MenuMain;
  //TMenuSetups MenuSetups;
  TMenu* MenuCurrent;
  

  ////// constants //////

  ////// functions //////
  static void Execute(void*);
  
  void DrawMenu(TMenu*);
  EPressedButton PerfomMenu(TMenu*);
  EPressedButton CheckPressedButtons(void);
  

};
//--- end class TGraphicalInterfaceTask --------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
