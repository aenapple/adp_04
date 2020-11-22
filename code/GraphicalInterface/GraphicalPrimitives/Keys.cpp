/**********************************************************************************/
/**
*  @file
*  Keys.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Keys.hpp"



/**********************************************************************************/



/**********************************************************************************/
//const char TButton::defaultLabelText[8]= { "Default" };


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
TKeys::TKeys(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
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
void TKeys::Create(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
  this->xCoordinate= x;
  this->yCoordinate= y;
  this->width= w;
  this->height= h;
  
}
//--- end Create -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TKeys::SetDefaultColor(void)
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
void TKeys::SetColorBackground(unsigned long color)
{
  this->colorButton= color;
}
//--- end SetColorBackground -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TKeys::SetColorText(unsigned long color)
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
void TKeys::SetText(const char* text, unsigned char font)
{
  this->text= text;
  this->textFont= font;
  
  //or(int i=0; i < 12; i++) arrayText[i]= text[i];
  
}
//--- end SetText ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TKeys::Draw(void)
{
  //this->WriteCommandColorRGB(LCD_RAM_CMD + this->ramCmdOffset, this->colorText);  // set text color
  //this->IncrementRamCmdOffset(4);
  
  //this->CommandFgcolor(this->colorButton);  // set button color
  
  this->CommandKeys(this->xCoordinate, this->yCoordinate, this->width, this->height, this->textFont, 0, this->text);
  
}
//--- end Draw ----------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TKeys::CheckPress(unsigned short touchX, unsigned short touchY)
{
  unsigned short minX;
  unsigned short maxX;
  unsigned short minY;
  unsigned short maxY;
  unsigned char sizeString;
  unsigned short sizeOneKey;
  short i;
  unsigned char result;
  
  minX= this->xCoordinate;
  maxX= this->xCoordinate + this->width;
  minY= this->yCoordinate;
  maxY= this->yCoordinate + this->height;
  
  sizeString= strlen(this->text);
  sizeOneKey= this->width / sizeString;
  
  result= 0;
  if((touchX > minX) && (touchX < maxX) && (touchY > minY) && (touchY < maxY))
  {
    for(i=0; i < sizeString; i++)
    {
      if(touchX < (minX + sizeOneKey * (i+1)))
      {
        result= this->text[i];
        break;
      }
      
    }

  }
  
  return(result);  // 0 - no symbol.
}
//--- end CheckPress ---------------------------------------------------------------

/**********************************************************************************/
