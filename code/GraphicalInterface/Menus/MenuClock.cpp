/**********************************************************************************/
/**
*  @file
*  MenuClock.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuClock.hpp"
#include "..\GraphicalPrimitives\Clock.hpp"

TMenuClock MenuClock;
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
TMenuClock::TMenuClock(void)
{
  //Clock.Create(140, 135, 120, 11, 5, 12);
  //Clock.SetColor(LCD_COLOR_DARK_GRAY1);
  
  ButtonMenu.Create(95, 180, 276, 80);
  ButtonMenu.SetLabelText("MENU", 27);
  
  LabelDate.SetColorBackground(LCD_COLOR_DARK_GRAY2);
  LabelDate.SetColorText(LCD_COLOR_WHITE);
  LabelDate.SetString("24 March", 25);
  LabelDate.Create(95, 45, 276, 50);
  
  LabelHours.SetColorBackground(LCD_COLOR_DARK_GRAY1);
  LabelHours.SetColorText(LCD_COLOR_WHITE);
  LabelHours.SetString(Clock.GetHoursString(), 31);
  LabelHours.Create(95, 100, 80, 60);
  
  LabelSeparator1.SetColorBackground(LCD_COLOR_DARK_GRAY1);
  LabelSeparator1.SetColorText(LCD_COLOR_WHITE);
  LabelSeparator1.SetString(":", 31);
  LabelSeparator1.Create(169, 100, 30, 60);
  
  LabelMinutes.SetColorBackground(LCD_COLOR_DARK_GRAY1);
  LabelMinutes.SetColorText(LCD_COLOR_WHITE);
  LabelMinutes.SetString(Clock.GetMinutesString(), 31);
  LabelMinutes.Create(193, 100, 80, 60);
  
  LabelSeparator2.SetColorBackground(LCD_COLOR_DARK_GRAY1);
  LabelSeparator2.SetColorText(LCD_COLOR_WHITE);
  LabelSeparator2.SetString(":", 31);
  LabelSeparator2.Create(267, 100, 30, 60);
  
  LabelSeconds.SetColorBackground(LCD_COLOR_DARK_GRAY1);
  LabelSeconds.SetColorText(LCD_COLOR_WHITE);
  LabelSeconds.SetString(Clock.GetSecondsString(), 31);
  LabelSeconds.Create(291, 100, 80, 60);
  
  
  
  
  
}
//--- end TMenuMain ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuClock::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  //Clock.Draw();
  ButtonMenu.Draw();
  LabelDate.Draw();
  LabelHours.Draw();
  LabelSeparator1.Draw();
  LabelMinutes.Draw();
  LabelSeparator2.Draw();
  LabelSeconds.Draw();
  
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
EPressedButton TMenuClock::Perfom(void)
{
  unsigned char timeDraw;
  
  this->Draw();
  timeDraw= 0;
  
  while(true)
  {
    this->Delay(100);
    Clock.Tick();
    
    if(this->CheckPressedButton() == MENU_MAIN) break;
    
    timeDraw++;
    if(timeDraw == 10)
    {
      LabelHours.SetString(Clock.GetHoursString(), 31);
      LabelMinutes.SetString(Clock.GetMinutesString(), 31);
      LabelSeconds.SetString(Clock.GetSecondsString(), 31);
      
      
      
      this->Draw();
      timeDraw= 0;
    }
    
  }
  
  
  return(MENU_MAIN);  
}
//--- end Perfom -------------------------------------------------------------------
  
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuClock::CheckPressedButton(void)
{
  unsigned long touchXY;
  
  touchXY= this->ReadRegTouchScreenXY();
  if(touchXY == 0x80008000)
  {
    this->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
    return(MENU_NOT_PRESSED_BUTTON);
  }
  
  this->SetPressedButton(MENU_MAIN);
  return(MENU_MAIN);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
