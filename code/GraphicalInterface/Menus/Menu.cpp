/**********************************************************************************/
/**
*  @file
*  Menu.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Menu.hpp"

//TLedIndicator LedIndicator;


/**********************************************************************************/
EPressedButton TMenu::pressedButton;


/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenu::TMenu(void)
{
  //this->pressedButton= MENU_NOT_PRESSED_BUTTON;
}
//--- end TMenu --------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenu::SetPressedButton(EPressedButton button)
{
  this->pressedButton= button;
}
//--- end SetPressedButton ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenu::GetPressedButton(void)
{
  return(this->pressedButton);
}
//--- end GetPressedButton ---------------------------------------------------------



/**********************************************************************************/
