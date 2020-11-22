/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser1Monitoring.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsUser1Monitoring.hpp"
#include "MenuSetupsUser1Monitoring1.hpp"

TMenuSetupsUser1Monitoring MenuSetupsUser1Monitoring;
extern TMenuSetupsUser1Monitoring1 MenuSetupsUser1Monitoring1;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsUser1Monitoring::TMenuSetupsUser1Monitoring(void)
{

  
}
//--- end TMenuSetupsUser1Monitoring -----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsUser1Monitoring::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsUser1Monitoring::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  BoardChoiceString= new TBoardChoiceString();
  
  BoardChoiceString->SetupTitleText("User#1 Monitoring, please choice.");
  BoardChoiceString->SetupString1Text("Monitoring#1");
  BoardChoiceString->SetupString2Text("Monitoring#2");
  BoardChoiceString->SetupString3Text("Monitoring#3");
  BoardChoiceString->SetupSizeMenu(3);
  
  while(true)
  {
    pressedButton= BoardChoiceString->Perfom();
    
    if(pressedButton == KEYBOARD_NOT_PRESSED) continue;
    
    if(pressedButton == KEYBOARD_RETURN) break;
    
    switch(pressedButton)
    {
      case KEYBOARD_MENU_STRING1:
        MenuSetupsUser1Monitoring1.Perfom();
        break;
        
      case KEYBOARD_MENU_STRING2:
        //MenuSetupsUser1Monitoring2.Perfom();
        break;
        
      case KEYBOARD_MENU_STRING3:
        //MenuSetupsUser1Monitoring3.Perfom();
        break;
        
    }
    
    
  }
  
  delete(BoardChoiceString);
  this->WaitPullButton();

  this->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
  return(MENU_NOT_PRESSED_BUTTON);  
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsUser1Monitoring::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
