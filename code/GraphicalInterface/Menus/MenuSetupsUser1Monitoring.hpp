/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser1Monitoring.hpp - declaration of class TMenuSetupsUser1Monitoring.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsUser1MonitoringH
#define __MenuSetupsUser1MonitoringH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsUser1Monitoring : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsUser1Monitoring(void);
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
//--- end class TMenuSetupsUser1Monitoring -----------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
