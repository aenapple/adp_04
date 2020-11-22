/**********************************************************************************/
/**
*  @file
*  LcdInterface.hpp - declaration of class TLcdInterface.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __LcdInterfaceH
#define __LcdInterfaceH

/**********************************************************************************/
//#ifdef __STM32F207
//#include "stm32f2xx_gpio.h"
//#include "stm32f2xx_rcc.h"
//#include "stm32f2xx_spi.h"
//#endif

//#ifdef __STM32F407
//#include "stm32f4xx_gpio.h"
//#include "stm32f4xx_rcc.h"
//#include "stm32f4xx_spi.h"
//#endif

#include "..\HardDrivers\Spi.hpp"


/**********************************************************************************/
#define LCD_HOSTCOMMAND_ACTIVE  0x00
#define LCD_HOSTCOMMAND_STANDBY 0x41
#define LCD_HOSTCOMMAND_SLEEP   0x42
#define LCD_HOSTCOMMAND_PWRDOWN 0x50
#define LCD_HOSTCOMMAND_CLKEXT  0x44
#define LCD_HOSTCOMMAND_CLK48M  0x62
#define LCD_HOSTCOMMAND_CLK36M  0x61
#define LCD_HOSTCOMMAND_CORERST 0x68

//#define LCD_GRAPHICS_RAM_ADDRESS_START 0x000000
//#define LCD_GRAPHICS_RAM_ADDRESS_END   0x03FFFF

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TLcdInterface : public TSpi
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void SwitchToActiveMode(void);
  void SwitchToStanbyMode(void);
  void SwitchToSleepMode(void);
  void PowerDown(void);
  void EnableExternalClock(void);
  void SwitchPllto48MHz(void);
  void SwitchPllto36MHz(void);
  void SendResetPulse(void);
  
  void WriteRegister32bits(unsigned int, unsigned long);
  void WriteRegister16bits(unsigned int, unsigned short);
  void WriteRegister8bits(unsigned int, unsigned char);
  
  unsigned long ReadRegister32bits(unsigned int);
  unsigned short ReadRegister16bits(unsigned int);
  unsigned char ReadRegister8bits(unsigned int);
  
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void WriteMemory(unsigned int, unsigned char*, unsigned int);
  void ReadMemory(unsigned int, unsigned char*, unsigned int);
  void HostCommand(unsigned char);

};
//--- end class TLedIndicator ------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
