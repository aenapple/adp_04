/**********************************************************************************/
/**
*  @file
*  MenuSetupsDispensingTime.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsDispensingTime.hpp"
#include "..\GraphicalPrimitives\BoardSetupTime.hpp"
#include "..\GraphicalPrimitives\Clock.hpp"

TMenuSetupsDispensingTime MenuSetupsDispensingTime;
extern TBoardSetupTime BoardSetupTime;
extern TClock Clock;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetupsDispensingTime::TMenuSetupsDispensingTime(void)
{
  
}
//--- end TMenuSetupsDispensingTime ------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsDispensingTime::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsDispensingTime::Perfom(void)
{
  // Setup time. //
  BoardSetupTime.Init(Clock.GetHours(), Clock.GetMinutes(), Clock.GetSeconds(), "Hours", "Minutes", "Seconds");
  BoardSetupTime.Draw("Please setup time.");
  
  Clock.SetHours(BoardSetupTime.GetHours());
  Clock.SetMinutes(BoardSetupTime.GetMinutes());
  Clock.SetSeconds(BoardSetupTime.GetSeconds());
  
  BoardEnterString= new TBoardEnterString();
  
  BoardEnterString->SetMaxSizeEnteredString(30);
  BoardEnterString->SetTitleString("Please enter warning.");
  BoardEnterString->SetEnterString("");
  BoardEnterString->Perfom();
  
  
  delete(BoardEnterString);
  
  //if((pressedKeyboard) == KEYBOARD_OK) this->SetPressedButton(MENU_MENU);
  //else this->SetPressedButton(MENU_MAIN);
  
  
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
EPressedButton TMenuSetupsDispensingTime::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
