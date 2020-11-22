/**********************************************************************************/
/**
*  @file
*  Keys.hpp - declaration of class TKeys.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __KeysH
#define __KeysH

/**********************************************************************************/
#include "..\LcdInterface.hpp"


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TKeys : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  //TButton(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
  void Create(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
  void SetDefaultColor(void);
  void SetColorBackground(unsigned long);
  void SetColorText(unsigned long);
  void SetText(const char*, unsigned char);
  void Draw(void);
  unsigned char CheckPress(unsigned short, unsigned short);

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  unsigned short xCoordinate;  // x-coordinate of button top-left, in pixels.
  unsigned short yCoordinate;  // y-coordinate of button top-left, in pixels.
  unsigned short width;        // keys width in pixels.
  unsigned short height;       // keys height in pixels.
  unsigned long colorButton;
  unsigned long colorText;
  const char* text;
  unsigned char textFont;
  //unsigned char arrayText[12];
  
  ////// constants //////
  //static const char defaultLabelText[8];

  ////// functions //////


};
//--- end class TKeys --------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
