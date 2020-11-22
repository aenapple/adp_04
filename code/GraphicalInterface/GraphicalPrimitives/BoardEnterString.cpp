/**********************************************************************************/
/**
*  @file
*  BoardEnterString.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "BoardEnterString.hpp"


//TBoardEnterString BoardEnterString;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TBoardEnterString::TBoardEnterString(void)
{
  ButtonEnter.Create(20, 10, 440, 30);  // not active, used as label
  ButtonEnter.SetLabelText("Please enter ... .", 27);
  ButtonEnter.SetColor(LCD_COLOR_DARK_GREEN);
  
  this->indexString= 0;
  this->string[this->indexString]= '_';
  this->string[this->indexString+1]= 0;
  
  LabelString.Create(20, 50, 440, 30);
  LabelString.SetString((const char*)this->string, 27);
  LabelString.SetColorBackground(LCD_COLOR_DARK_GRAY2/*LCD_COLOR_DARK_GREEN*/);
  
  this->sizeString= BOARD_ENTER_STRING_SIZE_MAX - 2;
  
}
//--- end TBoardEnterString --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardEnterString::SetTitleString(const char* s)
{
  ButtonEnter.SetLabelText(s, 27);
}
//--- end SetTitleString -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardEnterString::SetMaxSizeEnteredString(unsigned char sizeString)
{
  if(sizeString > (BOARD_ENTER_STRING_SIZE_MAX - 2)) this->sizeString= BOARD_ENTER_STRING_SIZE_MAX - 2;
  else this->sizeString= sizeString;
}
//--- end SetMaxSizeEnteredString --------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardEnterString::SetEnterString(const char* s)
{
  //if(strlen(s) > (BOARD_ENTER_STRING_SIZE_MAX-2)) this->indexString= BOARD_ENTER_STRING_SIZE_MAX - 1;
  if(strlen(s) > this->sizeString) this->indexString= this->sizeString + 1;
  else
  {
    if(strlen(s) == 0) this->indexString= 0;
    else this->indexString= strlen(s);
  }
  
  for(int i=0; i < this->indexString; i++) this->string[i]= s[i];
  
  this->string[this->indexString]= '_';
  this->string[this->indexString+1]= 0;
}
//--- end SetEnterString -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardEnterString::Draw(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_DARK_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  ButtonEnter.Draw();
  LabelString.Draw();
  Keyboard.Draw(20, 90);
  
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
EPressedKeyboard TBoardEnterString::Perfom(void)
{
  unsigned char timerCursor;
  EPressedKeyboard pressedKeyboard;
  unsigned char readCharapter[2];
  
  Keyboard.SetActiveTypeKeyboard(KEYBOARD_SMALL_CHARAPTERS);
  this->Draw();
  timerCursor= 0;
  
  while(true)
  {
    this->Delay(100);
    timerCursor++;
    if(timerCursor == 5)
    {
      this->string[this->indexString]= '_';
      this->string[this->indexString+1]= 0;
      LabelString.SetString((const char*)this->string, 27);
      this->Draw();
    }
    if(timerCursor == 10)
    {
      this->string[this->indexString]= ' ';
      this->string[this->indexString+1]= 0;
      LabelString.SetString((const char*)this->string, 27);
      this->Draw();
      timerCursor= 0;
    }
    
    pressedKeyboard= this->CheckButtons(readCharapter);
    
    if((pressedKeyboard == KEYBOARD_CANCEL) || (pressedKeyboard == KEYBOARD_OK)) break;
    
    if((pressedKeyboard == KEYBOARD_SHIFT) || (pressedKeyboard == KEYBOARD_SWITCH) || (pressedKeyboard == KEYBOARD_SPACE) || (pressedKeyboard == KEYBOARD_BACKSPACE))
    {
      this->Draw();
      continue;
    }
    
    if((pressedKeyboard == KEYBOARD_NOT_PRESSED) && (readCharapter[0] == 0)) continue;
    else this->Draw();
    
  }
  
  
  return(pressedKeyboard);
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedKeyboard TBoardEnterString::CheckButtons(unsigned char* charapter)
{
  EPressedKeyboard pressedKeyboard;
  
  pressedKeyboard= Keyboard.CheckPressedButton(charapter);
  if((pressedKeyboard == KEYBOARD_NOT_PRESSED) && (charapter[0] == 0)) return(pressedKeyboard);
    
  this->WaitPullButton();
  
  if((pressedKeyboard == KEYBOARD_NOT_PRESSED) && (charapter[0] > 0))
  {
    this->AppendCharapter(charapter[0]);
    return(pressedKeyboard);
  }
    
  //if((pressedKeyboard == KEYBOARD_CANCEL) || (pressedKeyboard == KEYBOARD_OK)) return(pressedKeyboard);

  switch(pressedKeyboard)
  {
    case KEYBOARD_CANCEL:
      //this->SetPressedButton(MENU_MAIN);
      break;
      
    case KEYBOARD_OK:
      //this->SetPressedButton(MENU_MENU);
      break;
    
    case KEYBOARD_SHIFT:
      {
        if(Keyboard.GetActiveTypeKeyboard() == KEYBOARD_SMALL_CHARAPTERS) Keyboard.SetActiveTypeKeyboard(KEYBOARD_LARGE_CHARAPTERS);
        else
        {
          if(Keyboard.GetActiveTypeKeyboard() == KEYBOARD_LARGE_CHARAPTERS) Keyboard.SetActiveTypeKeyboard(KEYBOARD_SMALL_CHARAPTERS);
        }
      }
      break;
        
    case KEYBOARD_SWITCH:
      {
        if(Keyboard.GetActiveTypeKeyboard() == KEYBOARD_SYMBOLS) Keyboard.SetActiveTypeKeyboard(KEYBOARD_SMALL_CHARAPTERS);
        else Keyboard.SetActiveTypeKeyboard(KEYBOARD_SYMBOLS);
      }
      break;
      
    case KEYBOARD_SPACE: this->AppendCharapter(' '); break;

    case KEYBOARD_BACKSPACE: this->RemoveCharapter(); break;
      
      
  }
    

  return(pressedKeyboard);
}
//--- end CheckButtons -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardEnterString::AppendCharapter(unsigned char charapter)
{
  //if(this->indexString == (BOARD_ENTER_STRING_SIZE_MAX-2)) return;
  if(this->indexString == this->sizeString) return;
  
  this->string[this->indexString]= charapter;
  this->string[this->indexString+1]= 0;  // end of string
  
  this->indexString++;
  
  LabelString.SetString((const char*)this->string, 27);
  
}
//--- end AppendCharapter ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardEnterString::RemoveCharapter(void)
{
  if(this->indexString == 0) return;
  
  this->indexString--;
  this->string[this->indexString+1]= 0;  // end of string
  LabelString.SetString((const char*)this->string, 27);
}
//--- end RemoveCharapter ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char* TBoardEnterString::GetEnteredString(void)
{
  return(this->string);
}
//--- end GetEnteredString ---------------------------------------------------------

/**********************************************************************************/
