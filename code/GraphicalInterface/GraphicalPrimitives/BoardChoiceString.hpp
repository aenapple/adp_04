/**********************************************************************************/
/**
*  @file
*  BoardChoiceString.hpp - declaration of class TBoardChoiceString.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __BoardChoiceStringH
#define __BoardChoiceStringH

/**********************************************************************************/
#include "..\LcdInterface.hpp"
#include "..\GraphicalPrimitives\Button.hpp"
#include "..\GraphicalPrimitives\Label.hpp"
#include "..\GraphicalPrimitives\BoardEnterString.hpp"

/**********************************************************************************/
#define BOARD_CHOICE_STRING_MAX_STRINGS  8
#define BOARD_CHOICE_STRING_MIN_STRINGS  2

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TBoardChoiceString : public TLcdInterface
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TBoardChoiceString(void);
  void Draw(void);
  EPressedKeyboard Perfom(void);
  EPressedKeyboard CheckPressedButton(void);
  
  void SetupTitleText(const char*);
  void SetupString1Text(const char*);
  void SetupString2Text(const char*);
  void SetupString3Text(const char*);
  void SetupString4Text(const char*);
  void SetupString5Text(const char*);
  void SetupString6Text(const char*);
  void SetupString7Text(const char*);
  void SetupString8Text(const char*);
  void SetupSizeMenu(unsigned char);

  void SetupString(unsigned char*, unsigned char, const char*);
  
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  
  
private:
  ////// variables //////
  TBoardEnterString* BoardEnterString;
  
  TButton ButtonSetup;  // not active, used as label
  TButton ButtonUp;
  TButton ButtonDown;
  TButton ButtonEnter;
  TButton ButtonReturn;
  
  TLabel Label1;
  TLabel Label2;
  TLabel Label3;
  TLabel Label4;
  TLabel Label5;
  TLabel Label6;
  TLabel Label7;
  TLabel Label8;
  
  unsigned char indexOfString;
  unsigned char sizeMenu;
  
  ////// constants //////
  
  
  ////// functions //////
  void UpActiveString(void);
  void DownActiveString(void);
  
  

};
//--- end class TBoardChoiceString -------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
