/**********************************************************************************/
/**
*  @file
*  Number.hpp - declaration of class TNumber.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __NumberH
#define __NumberH

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
class TNumber : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void Create(unsigned short x, unsigned short y);
  //void SetDefaultColor(void);
  void SetColor(unsigned long);
  void SetNumber(unsigned long, unsigned char);
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
  unsigned long number;
  
  
  ////// constants //////
  
  
  ////// functions //////


};
//--- end class TNumber ------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
