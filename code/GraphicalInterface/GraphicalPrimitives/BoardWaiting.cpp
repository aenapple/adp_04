/**********************************************************************************/
/**
*  @file
*  BoardWaiting.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "BoardWaiting.hpp"

//TBoardWaiting BoardWaiting;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TBoardWaiting::TBoardWaiting(void)
{

}
//--- end TBoardWaiting ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardWaiting::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  this->CommandText(160, 30, 30, 0, "Please wait...");
  this->CommandSpinner(240, 150, 0, 0);
  
  
  this->WriteCommandDisplay(LCD_RAM_CMD + this->ramCmdOffset);
  this->IncrementRamCmdOffset(4);
  
  this->CommandDlSwap();
  
  this->CommandExec();
  
  this->Delay(10);

}
//--- end Draw ---------------------------------------------------------------------

/**********************************************************************************/
