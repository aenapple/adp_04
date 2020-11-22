/**********************************************************************************/
/**
*  @file
*  MenuSetupsMedication.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsMedication.hpp"


TMenuSetupsMedication MenuSetupsMedication;
/**********************************************************************************/


/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsMedication::TMenuSetupsMedication(void)
{
  
}
//--- end TMenuSetupsMedication ----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsMedication::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsMedication::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  BoardChoiceString= new TBoardChoiceString();
  
  BoardChoiceString->SetupTitleText("User#1, List of Medications.");
  BoardChoiceString->SetupString1Text("Medication#1");
  BoardChoiceString->SetupString2Text("Medication#2");
  BoardChoiceString->SetupString3Text("Medication#3");
  BoardChoiceString->SetupString4Text("Medication#4");
  BoardChoiceString->SetupString5Text("Medication#5");
  BoardChoiceString->SetupString6Text("Medication#6");
  BoardChoiceString->SetupString7Text("Medication#7");
  BoardChoiceString->SetupString8Text("Medication#8");
  BoardChoiceString->SetupSizeMenu(8);
  
  while(true)
  {
    pressedButton= BoardChoiceString->Perfom();
    
    if(pressedButton == KEYBOARD_NOT_PRESSED) continue;
    
    if(pressedButton == KEYBOARD_RETURN) break;
    
    switch(pressedButton)
    {
      case KEYBOARD_MENU_STRING1:
        break;
        
      case KEYBOARD_MENU_STRING2:
        break;
        
      case KEYBOARD_MENU_STRING3:
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
EPressedButton TMenuSetupsMedication::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
