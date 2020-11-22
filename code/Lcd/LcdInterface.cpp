/**********************************************************************************/
/**
*  @file
*  LcdInterface.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "LcdInterface.hpp"

TLcdInterface LcdInterface;


/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::WriteMemory(unsigned int address, unsigned char* buffer, unsigned int numberBytes)
{
  unsigned char addressBuffer[3];
  
  this->ClearLcdInterfaceCs();
  
  addressBuffer[0]= 0x80 | (unsigned char)(address >> 16);
  addressBuffer[1]= (unsigned char)(address >> 8);
  addressBuffer[2]= (unsigned char)address;
  
  this->TransmitBytes(addressBuffer, 3);
  this->TransmitBytes(buffer, numberBytes);
  
  this->SetLcdInterfaceCs();
  
}
//--- end WriteMemory --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::ReadMemory(unsigned int address, unsigned char* buffer, unsigned int numberBytes)
{
  unsigned char addressBuffer[3];
  
  this->ClearLcdInterfaceCs();
  
  addressBuffer[0]= 0x3F & (unsigned char)(address >> 16);
  addressBuffer[1]= (unsigned char)(address >> 8);
  addressBuffer[2]= (unsigned char)address;
  
  this->TransmitBytes(addressBuffer, 3);
  this->TransmitBytes(buffer, numberBytes);
  
  this->SetLcdInterfaceCs();
  
}
//--- end ReadMemory ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::HostCommand(unsigned char command)
{
  unsigned char buffer[3];
  
  this->ClearLcdInterfaceCs();
  
  buffer[0]= command;
  buffer[1]= 0;
  buffer[2]= 0;
  
  this->TransmitBytes(buffer, 3);
  
  this->SetLcdInterfaceCs();

}
//--- end HostCommand --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::SwitchToActiveMode(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_ACTIVE);
}
//--- end SwitchToActiveMode -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::SwitchToStanbyMode(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_STANDBY);
}
//--- end SwitchToStanbyMode -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::SwitchToSleepMode(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_SLEEP);
}
//--- end SwitchToSleepMode --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::PowerDown(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_PWRDOWN);
}
//--- end PowerDown ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::EnableExternalClock(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_CLKEXT);
}
//--- end EnableExternalClock ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::SwitchPllto48MHz(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_CLK48M);
}
//--- end SwitchPllto48MHz ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::SwitchPllto36MHz(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_CLK36M);
}
//--- end SwitchPllto36MHz ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::SendResetPulse(void)
{
  this->HostCommand(LCD_HOSTCOMMAND_CORERST);
}
//--- end SendResetPulse -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::WriteRegister32bits(unsigned int address, unsigned long value)
{
  unsigned char buffer[4];
  
  buffer[0]= (unsigned char)(value >> 24);
  buffer[1]= (unsigned char)(value >> 16);
  buffer[2]= (unsigned char)(value >> 8);
  buffer[3]= (unsigned char)value;
  
  this->WriteMemory(address, buffer, 4);
  
}
//--- end WriteRegister32bits ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::WriteRegister16bits(unsigned int address, unsigned short value)
{
  unsigned char buffer[2];
  
  buffer[0]= (unsigned char)(value >> 8);
  buffer[1]= (unsigned char)value;
  
  this->WriteMemory(address, buffer, 2);
  
}
//--- end WriteRegister16bits ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The fuction ... .
*
*  @return ... .
*/
void TLcdInterface::WriteRegister8bits(unsigned int address, unsigned char value)
{
  unsigned char buffer[2];
  
  buffer[0]= value;
  
  this->WriteMemory(address, buffer, 1);
  
}
//--- end WriteRegister8bits -------------------------------------------------------

/**********************************************************************************/
