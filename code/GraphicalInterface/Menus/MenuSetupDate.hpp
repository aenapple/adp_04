/**********************************************************************************/
/**
*  @file
*  MenuSetupDate.hpp - declaration of class TMenuSetupDate.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupDateH
#define __MenuSetupDateH

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
class TMenuSetupDate : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupDate(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TButton ButtonIncrement;
  TButton ButtonDecrement;
  TButton ButtonMoveLeft;
  TButton ButtonMoveRight;
  TButton ButtonReturn;
  
  TLabel LabelDay; 
  TLabel LabelMonth;
  TLabel LabelYear;
  TLabel LabelTextDay; 
  TLabel LabelTextMonth;
  TLabel LabelTextYear;
  ////// constants //////
  
  
  ////// functions //////


};
//--- end class TMenuSetupDate -----------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
