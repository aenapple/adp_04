/**********************************************************************************/
/**
*  @file
*  Text.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Text.hpp"



/**********************************************************************************/



/**********************************************************************************/
const char TText::defaultLabelText[8]= { "Default" };


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
TClock::TClock(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
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
//--- end TClock -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TText::Create(unsigned short x, unsigned short y)
{
  this->xCoordinate= x;
  this->yCoordinate= y;
  
  // Default setting. //
  //this->SetDefaultColor();

}
//--- end Create -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TText::SetDefaultColor(void)
{
  this->SetColor(0x003870);
}
//--- end SetDefaultColor ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TText::SetColor(unsigned long color)
{
  this->colorString= color;
}
//--- end SetColor -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TText::SetString(const char* s, unsigned char f)
{
  this->string= s;
  this->fontString= f;
}
//--- end SetText ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TText::Draw(void)
{
  //if(this->colorString != 0x003870) this->CommandBgcolor(this->colorString);  // set clock color
  
  this->CommandText(this->xCoordinate, this->yCoordinate, this->fontString, 0, this->string);
  
}
//--- end Draw ----------------------------------------------------------------------


/**********************************************************************************/
