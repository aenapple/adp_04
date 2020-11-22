/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser1Monitoring1.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsUser1Monitoring1.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"
#include "MenuSetupsLanguage.hpp"

TMenuSetupsUser1Monitoring1 MenuSetupsUser1Monitoring1;
extern TMenuSetupsLanguage MenuSetupsLanguage;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsUser1Monitoring1::TMenuSetupsUser1Monitoring1(void)
{

  
}
//--- end TMenuSetupsUser1Monitoring -----------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsUser1Monitoring1::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsUser1Monitoring1::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  BoardChoiceString= new TBoardChoiceString();
  
  BoardChoiceString->SetupTitleText("User#1 Monitoring, please choice.");
  BoardChoiceString->SetupString1Text("Name.");
  BoardChoiceString->SetupString2Text("Phone / Cell.");
  BoardChoiceString->SetupString3Text("Four digits code.");
  BoardChoiceString->SetupString4Text("Language.");
  BoardChoiceString->SetupSizeMenu(4);
  
  while(true)
  {
    pressedButton= BoardChoiceString->Perfom();
    
    if(pressedButton == KEYBOARD_NOT_PRESSED) continue;
    
    if(pressedButton == KEYBOARD_RETURN) break;
    
    switch(pressedButton)
    {
      case KEYBOARD_MENU_STRING1:
      case KEYBOARD_MENU_STRING2:
      case KEYBOARD_MENU_STRING3:
        {
          BoardEnterString= new TBoardEnterString();
  
          BoardEnterString->SetMaxSizeEnteredString(30);
          BoardEnterString->SetTitleString("User#1, Monitoring#1, please enter name.");
          BoardEnterString->SetEnterString("");
          BoardEnterString->Perfom();
  
          delete(BoardEnterString);
        }
        break;
        
      //case KEYBOARD_MENU_STRING2:
        //break;
        
      //case KEYBOARD_MENU_STRING3:
        //break;
        
      case KEYBOARD_MENU_STRING4:
        MenuSetupsLanguage.Perfom();
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
EPressedButton TMenuSetupsUser1Monitoring1::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
