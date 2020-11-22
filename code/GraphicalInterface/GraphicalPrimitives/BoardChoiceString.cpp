/**********************************************************************************/
/**
*  @file
*  BoardChoiceString.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "BoardChoiceString.hpp"
//#include "..\GraphicalPrimitives\BoardEnterString.hpp"

//TBoardChoiceString BoardChoiceString;
//extern TBoardEnterString BoardEnterString;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TBoardChoiceString::TBoardChoiceString(void)
{
  ButtonSetup.Create(20, 10, 440, 30);  // not active, used as label
  ButtonSetup.SetLabelText("Please ... .", 27);
  ButtonSetup.SetColor(LCD_COLOR_DARK_GREEN);
  
  Label1.Create(20, 50, 300, 27);
  Label1.SetString(" ", 27);
  Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
  
  Label2.Create(20, 77, 300, 27);
  Label2.SetString(" ", 27);
  Label2.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  Label3.Create(20, 104, 300, 27);
  Label3.SetString(" ", 27);
  Label3.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  Label4.Create(20, 131, 300, 27);
  Label4.SetString(" ", 27);
  Label4.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  Label5.Create(20, 158, 300, 27);
  Label5.SetString(" ", 27);
  Label5.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  Label6.Create(20, 185, 300, 27);
  Label6.SetString(" ", 27);
  Label6.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  Label7.Create(20, 212, 300, 27);
  Label7.SetString(" ", 27);
  Label7.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  Label8.Create(20, 239, 300, 27);
  Label8.SetString(" ", 27);
  Label8.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  ButtonUp.Create(340, 90, 120, 36);
  ButtonUp.SetLabelText("UP", 27);
  
  ButtonDown.Create(340, 130, 120, 36);
  ButtonDown.SetLabelText("DOWN", 27);
  
  ButtonEnter.Create(340, 170, 120, 36);
  ButtonEnter.SetLabelText("ENTER", 27);
  
  ButtonReturn.Create(340, 210, 120, 36);
  ButtonReturn.SetLabelText("RETURN", 27);
  
  this->indexOfString= 0;
  this->sizeMenu= 8;
  
}
//--- end TBoardChoiceString -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupTitleText(const char* s)
{
  ButtonSetup.SetLabelText(s, 27);
}
//--- end SetupTitleText -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupSizeMenu(unsigned char size)
{
  if(this->sizeMenu > 8) this->sizeMenu= 8;
  else
  {
    if(this->sizeMenu < 2) this->sizeMenu= 2;
    else this->sizeMenu= size;
  }
  
}
//--- end SetupSizeMenu ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString1Text(const char* s)
{
  Label1.SetString(s, 27);
}
//--- end SetupString1Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString2Text(const char* s)
{
  Label2.SetString(s, 27);
}
//--- end SetupString2Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString3Text(const char* s)
{
  Label3.SetString(s, 27);
}
//--- end SetupString3Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString4Text(const char* s)
{
  Label4.SetString(s, 27);
}
//--- end SetupString4Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString5Text(const char* s)
{
  Label5.SetString(s, 27);
}
//--- end SetupString5Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString6Text(const char* s)
{
  Label6.SetString(s, 27);
}
//--- end SetupString6Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString7Text(const char* s)
{
  Label7.SetString(s, 27);
}
//--- end SetupString7Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString8Text(const char* s)
{
  Label8.SetString(s, 27);
}
//--- end SetupString8Text ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  ButtonSetup.Draw();
  ButtonUp.Draw();
  ButtonDown.Draw();
  ButtonEnter.Draw();
  ButtonReturn.Draw();
  
  /*
  if(this->sizeMenu > 0) Label1.Draw();
  if(this->sizeMenu > 1) Label2.Draw();
  if(this->sizeMenu > 2) Label3.Draw();
  if(this->sizeMenu > 3) Label4.Draw();
  if(this->sizeMenu > 4) Label5.Draw();
  if(this->sizeMenu > 5) Label6.Draw();
  if(this->sizeMenu > 6) Label7.Draw();
  if(this->sizeMenu > 7) Label8.Draw();
  */
  
  Label1.Draw();
  Label2.Draw();
  Label3.Draw();
  Label4.Draw();
  Label5.Draw();
  Label6.Draw();
  Label7.Draw();
  Label8.Draw();
  
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
EPressedKeyboard TBoardChoiceString::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  //Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
  //Label2.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  //Label3.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  //Label4.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  //Label5.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  //Label6.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  //Label7.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  //Label8.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  
  this->Draw();
  
  while(true)
  {
    this->Delay(100);
    pressedButton= this->CheckPressedButton();
    
    if(pressedButton == KEYBOARD_RETURN) break;
    
    if(pressedButton == KEYBOARD_ENTER)
    {
      this->WaitPullButton();
      
      if(Label1.GetColorBackground() == LCD_COLOR_LIGHT_GREEN/*LCD_COLOR_LIGHT_GREEN*/) return(KEYBOARD_MENU_STRING1);
      if(Label2.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) return(KEYBOARD_MENU_STRING2);
      if(Label3.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) return(KEYBOARD_MENU_STRING3);
      if(Label4.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) return(KEYBOARD_MENU_STRING4);
      if(Label5.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) return(KEYBOARD_MENU_STRING5);
      if(Label6.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) return(KEYBOARD_MENU_STRING6);
      if(Label7.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) return(KEYBOARD_MENU_STRING7);
      if(Label8.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) return(KEYBOARD_MENU_STRING8);
      
    }
    
    if(pressedButton == KEYBOARD_UP) this->UpActiveString();
    if(pressedButton == KEYBOARD_DOWN) this->DownActiveString();
    
    this->WaitPullButton();
    this->Draw();
  
  }
  
  this->WaitPullButton();

  return(pressedButton);  
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::SetupString(unsigned char* string, unsigned char sizeString, const char* title)
{
  const char* pEnteredString;
  unsigned char i;
  EPressedKeyboard pressedKeyboard;
  
  BoardEnterString= new TBoardEnterString();

  BoardEnterString->SetMaxSizeEnteredString(sizeString);
  BoardEnterString->SetTitleString(title);
  BoardEnterString->SetEnterString((const char*)string);
  pressedKeyboard= BoardEnterString->Perfom();
  
  if(pressedKeyboard == KEYBOARD_OK)
  {
    pEnteredString= (const char*)BoardEnterString->GetEnteredString();
    for(i=0; i < strlen(pEnteredString)-1; i++) string[i]= pEnteredString[i];
    string[i]= 0;
  }
  
  delete(BoardEnterString);
  
  this->WaitPullButton();

}
//--- end SetupName ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::UpActiveString(void)
{
  if(Label1.GetColorBackground() == LCD_COLOR_LIGHT_GREEN/*LCD_COLOR_LIGHT_GREEN*/)
  {
    if(this->sizeMenu == 2) Label2.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    if(this->sizeMenu == 3) Label3.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    if(this->sizeMenu == 4) Label4.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    if(this->sizeMenu == 5) Label5.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    if(this->sizeMenu == 6) Label6.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    if(this->sizeMenu == 7) Label7.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    if(this->sizeMenu == 8) Label8.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label1.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }

  if(Label2.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label2.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(this->sizeMenu == 2) return;
  if(Label3.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label2.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label3.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(this->sizeMenu == 3) return;
  if(Label4.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label3.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label4.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(this->sizeMenu == 4) return;
  if(Label5.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label4.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label5.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(this->sizeMenu == 5) return;
  if(Label6.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label5.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label6.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(this->sizeMenu == 6) return;
  if(Label7.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label6.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label7.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(this->sizeMenu == 7) return;
  if(Label8.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label7.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label8.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  }
  
}
//--- end UpActiveString -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardChoiceString::DownActiveString(void)
{
  if(Label1.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label2.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label1.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(Label2.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    if(this->sizeMenu == 2) Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    else Label3.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label2.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(Label3.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    if(this->sizeMenu == 3) Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    else Label4.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label3.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(Label4.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    if(this->sizeMenu == 4) Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    else Label5.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label4.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(Label5.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    if(this->sizeMenu == 5) Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    else Label6.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label5.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(Label6.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    if(this->sizeMenu == 6) Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    else Label7.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label6.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(Label7.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    if(this->sizeMenu == 7) Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    else Label8.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label7.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
  if(Label8.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
  {
    Label1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
    Label8.SetColorBackground(LCD_COLOR_DARK_GRAY2);
    return;
  }
  
}
//--- end DownActiveString ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedKeyboard TBoardChoiceString::CheckPressedButton(void)
{
  unsigned long touchXY;
  unsigned short touchX;
  unsigned short touchY;
  
  touchXY= this->ReadRegTouchScreenXY();
  if(touchXY == 0x80008000) return(KEYBOARD_NOT_PRESSED);
  
  touchX= this->CalculateTouchX(touchXY);
  touchY= this->CalculateTouchY(touchXY);
  
  if(ButtonUp.CheckPress(touchX, touchY) > 0) return(KEYBOARD_UP);
  if(ButtonDown.CheckPress(touchX, touchY) > 0) return(KEYBOARD_DOWN);
  if(ButtonEnter.CheckPress(touchX, touchY) > 0) return(KEYBOARD_ENTER);
  if(ButtonReturn.CheckPress(touchX, touchY) > 0) return(KEYBOARD_RETURN);
  
  return(KEYBOARD_NOT_PRESSED);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
