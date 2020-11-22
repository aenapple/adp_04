/**********************************************************************************/
/**
*  @file
*  MenuSetups.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuSetups.hpp"


TMenuSetups MenuSetups;

/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuSetups::TMenuSetups(void)
{
  ButtonSetup.Create(30, 10, 410, 30);  // not active, used as label
  ButtonSetup.SetLabelText("Please setup.", 27);
  ButtonSetup.SetColor(LCD_COLOR_DARK_GREEN);
  
  //ButtonDate.Create(30, 70, 200, 50);
  //ButtonDate.SetLabelText("DATE & TIME", 27);
  
  //ButtonTime.Create(240, 70, 200, 50);
  //ButtonTime.SetLabelText("TIME", 27);
  
  ButtonDateTime.Create(30, 70, 200, 50);
  ButtonDateTime.SetLabelText("DATE & TIME", 27);
  
  ButtonUser1.Create(30, 130, 200, 50);
  ButtonUser1.SetLabelText("USER #1", 27);
  
  ButtonUser2.Create(30, 190, 200, 50);
  ButtonUser2.SetLabelText("USER #2", 27);
  
  //ButtonReturn.Create(240, 210, 200, 50);
  ButtonReturn.Create(340, 210, 120, 40);
  ButtonReturn.SetLabelText("RETURN", 27);

}
//--- end TMenuMain ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuSetups::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  ButtonSetup.Draw();
  //ButtonDate.Draw();
  //ButtonTime.Draw();
  ButtonDateTime.Draw();
  ButtonUser1.Draw();
  ButtonUser2.Draw();
  ButtonReturn.Draw();
  
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
EPressedButton TMenuSetups::Perfom(void)
{
  return(MENU_NOT_PRESSED_BUTTON);  
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuSetups::CheckPressedButton(void)
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
  
  if(ButtonReturn.CheckPress(touchX, touchY) > 0)
  {
    this->SetPressedButton(MENU_MAIN);
    return(MENU_MAIN);
  }
  
  if(ButtonDateTime.CheckPress(touchX, touchY) > 0)
  {
    this->SetPressedButton(MENU_SETUPS_DATE_TIME);
    return(MENU_SETUPS_DATE_TIME);
  }
  
  if(ButtonUser1.CheckPress(touchX, touchY) > 0)
  {
    this->SetPressedButton(MENU_SETUPS_USER1);
    return(MENU_SETUPS_USER1);
  }
  
  if(ButtonUser2.CheckPress(touchX, touchY) > 0)
  {
    this->SetPressedButton(MENU_SETUPS_USER2);
    return(MENU_SETUPS_USER2);
  }
  
  
  this->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
