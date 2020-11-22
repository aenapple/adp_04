/**********************************************************************************/
/**
*  @file
*  MenuMenu.hpp - declaration of class TMenuMenu.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuMenuH
#define __MenuMenuH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"
#include "..\GraphicalPrimitives\BoardWaiting.hpp"
#include "..\GraphicalPrimitives\BoardFlashing.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuMenu : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuMenu(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TBoardChoiceString* BoardChoiceString;
  TBoardWaiting* BoardWaiting;
  TBoardFlashing* BoardFlashing;
  
  
  
  ////// constants //////
  
  
  ////// functions //////


};
//--- end class TMenuMenu ----------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
