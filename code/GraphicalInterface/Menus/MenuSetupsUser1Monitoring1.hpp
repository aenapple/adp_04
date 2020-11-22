/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser1Monitoring1.hpp - declaration of class TMenuSetupsUser1Monitoring1.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsUser1Monitoring1H
#define __MenuSetupsUser1Monitoring1H

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardEnterString.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsUser1Monitoring1 : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsUser1Monitoring1(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TBoardEnterString* BoardEnterString;
  TBoardChoiceString* BoardChoiceString;
  
  
  ////// constants //////
  
  
  ////// functions //////
  
  

};
//--- end class TMenuSetupsUser1Monitoring1 ----------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
