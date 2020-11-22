/**********************************************************************************/
/**
*  @file
*  MenuSetupDateTime.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupDateTime.hpp"
#include "..\GraphicalPrimitives\BoardSetupDate.hpp"
#include "..\GraphicalPrimitives\BoardSetupTime.hpp"
#include "..\GraphicalPrimitives\Clock.hpp"

TMenuSetupDateTime MenuSetupDateTime;
extern TBoardSetupDate BoardSetupDate;
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
TMenuSetupDateTime::TMenuSetupDateTime(void)
{

}
//--- end TMenuSetupDateTime -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupDateTime::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupDateTime::Perfom(void)
{
  // Setup date. //
  BoardSetupDate.Init(Clock.GetDay(), Clock.GetMonth(), Clock.GetYear(), "Day", "Month", "Year");
  BoardSetupDate.Draw("Please setup date.");
  
  Clock.SetDay(BoardSetupDate.GetDay());
  Clock.SetMonth(BoardSetupDate.GetMonth());
  Clock.SetYear(BoardSetupDate.GetYear());

  // Setup time. //
  BoardSetupTime.Init(Clock.GetHours(), Clock.GetMinutes(), Clock.GetSeconds(), "Hours", "Minutes", "Seconds");
  BoardSetupTime.Draw("Please setup time.");
  
  Clock.SetHours(BoardSetupTime.GetHours());
  Clock.SetMinutes(BoardSetupTime.GetMinutes());
  Clock.SetSeconds(BoardSetupTime.GetSeconds());
  
  return(MENU_SETUPS);
}
//--- end Perfom -------------------------------------------------------------------
  
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupDateTime::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
