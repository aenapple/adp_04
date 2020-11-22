/**********************************************************************************/
/**
*  @file
*  MenuMenu.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "MenuMenu.hpp"


TMenuMenu MenuMenu;

/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TMenuMenu::TMenuMenu(void)
{
  

}
//--- end TMenuMenu ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TMenuMenu::Draw(void)
{

}
//--- end Draw ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuMenu::Perfom(void)
{
  EPressedKeyboard pressedButton;
  
  BoardChoiceString= new TBoardChoiceString();
  
  BoardChoiceString->SetupTitleText("Please choice.");
  BoardChoiceString->SetupString1Text("Replacing cassettes.");
  BoardChoiceString->SetupString2Text("Replenishing pills inside the unit.");
  BoardChoiceString->SetupString3Text("Dispensing.");
  BoardChoiceString->SetupString4Text("Medical data.");
  BoardChoiceString->SetupString5Text("Diagnistics.");
  BoardChoiceString->SetupSizeMenu(5);
  
  while(true)
  {
    pressedButton= BoardChoiceString->Perfom();
    
    if(pressedButton == KEYBOARD_RETURN) break;
    
    switch(pressedButton)
    {
      case KEYBOARD_MENU_STRING1:
        {
          BoardWaiting = new TBoardWaiting();
          BoardWaiting->Draw();
          this->Delay(10000);
          delete(BoardWaiting);
        }
        break;
        
      case KEYBOARD_MENU_STRING2:
        {
          BoardFlashing= new TBoardFlashing();
          for(int i=0; i < 10; i++)
          {
            BoardFlashing->SetColor(LCD_COLOR_WHITE);
            BoardFlashing->Draw();
            this->Delay(500);
            BoardFlashing->SetColor(LCD_COLOR_DARK_GRAY2);
            BoardFlashing->Draw();
            this->Delay(500);
          }
          delete(BoardFlashing);
          
        }
        break;
        
      case KEYBOARD_MENU_STRING3:
        {
          BoardFlashing= new TBoardFlashing();
          for(int i=0; i < 10; i++)
          {
            BoardFlashing->SetColor(LCD_COLOR_GREEN);
            BoardFlashing->Draw();
            this->Delay(500);
            BoardFlashing->SetColor(LCD_COLOR_RED);
            BoardFlashing->Draw();
            this->Delay(500);
          }
          delete(BoardFlashing);
          
        }
        break;
        break;
        
      case KEYBOARD_MENU_STRING4:
        //
        break;
        
      case KEYBOARD_MENU_STRING5:
        //
        break;
        
      
    }
  
    
  }
  
  delete(BoardChoiceString);
  this->WaitPullButton();

  this->SetPressedButton(MENU_MAIN);
  return(MENU_MAIN);
}
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
EPressedButton TMenuMenu::CheckPressedButton(void)
{
  this->SetPressedButton(MENU_NOT_PRESSED_BUTTON);
  return(MENU_NOT_PRESSED_BUTTON);
}
//--- end CheckPressedButton -------------------------------------------------------

/**********************************************************************************/
