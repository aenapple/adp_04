/**********************************************************************************/
/**
*  @file
*  MenuSetups.hpp - declaration of class TMenuSetups.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsH
#define __MenuSetupsH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\Button.hpp"
#include "..\GraphicalPrimitives\Text.hpp"
#include "..\GraphicalPrimitives\Label.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetups : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetups(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TButton ButtonSetup;  // not active, used as label
  //TLabel labelSetup;
  //TButton ButtonDate;
  //TButton ButtonTime;
  TButton ButtonDateTime;
  TButton ButtonUser1;
  TButton ButtonUser2;
  TButton ButtonReturn;
  
  
  ////// constants //////
  
  
  ////// functions //////


};
//--- end class TMenuSetups --------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
