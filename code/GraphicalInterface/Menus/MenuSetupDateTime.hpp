/**********************************************************************************/
/**
*  @file
*  MenuSetupDateTime.hpp - declaration of class TMenuSetupDateTime.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupDateTimeH
#define __MenuSetupDateTimeH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\Button.hpp"
#include "..\GraphicalPrimitives\Label.hpp"


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupDateTime : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupDateTime(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  
  ////// constants //////
  
  
  ////// functions //////


};
//--- end class TMenuSetupDateTime -------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
