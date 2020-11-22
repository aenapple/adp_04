/**********************************************************************************/
/**
*  @file
*  MenuSetupsDispensingTime.hpp - declaration of class TMenuSetupsDispensingTime.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsDispensingTimeH
#define _MenuSetupsDispensingTimeH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardEnterString.hpp"

/**********************************************************************************/
//#define USER_NAME_STRING_SIZE_MAX  30
//#define USER_PHONE_STRING_SIZE     12
//#define USER_CODE_STRING_SIZE      4


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsDispensingTime : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsDispensingTime(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TBoardEnterString* BoardEnterString;
  
  
  ////// constants //////
  
  
  ////// functions //////
  

};
//--- end class TMenuSetupsDispensingTime ------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
