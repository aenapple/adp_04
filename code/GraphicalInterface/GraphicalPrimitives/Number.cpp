/**********************************************************************************/
/**
*  @file
*  Number.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Number.hpp"



/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
TNumber::TNumber(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
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
//--- end TNumber ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TNumber::Create(unsigned short x, unsigned short y)
{
  this->xCoordinate= x;
  this->yCoordinate= y;
  
  // Default setting. //
  this->number= 0;

}
//--- end Create -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
void TNumber::SetDefaultColor(void)
{
  this->SetColor(0x003870);
}
*/
//--- end SetDefaultColor ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TNumber::SetColor(unsigned long color)
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
void TNumber::SetNumber(unsigned long n, unsigned char f)
{
  this->number= n;
  this->fontString= f;
}
//--- end SetText ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TNumber::Draw(void)
{
  //if(this->colorString != 0x003870) this->CommandBgcolor(this->colorString);  // set clock color
  
  this->CommandNumber(this->xCoordinate, this->yCoordinate, this->fontString, 0, this->number);
  
}
//--- end Draw ----------------------------------------------------------------------


/**********************************************************************************/
