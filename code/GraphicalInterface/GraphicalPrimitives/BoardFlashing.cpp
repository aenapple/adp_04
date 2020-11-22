/**********************************************************************************/
/**
*  @file
*  BoardFlashing.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "BoardFlashing.hpp"

//TBoardFlashing BoardFlashing;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TBoardFlashing::TBoardFlashing(void)
{
  ButtonFlashing.Create(150, 50, 170, 170);  // not active, used as label
  ButtonFlashing.SetLabelText(" ", 27);
  ButtonFlashing.SetColor(LCD_COLOR_DARK_GRAY1);

}
//--- end TBoardFlashing -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardFlashing::SetColor(unsigned long color)
{
  ButtonFlashing.SetColor(color);
}
//--- end SetColor -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardFlashing::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  ButtonFlashing.Draw();
  
  this->WriteCommandDisplay(LCD_RAM_CMD + this->ramCmdOffset);
  this->IncrementRamCmdOffset(4);
  
  this->CommandDlSwap();
  
  this->CommandExec();
  
  this->Delay(10);

}
//--- end Draw ---------------------------------------------------------------------

/**********************************************************************************/
