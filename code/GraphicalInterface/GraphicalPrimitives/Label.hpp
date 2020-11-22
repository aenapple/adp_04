/**********************************************************************************/
/**
*  @file
*  Label.hpp - declaration of class TLabel.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __LabelH
#define __LabelH

/**********************************************************************************/
#include "..\LcdInterface.hpp"


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TLabel : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  //TButton(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
  void Create(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
  void SetDefaultColor(void);
  void SetColorText(unsigned long);
  void SetColorBackground(unsigned long);
  unsigned long GetColorBackground(void);
  void SetString(const char*, unsigned char);
  void Draw(void);
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  unsigned short xCoordinate;  // x-coordinate of button top-left, in pixels.
  unsigned short yCoordinate;  // y-coordinate of button top-left, in pixels.
  unsigned short width;        // button width in pixels.
  unsigned short height;       // button height in pixels.
  unsigned long colorBackground;
  unsigned long colorText;
  const char* string;
  unsigned char stringFont;
  
  ////// constants //////
  static const char defaultText[8];

  ////// functions //////


};
//--- end class TLabel -------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
