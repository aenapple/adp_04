/**********************************************************************************/
/**
*  @file
*  BoardSetupTime.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "BoardSetupTime.hpp"


TBoardSetupTime BoardSetupTime;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
TBoardSetupTime::TBoardSetupTime(void) : TBoardSetupDateTime()
{
    
}
//--- end TBoardSetupTime ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
/*
void TBoardSetupTime::Perfom(void)
{
  this->digit1++;
  if(this->digit1 > 23) this->digit1= 0;  // Hours
}
*/
//--- end Perfom -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupTime::IncrementDigit1(void)
{
  this->digit1++;
  if(this->digit1 > 23) this->digit1= 0;  // Hours
}
//--- end IncrementDigit1 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupTime::IncrementDigit2(void)
{
  this->digit2++;
  if(this->digit2 > 59) this->digit2= 0;  // Minutes
}
//--- end IncrementDigit2 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupTime::IncrementDigit3(void)
{
  this->digit3++;
  if(this->digit3 > 59) this->digit3= 0;  // Seconds
}
//--- end IncrementDigit3 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupTime::DecrementDigit1(void)
{
  if(this->digit1 == 0) this->digit1= 23;  // Hours
  else this->digit1--;
}
//--- end DecrementDigit1 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupTime::DecrementDigit2(void)
{
  if(this->digit2 == 0) this->digit2= 59;  // Munites
  else this->digit2--;
}
//--- end DecrementDigit2 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TBoardSetupTime::DecrementDigit3(void)
{
  if(this->digit3 == 0) this->digit3= 59;  // Seconds
  else this->digit3--;
}
//--- end DecrementDigit3 ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TBoardSetupTime::GetHours(void)
{
  return(this->digit1);
}
//--- end GetHours -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TBoardSetupTime::GetMinutes(void)
{
  return(this->digit2);
}
//--- end GetMinutes ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TBoardSetupTime::GetSeconds(void)
{
  return(this->digit3);
}
//--- end GetSeconds ---------------------------------------------------------------
  
/**********************************************************************************/
