/**********************************************************************************/
/**
*  @file
*  MenuSetupsLanguage.hpp - declaration of class TMenuSetupsLanguage.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsLanguageH
#define __MenuSetupsLanguageH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

/**********************************************************************************/
//#define USER_NAME_STRING_SIZE_MAX  30
//#define USER_PHONE_STRING_SIZE     12
//#define USER_CODE_STRING_SIZE      4
typedef enum
{
  ENGLISH=0,
  RUSSIAN,
  FRENCH,
  LANGUAGE_LAST_ELEMENT
} ELanguage;

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsLanguage : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsLanguage(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  ELanguage indexOfLanguage;
  TBoardChoiceString* BoardChoiceString;
  
  
  ////// constants //////
  static const char languageStrings[LANGUAGE_LAST_ELEMENT][15];
  
  ////// functions //////
  //void GetLanguage(void);
  

};
//--- end class TMenuSetupsLanguage ------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
