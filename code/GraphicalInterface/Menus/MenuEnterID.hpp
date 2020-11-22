/**********************************************************************************/
/**
*  @file
*  MenuEnterID.hpp - declaration of class TMenuEnterID.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuEnterIDH
#define __MenuEnterIDH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardEnterString.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuEnterID : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuEnterID(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TBoardEnterString* BoardEnterString;
  //unsigned char stringID[MENU_ENTERID_SIZE_STRING_ID];
  
  
  ////// constants //////
  
  
  ////// functions //////

  
};
//--- end class TMenuEnterID -------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
