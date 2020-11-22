/**********************************************************************************/
/**
*  @file
*  MenuSetupDate.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetupDate.hpp"
#include "..\GraphicalPrimitives\BoardSetupDate.hpp"
#include "..\GraphicalPrimitives\Clock.hpp"

TMenuSetupDate MenuSetupDate;
extern TBoardSetupDate BoardSetupDate;
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
TMenuSetupDate::TMenuSetupDate(void)
{

}
//--- end TMenuSetupTime -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetupDate::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupDate::Perfom(void)
{
  BoardSetupDate.Init(Clock.GetDay(), Clock.GetMonth(), Clock.GetYear(), "Day", "Month", "Year");
  
  BoardSetupDate.Draw(40, 15);
  
  return(MENU_SETUPS);
}
//--- end Perfom -------------------------------------------------------------------
  
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetupDate::CheckPressedButton(void)
{
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
