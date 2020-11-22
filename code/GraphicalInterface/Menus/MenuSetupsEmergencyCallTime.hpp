/**********************************************************************************/
/**
*  @file
*  MenuSetupsEmergencyCallTime.hpp - declaration of class TMenuSetupsEmergencyCallTime.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsEmergencyCallTimeH
#define __MenuSetupsEmergencyCallTimeH

/**********************************************************************************/
#include "Menu.hpp"

/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsEmergencyCallTime : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsEmergencyCallTime(void);
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
//--- end class MenuSetupsEmergencyCallTime ----------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
