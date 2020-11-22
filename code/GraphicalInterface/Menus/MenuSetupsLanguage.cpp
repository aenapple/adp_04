/**********************************************************************************/
/**
*  @file
*  MenuSetupsLanguage.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsLanguage.hpp"


TMenuSetupsLanguage MenuSetupsLanguage;
/**********************************************************************************/
const char TMenuSetupsLanguage::languageStrings[LANGUAGE_LAST_ELEMENT][15]=
{
  "English.      ",
  "Russian.      ",
  "French.       ",
};


/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsLanguage::TMenuSetupsLanguage(void)
{
  this->indexOfLanguage= ENGLISH;
}
//--- end TMenuSetupsUser1 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsLanguage::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsLanguage::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  BoardChoiceString= new TBoardChoiceString();
  
  BoardChoiceString->SetupTitleText("Please setup language for User#1.");
  BoardChoiceString->SetupString1Text(this->languageStrings[ENGLISH]);
  BoardChoiceString->SetupString2Text(this->languageStrings[RUSSIAN]);
  BoardChoiceString->SetupString3Text(this->languageStrings[FRENCH]);
  BoardChoiceString->SetupSizeMenu(3);
  
  while(true)
  {
    pressedButton= BoardChoiceString->Perfom();
    
    if(pressedButton == KEYBOARD_NOT_PRESSED) continue;
    
    if(pressedButton == KEYBOARD_RETURN) break;
    
    switch(pressedButton)
    {
      case KEYBOARD_MENU_STRING1:
        this->indexOfLanguage= ENGLISH;
        break;
        
      case KEYBOARD_MENU_STRING2:
        this->indexOfLanguage= RUSSIAN;
        break;
        
      case KEYBOARD_MENU_STRING3:
        this->indexOfLanguage= FRENCH;
        break;
        
    }
    
    break;
    
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
EPressedButton TMenuSetupsLanguage::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
