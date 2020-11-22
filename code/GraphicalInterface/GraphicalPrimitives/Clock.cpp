/**********************************************************************************/
/**
*  @file
*  Clock.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Clock.hpp"


TClock Clock;
/**********************************************************************************/



/**********************************************************************************/
//unsigned char TClock::hours;
//unsigned char TClock::minutes;
//unsigned char TClock::seconds;
//unsigned char TClock::mSeconds;

const char TClock::converterTable[100][3]=
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
TClock::TClock(void)
{
  this->hours= 11;
  this->minutes= 6;
  this->seconds= 0;
  this->mSeconds= 0;
  this->day= 1;
  this->month= 1;
  this->year= 14;
}
//--- end TClock -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::Tick(void)
{
  //this->mSeconds++;
  this->mSeconds += 100;  // DEBUG
  if(this->mSeconds > 999) { this->seconds++; this->mSeconds= 0; }
  if(this->seconds > 59) { this->minutes++; this->seconds= 0; }
  if(this->minutes > 59) { this->hours++; this->minutes= 0; }
  if(this->hours > 23) { this->day++; this->hours= 0; }
  
  if(this->month == 2)  // Feb
  {
    if(this->day > 28) { this->month++; this->day= 1; }
  }
  else
  {
    if((this->month == 1) || (this->month == 3) || (this->month == 5) || (this->month == 7) || (this->month == 8) || (this->month == 10) || (this->month == 12))
    {
      if(this->day > 31) { this->month++; this->day= 1; }
    }
    else
    {
      if(this->day > 30) { this->month++; this->day= 1; }
    }
  }
  
  if(this->month > 12) { this->year++; this->month= 1; }
  if(this->month > 99) { this->year= 0; }
  
}
//--- end Tick ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::Create(unsigned short x, unsigned short y, unsigned short r, unsigned char h, unsigned char m, unsigned char s)
{
  this->xCoordinate= x;
  this->yCoordinate= y;
  this->hours= h;
  this->minutes= m;
  this->seconds= s;
  this->radius= r;
  
  // Default setting. //
  this->SetDefaultColor();

}
//--- end Create -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetDefaultColor(void)
{
  this->SetColor(LCD_COLOR_DARK_BLUE);
}
//--- end SetDefaultColor ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetColor(unsigned long color)
{
  this->colorClock= color;
}
//--- end SetColor -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::Draw(void)
{
  unsigned char tempHours;
  
  if(this->hours > 11) tempHours= this->hours - 12;
  else tempHours= this->hours;
  
  if(this->colorClock != LCD_COLOR_DARK_BLUE) this->CommandBgcolor(this->colorClock);  // set clock color
  
  this->CommandClock(this->xCoordinate, this->yCoordinate, this->radius, tempHours, this->minutes, this->seconds, 0/*CLOCK_OPT_NOSECS*/);
  
}
//--- end Draw ----------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
const char* TClock::GetHoursString(void)
{
  return(this->converterTable[this->hours]);
}
//--- end GetHoursString -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
const char* TClock::GetMinutesString(void)
{
  return(this->converterTable[this->minutes]);
}
//--- end GetMinutesString ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
const char* TClock::GetSecondsString(void)
{
  return(this->converterTable[this->seconds]);
}
//--- end GetSecondsString ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TClock::GetHours(void)
{
  return(this->hours);
}
//--- end GetHours -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetHours(unsigned char h)
{
  this->hours= h;
}
//--- end SetHours -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TClock::GetMinutes(void)
{
  return(this->minutes);
}
//--- end GetMinutes ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetMinutes(unsigned char m)
{
  this->minutes= m;
}
//--- end SetMinutes ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TClock::GetSeconds(void)
{
  return(this->seconds);
}
//--- end GetSeconds ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetSeconds(unsigned char s)
{
  this->seconds= s;
}
//--- end SetSeconds ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TClock::GetDay(void)
{
  return(this->day);
}
//--- end GetDay -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetDay(unsigned char d)
{
  this->day= d;
}
//--- end SetDay -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TClock::GetMonth(void)
{
  return(this->month);
}
//--- end GetMonth -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetMonth(unsigned char m)
{
  this->month= m;
}
//--- end SetMonth -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TClock::GetYear(void)
{
  return(this->year);
}
//--- end GetYear ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::SetYear(unsigned char y)
{
  this->year= y;
}
//--- end SetYear ------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::IncrementHours(void)
{
  this->hours++;
  if(this->hours > 23) this->hours= 0;
}
//--- end IncrementHours -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::IncrementMinutes(void)
{
  this->minutes++;
  if(this->minutes > 59) this->minutes= 0;
}
//--- end IncrementMinutes ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::IncrementSeconds(void)
{
  this->seconds++;
  if(this->seconds > 59) this->seconds= 0;
}
//--- end IncrementSeconds ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::DecrementHours(void)
{
  if(this->hours == 0) this->hours= 23;
  else this->hours--;
}
//--- end DecrementHours -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::DecrementMinutes(void)
{
  if(this->minutes == 0) this->minutes= 59;
  else this->minutes--;
}
//--- end DecrementMinutes ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TClock::DecrementSeconds(void)
{
  if(this->seconds == 0) this->seconds= 59;
  else this->seconds--;
}
//--- end DecrementSeconds ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
const char* TClock::ConvertDigitToString(unsigned char digit)
{
  return(this->converterTable[digit]);
}
//--- end ConvertDigitToString -----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TClock::ConvertStringToDigit(const char* string)
{
  unsigned char i;
  
  for(i=0; i < 100; i++)
  {
    if(string == this->converterTable[i]) break;
  }
  
  return(i);
}
//--- end ConvertStringToDigit -----------------------------------------------------

/**********************************************************************************/
