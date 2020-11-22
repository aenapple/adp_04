/**********************************************************************************/
/**
*  @file
*  MenuClock.hpp - declaration of class TMenuClock.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuClockH
#define __MenuClockH

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
class TMenuClock : public TMenu
{
public:
  ////// variables //////
  
  
  ////// constants //////
  

  ////// functions //////
  TMenuClock(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  TButton ButtonMenu;
  TLabel LabelDate;
  TLabel LabelHours;
  TLabel LabelMinutes;
  TLabel LabelSeconds;
  TLabel LabelSeparator1;
  TLabel LabelSeparator2;
  
  ////// constants //////
  
  
  ////// functions //////


};
//--- end class TMenuClock ---------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
