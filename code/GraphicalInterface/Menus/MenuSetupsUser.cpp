/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsUser.hpp"
//#include "..\GraphicalPrimitives\BoardEnterString.hpp"
//#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

//TMenuSetupsUser1 MenuSetupsUser1;
//extern TBoardEnterString BoardEnterString;
//extern TBoardChoiceString BoardChoiceString;
/**********************************************************************************/



/**********************************************************************************/
const char TMenuSetupsUser::stringPleaseSetup[]= { "Please setup" };
const char TMenuSetupsUser::stringForUser[]= { "for User" };
const char TMenuSetupsUser::stringName[]= { "Name." };
const char TMenuSetupsUser::stringPhoneCell[]= { "Phone / Cell." };
const char TMenuSetupsUser::stringFourDigitsCode[]= { "Four digits code." };
const char TMenuSetupsUser::stringLanguage[]= { "Language." };
const char TMenuSetupsUser::stringDispensingTimeWarning[]= { "Dispensing time & warning." };
const char TMenuSetupsUser::stringMonitoring[]= { "Monitoring." };
const char TMenuSetupsUser::stringSetupEmergencyCallTime[]= { "Setup emergency call time." };
const char TMenuSetupsUser::stringMedicationSchedule[]= { "Medication schedule." };

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsUser::TMenuSetupsUser(void)
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
void TMenuSetupsUser::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsUser::Perfom(void)
{
  EPressedKeyboard pressedButton;
  //unsigned char* stringPleaseSetup;
  
  BoardChoiceString= new TBoardChoiceString();
  
  BoardChoiceString->SetupTitleText(this->stringPleaseSetup);
  BoardChoiceString->SetupString1Text(this->stringName);
  BoardChoiceString->SetupString2Text(this->stringPhoneCell);
  BoardChoiceString->SetupString3Text(this->stringFourDigitsCode);
  BoardChoiceString->SetupString4Text(this->stringLanguage);
  BoardChoiceString->SetupString5Text(this->stringDispensingTimeWarning);
  BoardChoiceString->SetupString6Text(this->stringMonitoring);
  BoardChoiceString->SetupString7Text(this->stringSetupEmergencyCallTime);
  BoardChoiceString->SetupString8Text(this->stringMedicationSchedule);
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
        //this->SetupString(this->name, USER_NAME_STRING_SIZE_MAX, "Please enter name for User#1.");
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
EPressedButton TMenuSetupsUser::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
