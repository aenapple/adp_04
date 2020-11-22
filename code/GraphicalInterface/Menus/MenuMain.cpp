/**********************************************************************************/
/**
*  @file
*  MenuMain.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuMain.hpp"

TMenuMain MenuMain;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuMain::TMenuMain(void)
{
  ButtonSetups.Create(50, 50, 170, 170);
  //ButtonSetups.Create(10, 192, 230, 70);  // DEBUG
  ButtonSetups.SetLabelText("SETUPS", 29);
  
  ButtonMenu.Create(260, 50, 170, 170);
  //ButtonMenu.Create(240, 10, 230, 70);  // DEBUG
  ButtonMenu.SetLabelText("MENU", 29);
  
  // DEBUG //
  //NumberXCoordinate.Create(50, 50);
  //NumberXCoordinate.SetNumber(50, 27);
  //NumberYCoordinate.Create(50, 100);
  //NumberYCoordinate.SetNumber(50, 27);
  
}
//--- end TMenuMain ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuMain::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1/*LCD_COLOR_LIGHT_GRAY1*/);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  ButtonSetups.Draw();
  ButtonMenu.Draw();
  
  // DEBUG //
  //NumberXCoordinate.Draw();
  //NumberYCoordinate.Draw();
  
  this->WriteCommandDisplay(LCD_RAM_CMD + this->ramCmdOffset);
  this->IncrementRamCmdOffset(4);
  
  this->CommandDlSwap();
  
  this->CommandExec();
  
  this->Delay(10);
  
}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuMain::Perfom(void)
{
  /*
  unsigned long touchXY;
  unsigned short touchX;
  unsigned short touchY;
  
  this->Draw();
  
  while(true)
  {
    this->Delay(100);
    
    touchXY= this->ReadRegTouchScreenXY();
    if(touchXY == 0x80008000) continue;
    
  
    touchX= this->CalculateTouchX(touchXY);
    touchY= this->CalculateTouchY(touchXY);
  
    NumberXCoordinate.SetNumber(touchX, 27);
    NumberYCoordinate.SetNumber(touchY, 27);
    
    this->Draw();
    
  }
  */
  
  
  return(MENU_NOT_PRESSED_BUTTON);  
}
//--- end Perfom -------------------------------------------------------------------
  
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuMain::CheckPressedButton(void)
{
  unsigned long touchXY;
  unsigned short touchX;
  unsigned short touchY;
  
  touchXY= this->ReadRegTouchScreenXY();
  if(touchXY == 0x80008000)
  {
    this->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
    return(MENU_NOT_PRESSED_BUTTON);
  }
  
  touchX= this->CalculateTouchX(touchXY);
  touchY= this->CalculateTouchY(touchXY);
  
  if(ButtonSetups.CheckPress(touchX, touchY) > 0)
  {
    this->SetPressedButton(MENU_SETUPS);
    return(MENU_SETUPS);
  }
  
  if(ButtonMenu.CheckPress(touchX, touchY) > 0)
  {
    this->SetPressedButton(MENU_ENTER_ID);
    return(MENU_ENTER_ID);
  }
  
  
  this->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
