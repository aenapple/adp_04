/**********************************************************************************/
/**
*  @file
*  GraphicalInterfaceTask.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "GraphicalInterfaceTask.hpp"
#include "LcdInterface.hpp"
#include ".\Menus\MenuMain.hpp"
#include ".\Menus\MenuSetups.hpp"
#include ".\Menus\MenuMenu.hpp"
#include ".\Menus\MenuSetupDate.hpp"
#include ".\Menus\MenuSetupDateTime.hpp"
#include ".\Menus\MenuEnterID.hpp"
#include ".\Menus\MenuClock.hpp"
#include ".\Menus\MenuSetupsUser1.hpp"
#include ".\Menus\MenuSetupsUser2.hpp"


TGraphicalInterfaceTask GraphicalInterfaceTask;
extern TLcdInterface LcdInterface;
extern TMenuMain MenuMain;
extern TMenuSetups MenuSetups;
extern TMenuMenu MenuMenu;
extern TMenuSetupDate MenuSetupDate;
extern TMenuSetupDate MenuSetupDateTime;
extern TMenuEnterID MenuEnterID;
extern TMenuClock MenuClock;
extern TMenuSetupsUser1 MenuSetupsUser1;
extern TMenuSetupsUser2 MenuSetupsUser2;
/**********************************************************************************/

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGraphicalInterfaceTask::Execute(void *p)
{
  //EPressedButton pressedButton;
  //unsigned char flagPressedButton;
  
  //LcdInterface.Start();
  
  //GraphicalInterfaceTask.PerfomMenu(&MenuClock);
  //flagPressedButton= 0;
  
  while(true)
  {
    GraphicalInterfaceTask.Delay(100);
    
    /*
    if(flagPressedButton == 0) pressedButton= GraphicalInterfaceTask.CheckPressedButtons();
    
    switch(pressedButton)
    {
      case MENU_MAIN:
        GraphicalInterfaceTask.DrawMenu(&MenuMain);
        flagPressedButton= 0;
        break;
        
      case MENU_ENTER_ID:
        pressedButton= GraphicalInterfaceTask.PerfomMenu(&MenuEnterID);
        flagPressedButton= 1;
        break;
        
      case MENU_MENU:
        pressedButton= GraphicalInterfaceTask.PerfomMenu(&MenuMenu);
        flagPressedButton= 1;
        break;
      
      case MENU_SETUPS:
        GraphicalInterfaceTask.DrawMenu(&MenuSetups);
        flagPressedButton= 0;
        break;
        
      case MENU_SETUPS_DATE_TIME:
        pressedButton= GraphicalInterfaceTask.PerfomMenu(&MenuSetupDateTime);
        flagPressedButton= 1;
        break;
        
      case MENU_SETUPS_USER1:
        pressedButton= GraphicalInterfaceTask.PerfomMenu(&MenuSetupsUser1);
        flagPressedButton= 1;
        break;
        
      case MENU_SETUPS_USER2:
        pressedButton= GraphicalInterfaceTask.PerfomMenu(&MenuSetupsUser2);
        flagPressedButton= 1;
        break;
        
        
    }
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
EPressedButton TGraphicalInterfaceTask::CheckPressedButtons(void)
{
  return(this->MenuCurrent->CheckPressedButton());
}
//--- end DrawMenu -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
EPressedButton TGraphicalInterfaceTask::ExecuteMenu(TMenu* newMenu)
{
  this->MenuCurrent= newMenu;
  
  this->MenuCurrent->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
  this->MenuCurrent->Draw();
  
}
*/
//--- end ExecuteMenu --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGraphicalInterfaceTask::DrawMenu(TMenu* newMenu)
{
  this->MenuCurrent->WaitPullButton();
  
  this->MenuCurrent= newMenu;
  
  this->MenuCurrent->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
  this->MenuCurrent->Draw();
  
  
}
//--- end DrawMenu -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TGraphicalInterfaceTask::PerfomMenu(TMenu* newMenu)
{
  this->MenuCurrent->WaitPullButton();
  
  this->MenuCurrent= newMenu;
  
  this->MenuCurrent->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
  
  return(this->MenuCurrent->Perfom());
}
//--- end PerfomMenu -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGraphicalInterfaceTask::CreateTask(void)
{
  xTaskCreate(this->Execute, "GUI TASK", TASK_GUI_SIZE_STACK, NULL, TASK_GUI_PRIORITY, NULL);
}
//--- end CreateTask ---------------------------------------------------------------

/**********************************************************************************/
