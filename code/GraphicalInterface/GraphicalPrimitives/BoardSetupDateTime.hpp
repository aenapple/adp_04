/**********************************************************************************/
/**
*  @file
*  BoardSetupDateTime.hpp - declaration of class TBoardSetupDateTime.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __BoardSetupDateTimeH
#define __BoardSetupDateTimeH

/**********************************************************************************/
#include "..\LcdInterface.hpp"
#include "Button.hpp"
#include "Label.hpp"


/**********************************************************************************/
typedef enum
{
  BOARD_NOT_PRESSED_BUTTON = 0,
  BOARD_BUTTON_LEFT,
  BOARD_BUTTON_RIGHT,
  BOARD_BUTTON_INCREMENT,
  BOARD_BUTTON_DECREMENT,
  BOARD_BUTTON_OK
} EPressedBoardButton;

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TBoardSetupDateTime : public TLcdInterface
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TBoardSetupDateTime(void);
  void Draw(const char*);
  void Init(unsigned char, unsigned char, unsigned char, const char*, const char*, const char*);
  
  
protected:
  ////// variables //////
  TButton ButtonTitle;  // not active, used as label
  TButton ButtonIncrement;
  TButton ButtonDecrement;
  TButton ButtonMoveLeft;
  TButton ButtonMoveRight;
  TButton ButtonOk;
  
  TLabel LabelDigit1; 
  TLabel LabelDigit2;
  TLabel LabelDigit3;
  
  unsigned char digit1;
  unsigned char digit2;
  unsigned char digit3;
  
  
  ////// constants //////

  ////// functions //////
  virtual void IncrementDigit1(void)=0;
  virtual void IncrementDigit2(void)=0;
  virtual void IncrementDigit3(void)=0;
  virtual void DecrementDigit1(void)=0;
  virtual void DecrementDigit2(void)=0;
  virtual void DecrementDigit3(void)=0;
  
  EPressedBoardButton Perfom(void);
  
  
private:
  ////// variables //////
  TLabel LabelTextDigit1; 
  TLabel LabelTextDigit2;
  TLabel LabelTextDigit3;
  
  
  
  ////// constants //////
  static const char converterTable[100][3];
  
  ////// functions //////
  void Draw(void);
  EPressedBoardButton CheckPressedButton(void);
  const char* GetDigit1String(void);
  const char* GetDigit2String(void);
  const char* GetDigit3String(void);
  

};
//--- end class TBoardSetupDateTime ------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
