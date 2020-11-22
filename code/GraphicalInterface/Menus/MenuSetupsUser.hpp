/**********************************************************************************/
/**
*  @file
*  MenuSetupsUser.hpp - declaration of class TMenuSetupsUser.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MenuSetupsUserH
#define __MenuSetupsUserH

/**********************************************************************************/
#include "Menu.hpp"
#include "..\GraphicalPrimitives\BoardChoiceString.hpp"

/**********************************************************************************/
#define USER_NAME_STRING_SIZE_MAX  30
#define USER_PHONE_STRING_SIZE     12
#define USER_CODE_STRING_SIZE      4

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMenuSetupsUser : public TMenu
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TMenuSetupsUser(void);
  void Draw(void);                          // VIRTUAL
  EPressedButton Perfom(void);              // VIRTUAL
  EPressedButton CheckPressedButton(void);  // VIRTUAL
  

  
protected:
  ////// variables //////

  ////// constants //////
  static const char stringPleaseSetup[];
  static const char stringForUser[];
  static const char stringName[];
  static const char stringPhoneCell[];
  static const char stringFourDigitsCode[];
  static const char stringLanguage[];
  static const char stringDispensingTimeWarning[];
  static const char stringMonitoring[];
  static const char stringSetupEmergencyCallTime[];
  static const char stringMedicationSchedule[];

  
private:
  ////// variables //////
  TBoardChoiceString* BoardChoiceString;
  
  unsigned char name[USER_NAME_STRING_SIZE_MAX];
  unsigned char phoneHome[USER_PHONE_STRING_SIZE];
  unsigned char phoneCell[USER_PHONE_STRING_SIZE];
  unsigned char stringCode[USER_CODE_STRING_SIZE];
  unsigned char emergencyCallHours;
  unsigned char emergencyCallMinutes;
  unsigned char emergencyCallSeconds;
  
  ////// constants //////
  
  
  ////// functions //////
  void SetupPhone();
  void SetupStringCode();
  void SetupLanguage();
  

};
//--- end class TMenuSetupsUser ----------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
