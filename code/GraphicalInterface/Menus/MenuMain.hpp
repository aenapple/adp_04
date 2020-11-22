/**********************************************************************************/
/**
*  @file
*  MenuMain.hpp - declaration of class TMenuMain.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuMainH
#define __MenuMainH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\Button.hpp"
#include "..\GraphicalPrimitives\Number.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuMain : public TMenu
{
public:
  ////// variables //////
  
  
  ////// constants //////
  

  ////// functions //////
  TMenuMain(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  //void SetColor(unsigned long);
  //void SetColorLabel(unsigned long);
  //void SetLabelText(const char*, unsigned char);
  //void Draw(void);

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TButton ButtonSetups;
  TButton ButtonMenu;
  TNumber NumberXCoordinate;
  TNumber NumberYCoordinate;
  
  ////// constants //////
  
  
  ////// functions //////


};
//--- end class TMenuMain ----------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
