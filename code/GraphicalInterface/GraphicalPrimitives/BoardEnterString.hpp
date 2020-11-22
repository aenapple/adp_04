/**********************************************************************************/
/**
*  @file
*  BoardEnterString.hpp - declaration of class TBoardEnterString.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __BoardEnterStringH
#define __BoardEnterStringH

/**********************************************************************************/
#include "..\LcdInterface.hpp"
#include "..\GraphicalPrimitives\Button.hpp"
#include "..\GraphicalPrimitives\Label.hpp"
#include "..\GraphicalPrimitives\Keyboard.hpp"


/**********************************************************************************/
#define BOARD_ENTER_STRING_SIZE_MAX  32

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TBoardEnterString : public TLcdInterface
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TBoardEnterString(void);
  void SetTitleString(const char*);
  void SetEnterString(const char*);
  unsigned char* GetEnteredString(void);
  void SetMaxSizeEnteredString(unsigned char);
  EPressedKeyboard Perfom(void);

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TButton ButtonEnter;
  TLabel LabelString;
  TKeyboard Keyboard;
  unsigned char string[BOARD_ENTER_STRING_SIZE_MAX];
  unsigned char indexString;
  unsigned char sizeString;
  
  ////// constants //////
  
  
  ////// functions //////
  void Draw(void);
  void AppendCharapter(unsigned char);
  void RemoveCharapter(void);
  EPressedKeyboard CheckButtons(unsigned char*);

};
//--- end class TBoardEnterString --------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
