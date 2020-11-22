/**********************************************************************************/
/**
*  @file
*  MenuSetupsEmergencyCallTime.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupsEmergencyCallTime.hpp"
#include "..\GraphicalPrimitives\BoardSetupTime.hpp"
#include "..\GraphicalPrimitives\Clock.hpp"

TMenuSetupsEmergencyCallTime MenuSetupsEmergencyCallTime;
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
TMenuSetupsEmergencyCallTime::TMenuSetupsEmergencyCallTime(void)
{
  
}
//--- end TMenuSetupsEmergencyCallTime ---------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupsEmergencyCallTime::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupsEmergencyCallTime::Perfom(void)
{
  // Setup time. //
  BoardSetupTime.Init(Clock.GetHours(), Clock.GetMinutes(), Clock.GetSeconds(), "Hours", "Minutes", "Seconds");
  BoardSetupTime.Draw("Please setup time.");
  
  Clock.SetHours(BoardSetupTime.GetHours());
  Clock.SetMinutes(BoardSetupTime.GetMinutes());
  Clock.SetSeconds(BoardSetupTime.GetSeconds());
  
  
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
EPressedButton TMenuSetupsEmergencyCallTime::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
