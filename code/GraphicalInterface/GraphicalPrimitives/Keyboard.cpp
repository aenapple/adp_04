/**********************************************************************************/
/**
*  @file
*  Keyboard.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Keyboard.hpp"


TKeyboard Keyboard;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TKeyboard::TKeyboard(void)
{
  this->ButtonCancel.SetLabelText("Cancel", 18);
  this->ButtonOk.SetLabelText("OK", 18);
  this->ButtonShift.SetLabelText("Shift", 18);
  this->ButtonSwitch.SetLabelText("Sym", 18);
  this->ButtonSpace.SetLabelText(" ", 18);
  this->ButtonBackspace.SetLabelText("<=", 18);

  this->activeTypeKeyboard= KEYBOARD_SMALL_CHARAPTERS;
  
  this->KeysDigits.SetText("1234567890", 27);
  this->KeysCharapter1.SetText("qwertyuiop", 27);
  this->KeysCharapter1.SetText("asdfghjkl", 27);
  this->KeysCharapter1.SetText("zxcvbnm", 27);
  
}
//--- end TKeyboard ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TKeyboard::Draw(unsigned short x, unsigned short y)
{
  //this->CommandColdstart();  // set default color
  
  this->WriteCommandColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_WHITE);
  this->IncrementRamCmdOffset(4);
  this->CommandFgcolor(LCD_COLOR_DARK_GRAY1);  // set keys color
  
  this->KeysDigits.Create(x, y, 440, 30);
  this->KeysCharapter1.Create(x, y+35, 440, 30);
  this->KeysCharapter2.Create(x+20, y+70, 396, 30);
  this->KeysCharapter3.Create(x+65, y+105, 308, 30);
  
  if(this->activeTypeKeyboard == KEYBOARD_SYMBOLS)
  {
    this->KeysCharapter1.SetText("{}[],.?!:;", 27);
    this->KeysCharapter2.SetText("<>/|-_=+'", 27);
    this->KeysCharapter3.SetText("@#$%&*^", 27);
  }
  else
  {
    if(this->activeTypeKeyboard == KEYBOARD_LARGE_CHARAPTERS)
    {
      this->KeysCharapter1.SetText("QWERTYUIOP", 27);
      this->KeysCharapter2.SetText("ASDFGHJKL", 27);
      this->KeysCharapter3.SetText("ZXCVBNM", 27);
    }
    else
    {
      this->KeysCharapter1.SetText("qwertyuiop", 27);
      this->KeysCharapter2.SetText("asdfghjkl", 27);
      this->KeysCharapter3.SetText("zxcvbnm", 27);
    }
  }
  
  this->KeysDigits.Draw();
  this->KeysCharapter1.Draw();
  this->KeysCharapter2.Draw();
  this->KeysCharapter3.Draw();
  
  //this->CommandColdstart();  // set default color

  ButtonCancel.Create(x, y+140, 60, 30);
  ButtonCancel.Draw();
  
  ButtonOk.Create(x+380, y+140, 60, 30);
  ButtonOk.Draw();
  
  ButtonShift.Create(x, y+105, 60, 30);
  ButtonShift.Draw();
  
  ButtonSwitch.Create(x+65, y+140, 60, 30);
  ButtonSwitch.Draw();
  
  ButtonSpace.Create(x+130, y+140, 245, 30);
  ButtonSpace.Draw();
  
  ButtonBackspace.Create(x+380, y+105, 60, 30);
  ButtonBackspace.Draw();
 
  this->CommandColdstart();  // set default color
  
}
//--- end Draw ----------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedKeyboard TKeyboard::CheckPressedButton(unsigned char* charapter)
{
  unsigned long touchXY;
  unsigned short touchX;
  unsigned short touchY;
  unsigned char readCharapter;
  
  charapter[0]= 0;
  
  touchXY= this->ReadRegTouchScreenXY();
  if(touchXY == 0x80008000) return(KEYBOARD_NOT_PRESSED);
  
  touchX= this->CalculateTouchX(touchXY);
  touchY= this->CalculateTouchY(touchXY);
  
  if(ButtonCancel.CheckPress(touchX, touchY) > 0) return(KEYBOARD_CANCEL);
  if(ButtonOk.CheckPress(touchX, touchY) > 0) return(KEYBOARD_OK);
  if(ButtonShift.CheckPress(touchX, touchY) > 0) return(KEYBOARD_SHIFT);
  if(ButtonSwitch.CheckPress(touchX, touchY) > 0) return(KEYBOARD_SWITCH);
  if(ButtonSpace.CheckPress(touchX, touchY) > 0) return(KEYBOARD_SPACE);
  if(ButtonBackspace.CheckPress(touchX, touchY) > 0) return(KEYBOARD_BACKSPACE);
  
  readCharapter= this->KeysDigits.CheckPress(touchX, touchY);
  if(readCharapter == 0)
  {
    readCharapter= this->KeysCharapter1.CheckPress(touchX, touchY);
    if(readCharapter == 0)
    {
      readCharapter= this->KeysCharapter2.CheckPress(touchX, touchY);
      if(readCharapter == 0)
      {
        readCharapter= this->KeysCharapter3.CheckPress(touchX, touchY);
      }
      
    }
    
  }
  
  charapter[0]= readCharapter;
  
  return(KEYBOARD_NOT_PRESSED);
}
//--- end CheckPressedButton -------------------------------------------------------



//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TKeyboard::SetActiveTypeKeyboard(unsigned char type)
{
  this->activeTypeKeyboard= type;
}
//--- end SetActiveTypeKeyboard ----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
unsigned char TButton::CheckPressedKeys1(unsigned short touchX, unsigned short touchY)
{
  unsigned short minX;
  unsigned short maxX;
  unsigned short minY;
  unsigned short maxY;
  
  minX= this->xCoordinate;
  maxX= this->xCoordinate + this->width;
  minY= this->yCoordinate;
  maxY= this->yCoordinate + this->height;
  
  if((touchX > minX) && (touchX < maxX) && (touchY > minY) && (touchY < maxY)) return(1);  // YES
  
  return(0);  // NO
}
*/
//--- end CheckPress ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TKeyboard::GetActiveTypeKeyboard(void)
{
  return(this->activeTypeKeyboard);
}
//--- end GetActiveTypeKeyboard ----------------------------------------------------

/**********************************************************************************/
