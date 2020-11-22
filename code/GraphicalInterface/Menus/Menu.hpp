/**********************************************************************************/
/**
*  @file
*  Menu.hpp - declaration of class TMenu.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuH
#define __MenuH

/**********************************************************************************/
#include "..\LcdInterface.hpp"


/**********************************************************************************/
typedef enum
{
  MENU_NOT_PRESSED_BUTTON = 0,
  MENU_MAIN,
  MENU_MENU,
  MENU_SETUPS,  
  MENU_SETUPS_DATE_TIME,
  //MENU_SETUPS_TIME,
  MENU_SETUPS_USER1,  
  MENU_SETUPS_USER2,
  MENU_ENTER_ID,
  MENU_BUTTON_UP,
  MENU_BUTTON_DOWN,
  MENU_BUTTON_ENTER,
  MENU_BUTTON_RETURN,
} EPressedButton;


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenu : public TLcdInterface
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  TMenu(void);
  virtual void Draw(void)=0;
  virtual EPressedButton Perfom(void)=0;
  virtual EPressedButton CheckPressedButton(void)=0;
  
  void SetPressedButton(EPressedButton);
  EPressedButton GetPressedButton(void);
  //void WaitPullButton(void);

  
protected:
  ////// variables //////

  
  ////// constants //////

  ////// functions //////
  
  
  
private:
  ////// variables //////
  static EPressedButton pressedButton;
  
  ////// constants //////
  
  
  ////// functions //////
  

};
//--- end class TMenu --------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
