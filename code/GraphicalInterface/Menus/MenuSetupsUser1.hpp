/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser1.hpp - declaration of class TMenuSetupsUser1.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsUser1H
#define __MenuSetupsUser1H

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

/**********************************************************************************/
#define USER_NAME_STRING_SIZE_MAX  30
#define USER_PHONE_STRING_SIZE     12
#define USER_CODE_STRING_SIZE      4

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsUser1 : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsUser1(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TBoardChoiceString* BoardChoiceString;
  unsigned char name[USER_NAME_STRING_SIZE_MAX];
  unsigned char phoneHome[USER_PHONE_STRING_SIZE];
  unsigned char phoneCell[USER_PHONE_STRING_SIZE];
  unsigned char stringCode[USER_CODE_STRING_SIZE];
  unsigned char emergencyCallHours;
  unsigned char emergencyCallMinutes;
  unsigned char emergencyCallSeconds;
  
  ////// constants //////
  
  
  ////// functions //////
  //void UpActiveString(void);
  //void DownActiveString(void);
  //void SetupString(unsigned char*, unsigned char, const char*);
  void SetupPhone();
  void SetupStringCode();
  void SetupLanguage();
  

};
//--- end class TMenuSetupsUser1 ---------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
