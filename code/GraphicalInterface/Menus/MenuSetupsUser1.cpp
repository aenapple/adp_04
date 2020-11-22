/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser1.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsUser1.hpp"
#include "MenuSetupsLanguage.hpp"
#include "MenuSetupsDispensingTime.hpp"
#include "MenuSetupsUser1Monitoring.hpp"
#include "MenuSetupsEmergencyCallTime.hpp"
#include "MenuSetupsMedication.hpp"

TMenuSetupsUser1 MenuSetupsUser1;
extern TMenuSetupsLanguage MenuSetupsLanguage;
extern TMenuSetupsDispensingTime MenuSetupsDispensingTime;
extern TMenuSetupsUser1Monitoring MenuSetupsUser1Monitoring;
extern TMenuSetupsEmergencyCallTime MenuSetupsEmergencyCallTime;
extern TMenuSetupsMedication MenuSetupsMedication;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsUser1::TMenuSetupsUser1(void)
{
  /*
  BoardChoiceString.SetupTitleText("Please setup for User#1.");
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
//--- end TMenuSetupsUser1 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsUser1::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsUser1::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  BoardChoiceString= new TBoardChoiceString();
  
  BoardChoiceString->SetupTitleText("Please setup for User#1.");
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
        BoardChoiceString->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#1.");
        break;
        
      case KEYBOARD_MENU_STRING2:
        BoardChoiceString->SetupString(this->phoneHome, USER_PHONE_STRING_SIZE, "Please enter home phone for User#1.");
        break;
        
      case KEYBOARD_MENU_STRING3:
        BoardChoiceString->SetupString(this->stringCode, USER_CODE_STRING_SIZE, "Please enter four digits code for User#1.");
        break;
        
      case KEYBOARD_MENU_STRING4:
        MenuSetupsLanguage.Perfom();
        break;
        
      case KEYBOARD_MENU_STRING5:
        MenuSetupsDispensingTime.Perfom();
        break;
        
      case KEYBOARD_MENU_STRING6:
        MenuSetupsUser1Monitoring.Perfom();
        break;
        
      case KEYBOARD_MENU_STRING7:
        MenuSetupsEmergencyCallTime.Perfom();
        break;
        
      case KEYBOARD_MENU_STRING8:
        MenuSetupsMedication.Perfom();
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
EPressedButton TMenuSetupsUser1::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
