/**********************************************************************************/
/**
*  @file
*  MenuSetupsMedication.hpp - declaration of class TMenuSetupsMedication.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsMedicationH
#define __MenuSetupsMedicationH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

/**********************************************************************************/

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsMedication : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsMedication(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TBoardChoiceString* BoardChoiceString;
  
  
  ////// constants //////
  
  ////// functions //////
  

};
//--- end class TMenuSetupsMedication ----------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
