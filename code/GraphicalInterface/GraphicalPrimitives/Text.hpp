/**********************************************************************************/
/**
*  @file
*  Text.hpp - declaration of class TText.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __TextH
#define __TextH

/**********************************************************************************/
#include "..\LcdInterface.hpp"


/**********************************************************************************/
//#define CLOCK_OPT_NOSECS  0x8000
//#define CLOCK_OPT_NOBACK  0x1000
//#define CLOCK_OPT_NOHM    0x4000

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TText : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void Create(unsigned short x, unsigned short y);
  void SetDefaultColor(void);
  void SetColor(unsigned long);
  void SetString(const char*, unsigned char);
  void Draw(void);
  
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  unsigned short xCoordinate;  // x-coordinate of top-left, in pixels.
  unsigned short yCoordinate;  // y-coordinate of top-left, in pixels.
  unsigned long colorString;
  unsigned char fontString;
  const char* string;
  
  
  ////// constants //////
  static const char defaultLabelText[8];
  
  ////// functions //////


};
//--- end class TText --------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
