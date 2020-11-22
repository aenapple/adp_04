/**********************************************************************************/
/**
*  @file
*  MenuDoseEnterID.hpp - declaration of class TMenuDoseEnterID.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuDoseEnterIDH
#define __MenuDoseEnterIDH

/**********************************************************************************/
#include "Menu.hpp"
//#include "..\GraphicalPrimitives\BoardEnterString.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuDoseEnterID : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuDoseEnterID(void);
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
//--- end class TMenuDoseEnterID ---------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
