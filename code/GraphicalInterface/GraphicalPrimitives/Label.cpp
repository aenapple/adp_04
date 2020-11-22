/**********************************************************************************/
/**
*  @file
*  Label.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Label.hpp"



/**********************************************************************************/



/**********************************************************************************/
const char TLabel::defaultText[8]= { "Default" };


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
TLabel::TLabel(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
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
//--- end TLabel -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLabel::Create(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
  this->xCoordinate= x;
  this->yCoordinate= y;
  this->width= w;
  this->height= h;
  
  // Default setting. //
  //this->SetDefaultColor();
  //this->SetLabelText(this->defaultLabelText, 27);

}
//--- end Create -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLabel::SetDefaultColor(void)
{
  this->SetColorBackground(LCD_COLOR_DARK_BLUE);
  this->SetColorText(LCD_COLOR_WHITE);
}
//--- end SetDefaultColor ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLabel::SetColorBackground(unsigned long color)
{
  this->colorBackground= color;
}
//--- end SetColorBackground -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned long TLabel::GetColorBackground(void)
{
  return(this->colorBackground);
}
//--- end GetColorBackground -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLabel::SetColorText(unsigned long color)
{
  this->colorText= color;
}
//--- end SetColorText -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLabel::SetString(const char* text, unsigned char font)
{
  this->string= text;
  this->stringFont= font;
}
//--- end SetString ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLabel::Draw(void)
{
  //if(this->colorText != LCD_COLOR_WHITE)
  //{
  //this->WriteCommandColorRGB(LCD_RAM_CMD + this->ramCmdOffset, this->colorText);  // set text color
  //this->IncrementRamCmdOffset(4);
  //}
  
  //if(this->colorBackground != LCD_COLOR_DARK_BLUE) 
  this->CommandFgcolor(this->colorBackground);  // set button color
  
  this->CommandButton(this->xCoordinate, this->yCoordinate, this->width, this->height, this->stringFont, 256, this->string);  // option sets OPT_FLAT(256) - Co-processor widget is drawn without 3D effect.
  
 // this->CommandColdstart();  // set default color
  
}
//--- end Draw ----------------------------------------------------------------------

/**********************************************************************************/
