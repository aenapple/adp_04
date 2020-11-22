/**********************************************************************************/
/**
*  @file
*  MenuDoseEnterID.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuDoseEnterID.hpp"
//#include "..\GraphicalPrimitives\BoardEnterString.hpp"



TMenuDoseEnterID MenuDoseEnterID;


/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuDoseEnterID::TMenuDoseEnterID(void)
{
  
}
//--- end TMenuDoseEnterID ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuDoseEnterID::Draw(void)
{
  
  
  
  

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuDoseEnterID::Perfom(void)
{
  /*
  EPressedKeyboard pressedKeyboard;
  
  
  BoardEnterString= new TBoardEnterString();
  
  BoardEnterString->SetMaxSizeEnteredString(20);
  BoardEnterString->SetTitleString("Please enter ID.");
  BoardEnterString->SetEnterString("");
  pressedKeyboard= BoardEnterString->Perfom();
  
  
  delete(BoardEnterString);
  
  if((pressedKeyboard) == KEYBOARD_OK) this->SetPressedButton(MENU_MENU);
  else this->SetPressedButton(MENU_MAIN);
  */
  
  return(this->GetPressedButton());
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuDoseEnterID::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
