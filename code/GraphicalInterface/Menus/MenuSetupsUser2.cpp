/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser2.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsUser2.hpp"
//#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

TMenuSetupsUser2 MenuSetupsUser2;
//extern TBoardChoiceString BoardChoiceString;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsUser2::TMenuSetupsUser2(void)
{
  /*
  BoardChoiceString.SetupTitleText("Please setup for User#2.");
  BoardChoiceString.SetupString1Text("Name.");
  BoardChoiceString.SetupString2Text("Phone / Cell.");
  BoardChoiceString.SetupString3Text("Four digits code.");
  BoardChoiceString.SetupString4Text("Language.");
  BoardChoiceString.SetupString5Text("Dispensing time & warning.");
  BoardChoiceString.SetupString6Text("Monitoring.");
  BoardChoiceString.SetupString7Text("Setup emergency call time.");
  BoardChoiceString.SetupString8Text("Medication schedule.");
  BoardChoiceString.SetupSizeMenu(8);
  */
  
  
  this->name[0]= 0;
  this->phoneHome[0]= 0;
  this->phoneCell[0]= 0;
  this->stringCode[0]= 0;
  this->emergencyCallHours= 0;
  this->emergencyCallMinutes= 0;
  this->emergencyCallSeconds= 0;
  
}
//--- end TMenuSetupsUser2 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsUser2::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsUser2::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  BoardChoiceString= new TBoardChoiceString;
  
  BoardChoiceString->SetupTitleText("Please setup for User#2.");
  BoardChoiceString->SetupString1Text("Name.");
  BoardChoiceString->SetupString2Text("Phone / Cell.");
  BoardChoiceString->SetupString3Text("Four digits code.");
  BoardChoiceString->SetupString4Text("Language.");
  BoardChoiceString->SetupString5Text("Dispensing time & warning.");
  BoardChoiceString->SetupString6Text("Monitoring.");
  BoardChoiceString->SetupString7Text("Setup emergency call time.");
  BoardChoiceString->SetupString8Text("Medication schedule.");
  BoardChoiceString->SetupSizeMenu(8);
  
  while(true)
  {
    pressedButton= BoardChoiceString->Perfom();
    
    if(pressedButton == KEYBOARD_RETURN) break;
    
    switch(pressedButton)
    {
      case KEYBOARD_MENU_STRING1:
        BoardChoiceString->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#2.");
        break;
        
      case KEYBOARD_MENU_STRING2:
        BoardChoiceString->SetupString(this->phoneHome, USER_PHONE_STRING_SIZE, "Please enter home phone for User#2.");
        break;
        
      case KEYBOARD_MENU_STRING3:
        BoardChoiceString->SetupString(this->stringCode, USER_CODE_STRING_SIZE, "Please enter four digits code for User#2.");
        break;
        
      case KEYBOARD_MENU_STRING4:
        //this->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#1.");
        break;
        
      case KEYBOARD_MENU_STRING5:
        //this->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#1.");
        break;
        
      case KEYBOARD_MENU_STRING6:
        //this->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#1.");
        break;
        
      case KEYBOARD_MENU_STRING7:
        //this->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#1.");
        break;
        
      case KEYBOARD_MENU_STRING8:
        //this->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#1.");
        break;
      
    }
  
    
  }
  
  delete(BoardChoiceString);
  this->WaitPullButton();

  this->SetPressedButton(MENU_SETUPS);
  return(MENU_SETUPS);  
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsUser2::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
