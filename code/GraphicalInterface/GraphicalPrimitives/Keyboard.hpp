/**********************************************************************************/
/**
*  @file
*  Keyboard.hpp - declaration of class TKeyboard.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __KeyboardH
#define __KeyboardH

/**********************************************************************************/
#include "..\LcdInterface.hpp"
#include "Button.hpp"
#include "Keys.hpp"


/**********************************************************************************/
#define KEYBOARD_SMALL_CHARAPTERS  0
#define KEYBOARD_LARGE_CHARAPTERS  1
#define KEYBOARD_SYMBOLS           2

/**********************************************************************************/
typedef enum
{
  KEYBOARD_NOT_PRESSED = 0,
  KEYBOARD_SHIFT,
  KEYBOARD_CANCEL,
  KEYBOARD_SWITCH,
  KEYBOARD_BACKSPACE,
  KEYBOARD_SPACE,
  KEYBOARD_OK,
  KEYBOARD_ENTER,
  KEYBOARD_RETURN,
  KEYBOARD_UP,
  KEYBOARD_DOWN,
  KEYBOARD_MENU_STRING1,
  KEYBOARD_MENU_STRING2,
  KEYBOARD_MENU_STRING3,
  KEYBOARD_MENU_STRING4,
  KEYBOARD_MENU_STRING5,
  KEYBOARD_MENU_STRING6,
  KEYBOARD_MENU_STRING7,
  KEYBOARD_MENU_STRING8,
} EPressedKeyboard;

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TKeyboard : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  TKeyboard(void);
  //void SetColor(unsigned long);
  //void SetKeysText(const char*, unsigned char);
  //void SetOptions(unsigned short);
  void Draw(unsigned short, unsigned short);
  EPressedKeyboard CheckPressedButton(unsigned char*);
  void SetActiveTypeKeyboard(unsigned char);
  unsigned char GetActiveTypeKeyboard(void);
  
  
protected:
  ////// variables //////
  
  
  
  
  
  
  ////// constants //////
  
  
private:
  ////// variables //////
  TButton ButtonShift;
  TButton ButtonSpace;
  TButton ButtonOk;
  TButton ButtonCancel;
  TButton ButtonBackspace;
  TButton ButtonSwitch;
  
  TKeys KeysDigits;
  TKeys KeysCharapter1;
  TKeys KeysCharapter2;
  TKeys KeysCharapter3;
  
  unsigned char activeTypeKeyboard;
  
  
  ////// constants //////
  
  
  ////// functions //////
  
  

};
//--- end class TKeyboard ----------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
