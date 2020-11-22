/**********************************************************************************/
/**
*  @file
*  BoardSetupDateTime.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "BoardSetupDateTime.hpp"


TBoardSetupDateTime* BoardSetupDateTime;
/**********************************************************************************/



/**********************************************************************************/
const char TBoardSetupDateTime::converterTable[100][3]=
{
  "00", "01", "02", "03", "04", "05", "06", "07", "08", "09",
  "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
  "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
  "30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
  "40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
  "50", "51", "52", "53", "54", "55", "56", "57", "58", "59",
  "60", "61", "62", "63", "64", "65", "66", "67", "68", "69",
  "70", "71", "72", "73", "74", "75", "76", "77", "78", "79",
  "80", "81", "82", "83", "84", "85", "86", "87", "88", "89",
  "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"
};


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TBoardSetupDateTime::TBoardSetupDateTime(void)
{
  ButtonTitle.SetLabelText("Please ... .", 27);
  
  ButtonIncrement.SetLabelText("/\\", 30);
  ButtonDecrement.SetLabelText("\\/", 30);
  ButtonMoveLeft.SetLabelText("<", 31);
  ButtonMoveRight.SetLabelText(">", 31);
  ButtonOk.SetLabelText("OK", 27);
  
  LabelDigit1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
  LabelDigit1.SetColorText(LCD_COLOR_WHITE);
  LabelTextDigit1.SetColorBackground(LCD_COLOR_DARK_GREEN);
  LabelTextDigit1.SetColorText(LCD_COLOR_WHITE);
  
  LabelDigit2.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  LabelDigit2.SetColorText(LCD_COLOR_WHITE);
  LabelTextDigit2.SetColorBackground(LCD_COLOR_DARK_GREEN);
  LabelTextDigit2.SetColorText(LCD_COLOR_WHITE);
  
  LabelDigit3.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  LabelDigit3.SetColorText(LCD_COLOR_WHITE);
  LabelTextDigit3.SetColorBackground(LCD_COLOR_DARK_GREEN);
  LabelTextDigit3.SetColorText(LCD_COLOR_WHITE);
  
  LabelTextDigit1.SetString(" ", 16);
  LabelTextDigit2.SetString(" ", 16);
  LabelTextDigit3.SetString(" ", 16);
  
  this->digit1= 0;
  this->digit2= 0;
  this->digit3= 0;
  
}
//--- end TBoardSetupDateTime ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupDateTime::Init(unsigned char d1, unsigned char d2, unsigned char d3, const char* string1, const char* string2, const char* string3)
{
  LabelTextDigit1.SetString(string1, 16);
  LabelTextDigit2.SetString(string2, 16);
  LabelTextDigit3.SetString(string3, 16);
  
  this->digit1= d1;
  this->digit2= d2;
  this->digit3= d3;
}
//--- end Init ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupDateTime::Draw(const char* stringTitle)
{
  ButtonTitle.Create(55, 10, 360, 30);  // not active, used as label
  ButtonTitle.SetLabelText(stringTitle, 27);
  ButtonTitle.SetColor(LCD_COLOR_DARK_GREEN);
  
  ButtonIncrement.Create(200, 50, 70, 50);
  ButtonDecrement.Create(200, 200, 70, 50);
  ButtonMoveLeft.Create(55, 110, 70, 60);
  ButtonMoveRight.Create(345, 110, 70, 60);
  ButtonOk.Create(345, 200, 70, 50);
 
  LabelDigit1.Create(130, 110, 70, 60);
  LabelTextDigit1.Create(130, 170, 70, 20);
  
  LabelDigit2.Create(200, 110, 70, 60);
  LabelTextDigit2.Create(200, 170, 70, 20);
  
  LabelDigit3.Create(270, 110, 70, 60);
  LabelTextDigit3.Create(270, 170, 70, 20);
  
  this->Perfom();
  
}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupDateTime::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  LabelDigit1.SetString(this->GetDigit1String(), 29);
  LabelDigit2.SetString(this->GetDigit2String(), 29);
  LabelDigit3.SetString(this->GetDigit3String(), 29);
  
  ButtonTitle.Draw();
  ButtonIncrement.Draw();
  ButtonDecrement.Draw();
  ButtonMoveLeft.Draw();
  ButtonMoveRight.Draw();
  ButtonOk.Draw();
  
  LabelDigit1.Draw();
  LabelTextDigit1.Draw();
  LabelDigit2.Draw();
  LabelTextDigit2.Draw();
  LabelDigit3.Draw();
  LabelTextDigit3.Draw();
    
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
EPressedBoardButton TBoardSetupDateTime::Perfom(void)
{
  EPressedBoardButton pressedButton;
  
  this->Draw();
  
  while(true)
  {
    this->Delay(100);
    pressedButton= this->CheckPressedButton();
    
    if(pressedButton == BOARD_NOT_PRESSED_BUTTON) continue;
    if(pressedButton == BOARD_BUTTON_OK) break;
    
    switch(pressedButton)
    {
      case BOARD_BUTTON_LEFT:
        {
          if(LabelDigit3.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
          {
            LabelDigit3.SetColorBackground(LCD_COLOR_DARK_GRAY2);
            LabelDigit2.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
          }
          else
          {
            if(LabelDigit2.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
            {
              LabelDigit2.SetColorBackground(LCD_COLOR_DARK_GRAY2);
              LabelDigit1.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
            }
          }
        }
        break;
        
      case BOARD_BUTTON_RIGHT:
        {
          if(LabelDigit1.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
          {
            LabelDigit1.SetColorBackground(LCD_COLOR_DARK_GRAY2);
            LabelDigit2.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
          }
          else
          {
            if(LabelDigit2.GetColorBackground() == LCD_COLOR_LIGHT_GREEN)
            {
              LabelDigit2.SetColorBackground(LCD_COLOR_DARK_GRAY2);
              LabelDigit3.SetColorBackground(LCD_COLOR_LIGHT_GREEN);
            }
          }
        }
        break;
        
      case BOARD_BUTTON_INCREMENT:
        {
          if(LabelDigit1.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) this->IncrementDigit1();
          if(LabelDigit2.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) this->IncrementDigit2();
          if(LabelDigit3.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) this->IncrementDigit3();
        }
        break;
        
      case BOARD_BUTTON_DECREMENT:
        {
          if(LabelDigit1.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) this->DecrementDigit1();
          if(LabelDigit2.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) this->DecrementDigit2();
          if(LabelDigit3.GetColorBackground() == LCD_COLOR_LIGHT_GREEN) this->DecrementDigit3();
        }
        break;
        
    }
    
    this->WaitPullButton();
    LabelDigit1.SetString(this->GetDigit1String(), 29);
    LabelDigit2.SetString(this->GetDigit1String(), 29);
    LabelDigit3.SetString(this->GetDigit1String(), 29);
    this->Draw();
    
    
  }
  
  this->WaitPullButton();
    
  return(BOARD_BUTTON_OK);
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedBoardButton TBoardSetupDateTime::CheckPressedButton(void)
{
  unsigned long touchXY;
  unsigned short touchX;
  unsigned short touchY;
  
  touchXY= this->ReadRegTouchScreenXY();
  if(touchXY == 0x80008000) return(BOARD_NOT_PRESSED_BUTTON);
  
  touchX= this->CalculateTouchX(touchXY);
  touchY= this->CalculateTouchY(touchXY);
  
  if(ButtonOk.CheckPress(touchX, touchY) > 0) return(BOARD_BUTTON_OK);
  
  if(ButtonIncrement.CheckPress(touchX, touchY) > 0) return(BOARD_BUTTON_INCREMENT);
  if(ButtonDecrement.CheckPress(touchX, touchY) > 0) return(BOARD_BUTTON_DECREMENT);
  if(ButtonMoveLeft.CheckPress(touchX, touchY) > 0) return(BOARD_BUTTON_LEFT);
  if(ButtonMoveRight.CheckPress(touchX, touchY) > 0) return(BOARD_BUTTON_RIGHT);
  
  
  return(BOARD_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
const char* TBoardSetupDateTime::GetDigit1String(void)
{
  return(this->converterTable[this->digit1]);
}
//--- end GetDigit1String ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
const char* TBoardSetupDateTime::GetDigit2String(void)
{
  return(this->converterTable[this->digit2]);
}
//--- end GetDigit2String ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
const char* TBoardSetupDateTime::GetDigit3String(void)
{
  return(this->converterTable[this->digit3]);
}
//--- end GetDigit3String ----------------------------------------------------------

/**********************************************************************************/
