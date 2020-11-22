/**********************************************************************************/
/**
*  @file
*  MenuEnterID.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuEnterID.hpp"
//#include "..\GraphicalPrimitives\BoardEnterString.hpp"



TMenuEnterID MenuEnterID;
//extern TBoardEnterString BoardEnterString;

/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuEnterID::TMenuEnterID(void)
{
  
}
//--- end TMenuEnterID -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuEnterID::Draw(void)
{
  
  
  
  

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuEnterID::Perfom(void)
{
  EPressedKeyboard pressedKeyboard;
  
  
  BoardEnterString= new TBoardEnterString();
  
  BoardEnterString->SetMaxSizeEnteredString(20);
  BoardEnterString->SetTitleString("Please enter ID.");
  BoardEnterString->SetEnterString("");
  pressedKeyboard= BoardEnterString->Perfom();
  
  
  delete(BoardEnterString);
  
  if((pressedKeyboard) == KEYBOARD_OK) this->SetPressedButton(MENU_MENU);
  else this->SetPressedButton(MENU_MAIN);
  
  
  return(this->GetPressedButton());
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuEnterID::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
