/**********************************************************************************/
/**
*  @file
*  Clock.hpp - declaration of class TClock.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __ClockH
#define __ClockH

/**********************************************************************************/
#include "..\LcdInterface.hpp"


/**********************************************************************************/
#define CLOCK_OPT_NOSECS  0x8000
#define CLOCK_OPT_NOBACK  0x1000
#define CLOCK_OPT_NOHM    0x4000

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TClock : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  TClock(void);
  void Tick(void);
  void Create(unsigned short, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
  void SetDefaultColor(void);
  void SetColor(unsigned long);
  void Draw(void);
  const char* GetHoursString(void);
  const char* GetMinutesString(void);
  const char* GetSecondsString(void);
  unsigned char GetHours(void);
  unsigned char GetMinutes(void);
  unsigned char GetSeconds(void);
  void SetHours(unsigned char);
  void SetMinutes(unsigned char);
  void SetSeconds(unsigned char);
  const char* GetDayString(void);
  const char* GetMonthString(void);
  const char* GetYearString(void);
  unsigned char GetDay(void);
  unsigned char GetMonth(void);
  unsigned char GetYear(void);
  void SetDay(unsigned char);
  void SetMonth(unsigned char);
  void SetYear(unsigned char);
  void IncrementHours(void);
  void IncrementMinutes(void);
  void IncrementSeconds(void);
  void DecrementHours(void);
  void DecrementMinutes(void);
  void DecrementSeconds(void);
  const char* ConvertDigitToString(unsigned char);
  unsigned char ConvertStringToDigit(const char*);
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  unsigned short xCoordinate;  // x-coordinate of top-left, in pixels.
  unsigned short yCoordinate;  // y-coordinate of top-left, in pixels.
  unsigned short radius;       // Radius in pixels.
  unsigned long colorClock;
  unsigned char hours;
  unsigned char minutes;
  unsigned char seconds;
  unsigned short mSeconds;
  unsigned char day;
  unsigned char month;
  unsigned char year;
  
  ////// constants //////
  static const char converterTable[100][3];
  
  ////// functions //////


};
//--- end class TClock -------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
