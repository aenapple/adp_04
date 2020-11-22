/**********************************************************************************/
/**
*  @file
*  Button.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Button.hpp"



/**********************************************************************************/



/**********************************************************************************/
const char TButton::defaultLabelText[8]= { "Default" };


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
TButton::TButton(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
  this->xCoordinate= x;
  this->yCoordinate= y;
  this->width= w;
  this->height= h;
  
  // Default setting. //
  this->SetDefaultColor();
  this->SetLabelText(this->defaultLabelText, 27);

}
*/
//--- end TButton ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TButton::Create(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
  this->xCoordinate= x;
  this->yCoordinate= y;
  this->width= w;
  this->height= h;
  
  // Default setting. //
  this->SetDefaultColor();
  //this->SetLabelText(this->defaultLabelText, 27);

}
//--- end Create -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TButton::SetDefaultColor(void)
{
  this->SetColor(LCD_COLOR_DARK_BLUE);
  this->SetColorLabel(LCD_COLOR_WHITE);
}
//--- end SetDefaultColor ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TButton::SetColor(unsigned long color)
{
  this->colorButton= color;
}
//--- end SetColor -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TButton::SetColorLabel(unsigned long color)
{
  this->colorLabel= color;
}
//--- end SetColorLabel ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TButton::SetLabelText(const char* text, unsigned char font)
{
  this->labelText= text;
  this->labelFont= font;
}
//--- end SetLabelText -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TButton::Draw(void)
{
  //if(this->colorLabel != LCD_COLOR_WHITE)
  //{
    this->WriteCommandColorRGB(LCD_RAM_CMD + this->ramCmdOffset, this->colorLabel);  // set text color
    this->IncrementRamCmdOffset(4);
  //}
  
  //if(this->colorButton != LCD_COLOR_DARK_BLUE) 
    this->CommandFgcolor(this->colorButton);  // set button color
  
  this->CommandButton(this->xCoordinate, this->yCoordinate, this->width, this->height, this->labelFont, 0, this->labelText);
  
  //this->CommandColdstart();  // set default color
  
}
//--- end Draw ----------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TButton::CheckPress(unsigned short touchX, unsigned short touchY)
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
//--- end CheckPress ---------------------------------------------------------------

/**********************************************************************************/
