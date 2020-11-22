/**********************************************************************************/
/**
*  @file
*  Button.hpp - declaration of class TButton.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __ButtonH
#define __ButtonH

/**********************************************************************************/
#include "..\LcdInterface.hpp"


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TButton : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  //TButton(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
  void Create(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
  void SetDefaultColor(void);
  void SetColor(unsigned long);
  void SetColorLabel(unsigned long);
  void SetLabelText(const char*, unsigned char);
  void Draw(void);
  unsigned char CheckPress(unsigned short, unsigned short);
  //void TurnOn(void);
  //void Toggle(void);
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  unsigned short xCoordinate;  // x-coordinate of button top-left, in pixels.
  unsigned short yCoordinate;  // y-coordinate of button top-left, in pixels.
  unsigned short width;        // button width in pixels.
  unsigned short height;       // button height in pixels.
  unsigned long colorButton;
  unsigned long colorLabel;
  const char* labelText;
  unsigned char labelFont;
  
  ////// constants //////
  static const char defaultLabelText[8];

  ////// functions //////


};
//--- end class TButton ------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
