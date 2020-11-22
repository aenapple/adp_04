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
#ifdef __FREE_RTOS
#include "FreeRTOS.h"
#include "task.h"
#endif


/**********************************************************************************/
volatile unsigned short TLcdInterface::ramCmdOffset;
unsigned char TLcdInterface::flagRotate;
float TLcdInterface::kTouchX;
float TLcdInterface::kTouchY;
  
/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::Start(void)
{
  unsigned long addressRamDl;
  
  this->SetSpiLcdSlowSpeed();  // Enable SPI with speed 10.5MHz.
  
#ifdef __DEBUG_GUI
  GPIO_SetBits(GPIOD, GPIO_Pin_11);    // Set PD_N to '1'.
  GPIO_ResetBits(GPIOD, GPIO_Pin_10);  // Set MODE to '0' - selection is SPI interface.
#else
  GPIO_SetBits(GPIOD, GPIO_Pin_7);    // Set PD_N to '1'.
  GPIO_ResetBits(GPIOD, GPIO_Pin_5);  // Set MODE to '0' - selection is SPI interface.
#endif
  
  this->ResetControllerLcd();  // Hardware RESET.
  
  this->HostCommand(LCD_HOSTCOMMAND_CLKEXT);
  this->HostCommand(LCD_HOSTCOMMAND_CLK48M);
  this->HostCommand(LCD_HOSTCOMMAND_ACTIVE);
  //this->HostCommand(LCD_HOSTCOMMAND_CORERST);  // Software RESET.
  
  while(true)
  {
    if(this->ReadRegister8bits(LCD_REG_ID) == 0x7C) break;
  }
  
  // Configure display registers - demonstration for WQVGA resolution. //
  this->WriteRegister16bits(LCD_REG_HCYCLE, 548);
  this->WriteRegister16bits(LCD_REG_HOFFSET, 43);
  this->WriteRegister16bits(LCD_REG_HSYNC0, 0);
  this->WriteRegister16bits(LCD_REG_HSYNC1, 41);
  this->WriteRegister16bits(LCD_REG_VCYCLE, 292);
  this->WriteRegister16bits(LCD_REG_VOFFSET, 12);
  this->WriteRegister16bits(LCD_REG_VSYNC0, 0);
  this->WriteRegister16bits(LCD_REG_VSYNC1, 10);
  this->WriteRegister8bits(LCD_REG_SWIZZLE, 0);
  this->WriteRegister8bits(LCD_REG_PCLK_POL, 1);
  this->WriteRegister8bits(LCD_REG_CSPREAD, 1);
  this->WriteRegister16bits(LCD_REG_HSIZE, 480);
  kTouchX= 1024.0 / (480 + 70);
  this->WriteRegister16bits(LCD_REG_VSIZE, 272);
  kTouchY= 1024.0 / (272 + 40);
  
  // Rotate display 180 degrees: 1 - rotate enable, 0 - rotate disable. //
  this->SetRotate();
  //this->ClearRotate();
  
  // Write first display list. //
  addressRamDl= LCD_RAM_DL;
  addressRamDl= this->WriteCommandClearColorRGB(addressRamDl, LCD_COLOR_DARK_GRAY1);
  addressRamDl= this->WriteCommandClear(addressRamDl, 1, 1, 1);
  addressRamDl= this->WriteCommandDisplay(addressRamDl);
  
  // Display list swap. //
  this->DlSwapFrame();
  
  // Enable display bit. //
  this->WriteRegister8bits(LCD_REG_GPIO_DIR, 0x83);
  this->WriteRegister8bits(LCD_REG_GPIO, 0x83);
  
  // After this display is visible on the LCD. //
  this->WriteRegister8bits(LCD_REG_PCLK, 5);
  
  // Switch SPI speed. //
  this->Delay(5);
  this->SetSpiLcdHighSpeed();  // Setup SPI with speed 21MHz.
  
  // Output FTDI-logo. //
  /*addressRamDl= LCD_RAM_DL;
  //addressRamDl= this->WriteCommandClearColorRGB(addressRamDl, 0, 255, 0);
  addressRamDl= this->WriteCommandClear(addressRamDl, 1, 1, 1);
  // Draw string 'FTDI". //
  addressRamDl= this->WriteCommandBegin(addressRamDl, LCD_BEGIN_PRIMITIVE_BITMAPS);
  addressRamDl= this->WriteCommandVertex2II(addressRamDl, 220, 110, 31, 'F');  // ascii F in font 31
  addressRamDl= this->WriteCommandVertex2II(addressRamDl, 244, 110, 31, 'T');  // ascii T in font 31
  addressRamDl= this->WriteCommandVertex2II(addressRamDl, 270, 110, 31, 'D');  // ascii D in font 31
  addressRamDl= this->WriteCommandVertex2II(addressRamDl, 299, 110, 31, 'I');  // ascii I in font 31
  addressRamDl= this->WriteCommandEnd(addressRamDl);
  // Draw red dot for a 20 pixel radius. //
  addressRamDl= this->WriteCommandBegin(addressRamDl, LCD_BEGIN_PRIMITIVE_POINTS);  // start drawing points
  addressRamDl= this->WriteCommandColorRGB(addressRamDl, 0x00C80000);                // change color to red
  addressRamDl= this->WriteCommandPointSize(addressRamDl, 20);                      // set point size to 20 pixels inradius
  addressRamDl= this->WriteCommandVertex2II(addressRamDl, 192, 133, 0, 0);          // red point
  addressRamDl= this->WriteCommandEnd(addressRamDl);
  // Display new list. //
  addressRamDl= this->WriteCommandDisplay(addressRamDl);
  
  // Display list swap. //
  this->DlSwapFrame();
  */
  this->ClearRamCmdOffset();
  this->CommandExec();
  
  this->Delay(10);
  // DEBUG
  //this->Debug();
  // DEBUG
}
//--- end Start --------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::Debug(void)
{
  this->CommandDlstart();
  this->WriteCommandClearColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_LIGHT_GRAY1);
  this->IncrementRamCmdOffset(4);
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  
  this->CommandButton(30, 10, 200, 35, 27, 0, "One");
  
  this->CommandFgcolor(0x703800);  // brown ???
  this->CommandButton(30, 50, 200, 35, 27, 0, "Two");
  
  this->CommandFgcolor(LCD_COLOR_DARK_GREEN);
  this->CommandButton(30, 90, 200, 35, 27, 0, "Three");
  
  
  
  this->WriteCommandColorRGB(LCD_RAM_CMD + this->ramCmdOffset, 0xC80000);  // red ????
  this->IncrementRamCmdOffset(4);
  
  this->CommandFgcolor(LCD_COLOR_DARK_BLUE);  // default foreground color !!!!!
  
  this->CommandButton(240, 10, 200, 35, 27, 0, "Four");
  
  this->WriteCommandColorRGB(LCD_RAM_CMD + this->ramCmdOffset, LCD_COLOR_WHITE);
  this->IncrementRamCmdOffset(4);
  
  this->CommandButton(240, 50, 200, 35, 27, 0, "Five");
  
  this->CommandColdstart();  // default setting
  
  this->CommandButton(240, 90, 200, 35, 27, 0, "Six");
  
  this->WriteCommandDisplay(LCD_RAM_CMD + this->ramCmdOffset);
  this->IncrementRamCmdOffset(4);
  
  this->CommandDlSwap();
  
  this->CommandExec();
  
  this->Delay(100);
  
  this->Delay(1000);
  
}
//--- end Debug --------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::DlSwapFrame(void)
{
  this->WriteRegister8bits(LCD_REG_DLSWAP, LCD_DLSWAP_FRAME);
  
  while(true)
  {
    this->Delay(10);
    if(this->ReadRegister8bits(LCD_REG_DLSWAP) == 0x00) break;
  
  }

}
//--- end DlSwapFrame --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandClearColorRGB(unsigned long address, unsigned long color)
{
  this->WriteRegister32bits(address, LCD_COMMAND_CLEAR_COLOR_RGB + color); 
  
  return(address + 4);
}
//--- end WriteCommandClearColorRGB ------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandClear(unsigned long address, unsigned char bitColorBuf, unsigned char bitStencilBuf, unsigned char bitTagBuf)
{
  unsigned long command;
  
  command= LCD_COMMAND_CLEAR;
  if(bitColorBuf > 0) command |= 4;
  if(bitStencilBuf > 0) command |= 2;
  if(bitTagBuf > 0) command |= 1;
  
  this->WriteRegister32bits(address, command); 
  
  return(address + 4);
}
//--- end WriteCommandClear --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandDisplay(unsigned long address)
{
  this->WriteRegister32bits(address, LCD_COMMAND_DISPLAY); 
  
  return(address + 4);
}
//--- end WriteCommandDisplay ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandBegin(unsigned long address, unsigned char graphPrimitive)
{
  this->WriteRegister32bits(address, LCD_COMMAND_BEGIN+graphPrimitive); 
  
  return(address + 4);
}
//--- end WriteCommandBegin ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandVertex2II(unsigned long address, unsigned short x, unsigned short y, unsigned char handle, unsigned char cell)
{
  unsigned long command;
  
  command= LCD_COMMAND_VERTEX2II + ((x & 0x1FF) << 21) + ((y & 0x1FF) << 12) + ((handle & 0x1F) << 7) + (cell & 0x7F);
  
  this->WriteRegister32bits(address, command); 
  
  return(address + 4);
}
//--- end WriteCommandVertex2II ----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandEnd(unsigned long address)
{
  this->WriteRegister32bits(address, LCD_COMMAND_END); 
  
  return(address + 4);
}
//--- end WriteCommandEnd ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandColorRGB(unsigned long address, unsigned long color)
{
  this->WriteRegister32bits(address, LCD_COMMAND_COLOR_RGB + color); 
  
  return(address + 4);
}
//--- end WriteCommandColorRGB -----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return 'next address - input address + 4'.
*/
unsigned long TLcdInterface::WriteCommandPointSize(unsigned long address, unsigned short sizePixel)
{
  unsigned short size;
  
  size= sizePixel * 16;
  if(size > 0x1FFF) size= 0x1FFF;
  
  this->WriteRegister32bits(address, LCD_COMMAND_POINT_SIZE + size); 
  
  return(address + 4);
}
//--- end WriteCommandPointSize ----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::ClearRamCmdOffset(void)
{
  this->ramCmdOffset= 0;
}
//--- end ClearRamCmdOffset --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::IncrementRamCmdOffset(unsigned char size)
{
  this->ramCmdOffset= (this->ramCmdOffset + size) % 4096;
}
//--- end IncrementRamCmdOffset ----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::WriteCommandToRamCmd(unsigned long command)
{
  this->WriteRegister32bits(LCD_RAM_CMD + this->ramCmdOffset, command);
  this->IncrementRamCmdOffset(4);
}
//--- end WriteCommandToRamCmd -----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandDlstart(void)
{
  this->WriteCommandToRamCmd(LCD_CMD_DLSTART);
}
//--- end CommandDlstart -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandDlSwap(void)
{
  this->Delay(5);
  this->WriteCommandToRamCmd(LCD_CMD_DLSWAP);
}
//--- end CommandDlSwap ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandExec(void)
{
  this->Delay(5);
  
  this->WriteRegister16bits(LCD_REG_CMD_WRITE, this->ramCmdOffset);
  
  while(true)
  {
    if(this->ReadRegister32bits(LCD_REG_CMD_WRITE) == this->ReadRegister32bits(LCD_REG_CMD_READ)) break;
    this->Delay(5);
  }

}
//--- end CommandExec --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandButton(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned short font, unsigned short options, const char* string)
{
  this->WriteCommandToRamCmd(LCD_CMD_BUTTON);
  
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, x);  // x-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, y);  // y-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, w);  // width in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, h);  // height in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, font);  // Bitmap handle to specify the font used in button label.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, options);  // By default, the button is drawn with a 3D effect and the value is zero.
  this->IncrementRamCmdOffset(2);
  
  this->IncrementRamCmdOffset(this->WriteString(LCD_RAM_CMD + this->ramCmdOffset, string));
    
}
//--- end CommandButton ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandClock(unsigned short x, unsigned short y, unsigned short r, unsigned char hours, unsigned char minutes, unsigned char seconds, unsigned short options)
{
  this->WriteCommandToRamCmd(LCD_CMD_CLOCK);
  
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, x);  // x-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, y);  // y-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, r);  // radius in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, options);  // By default, the button is drawn with a 3D effect and the value is zero.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, (unsigned short)hours);  // Hours.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, (unsigned short)minutes);  // Minutes.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, seconds);  // Second.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, 0);  // mSecond.
  this->IncrementRamCmdOffset(2);
  
}
//--- end CommandClock -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandKeys(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned short font, unsigned short options, const char* string)
{
  this->WriteCommandToRamCmd(LCD_CMD_KEYS);
  
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, x);  // x-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, y);  // y-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, w);  // width in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, h);  // height in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, font);  // Bitmap handle to specify the font used in button label.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, options);  // By default, the button is drawn with a 3D effect and the value is zero.
  this->IncrementRamCmdOffset(2);
  
  this->IncrementRamCmdOffset(this->WriteString(LCD_RAM_CMD + this->ramCmdOffset, string));
  
}
//--- end CommandClock -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandText(unsigned short x, unsigned short y, unsigned short font, unsigned short options, const char* string)
{
  this->WriteCommandToRamCmd(LCD_CMD_TEXT);
  
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, x);  // x-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, y);  // y-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, font);  // Bitmap handle to specify the font.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, options);  // By default, the button is drawn with a 3D effect and the value is zero.
  this->IncrementRamCmdOffset(2);
  
  this->IncrementRamCmdOffset(this->WriteString(LCD_RAM_CMD + this->ramCmdOffset, string));
  
}
//--- end CommandText --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandNumber(unsigned short x, unsigned short y, unsigned short font, unsigned short options, unsigned long number)
{
  this->WriteCommandToRamCmd(LCD_CMD_NUMBER);
  
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, x);  // x-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, y);  // y-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, font);  // Bitmap handle to specify the font.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, options);  // By default, the button is drawn with a 3D effect and the value is zero.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister32bits(LCD_RAM_CMD + this->ramCmdOffset, number);  // The number to display, either unsigned or signed 32-bit.
  this->IncrementRamCmdOffset(4);
  
}
//--- end CommandNumber ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandSpinner(unsigned short x, unsigned short y, unsigned short style, unsigned short scale)
{
  this->WriteCommandToRamCmd(LCD_CMD_SPINNER);
  
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, x);  // x-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, y);  // y-coordinate of button top-left, in pixels.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, style);  // The style of spinner. Valid range is from 0 to 3.
  this->IncrementRamCmdOffset(2);
  this->WriteRegister16bits(LCD_RAM_CMD + this->ramCmdOffset, scale);  // The scaling coefficient of spinner. 0 means no scaling.
  this->IncrementRamCmdOffset(2);

}
//--- end CommandSpinner -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::Calibrate(void)
{
  this->CommandDlstart();
  
  this->WriteCommandClear(LCD_RAM_CMD + this->ramCmdOffset, 1, 1, 1);
  this->IncrementRamCmdOffset(4);
  
  this->CommandText(80, 30, 27, 0, "Please tap on the dot");
  
  this->WriteCommandToRamCmd(LCD_CMD_CALIBRATE);
  this->WriteCommandToRamCmd(0);
  
  
}
//--- end Calibrate ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandFgcolor(unsigned long color)
{
  this->WriteCommandToRamCmd(LCD_CMD_FGCOLOR);
  this->WriteCommandToRamCmd(color);
}
//--- end CommandFgcolor -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandBgcolor(unsigned long color)
{
  this->WriteCommandToRamCmd(LCD_CMD_BGCOLOR);
  this->WriteCommandToRamCmd(color);
}
//--- end CommandBgcolor -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::CommandColdstart(void)
{
  this->WriteCommandToRamCmd(LCD_CMD_COLDSTART);
}
//--- end CommandColdstart ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned long TLcdInterface::ReadRegTouchScreenXY(void)
{
  unsigned long touchXY;
  
  touchXY= this->ReadRegister32bits(LCD_REG_TOUCH_SCREEN_XY);
  if(touchXY != 0x80008000)
  {
    this->Delay(20);
    touchXY= this->ReadRegister32bits(LCD_REG_TOUCH_SCREEN_XY);
  }
  
  return(touchXY);
}
//--- end ReadRegTouchScreenXY -----------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::WaitPullButton(void)
{
  unsigned long touchXY;
  
  for(int i=0; i < 50; i++)
  {
    this->Delay(20);
    touchXY= this->ReadRegTouchScreenXY();
    if(touchXY == 0x80008000) break;
  }

}
//--- end WaitPullButton -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::ResetControllerLcd(void)
{
  this->Delay(20);

#ifdef __DEBUG_GUI
  GPIO_ResetBits(GPIOD, GPIO_Pin_11);  // Set PD_N to '0'.
#else
  GPIO_ResetBits(GPIOD, GPIO_Pin_7);   // Set PD_N to '0'.
#endif
  
  this->Delay(20);
  
#ifdef __DEBUG_GUI
  GPIO_SetBits(GPIOD, GPIO_Pin_11);  // Set PD_N to '1'.
#else
  GPIO_SetBits(GPIOD, GPIO_Pin_7);   // Set PD_N to '1'.
#endif  
  
  this->Delay(20);
}
//--- end ResetControllerLcd -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TLcdInterface::WriteMemory(unsigned long address, unsigned char* buffer, unsigned int numberBytes)
{
  unsigned char addressBuffer[3];
  unsigned char* outputBuffer;
  //int i;
  //int k;
  
  outputBuffer= new unsigned char[numberBytes];
  
  //for(i=0; i < 10; i++)
  //{
    this->ClearLcdInterfaceCs();
  
    addressBuffer[0]= 0x80 | (unsigned char)(address >> 16);
    addressBuffer[1]= (unsigned char)(address >> 8);
    addressBuffer[2]= (unsigned char)address;
  
    this->TransmitBytes(addressBuffer, outputBuffer, 3);
    this->TransmitBytes(buffer, outputBuffer, numberBytes);
  
    this->SetLcdInterfaceCs();
    
    /*
    if(address == LCD_REG_DLSWAP) { delete(outputBuffer); return(0); }
    
    k= 10;
    while(k--) {}
    
    this->ReadMemory(address, outputBuffer, numberBytes);
    
    for(k=0; k < numberBytes; k++)
    {
      if(buffer[k] != outputBuffer[k]) break;
    }
    
    if(k == numberBytes) // write data is OK.
    {
      delete(outputBuffer);
      return(0);
    }
    */
    
  //}
  
  delete(outputBuffer);
  
  return(1);
}
//--- end WriteMemory --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::ReadMemory(unsigned long address, unsigned char* buffer, unsigned int numberBytes)
{
  unsigned char addressBuffer[4];
  unsigned char* inputBuffer;
  
  inputBuffer= new unsigned char[numberBytes];
  
  this->ClearLcdInterfaceCs();
  
  addressBuffer[0]= 0x3F & (unsigned char)(address >> 16);
  addressBuffer[1]= (unsigned char)(address >> 8);
  addressBuffer[2]= (unsigned char)address;
  addressBuffer[3]= 4;  // dummy byte
  
  this->TransmitBytes(addressBuffer, inputBuffer, 4);
  this->TransmitBytes(inputBuffer, buffer, numberBytes);
  
  this->SetLcdInterfaceCs();
  
  delete(inputBuffer);
}
//--- end ReadMemory ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::HostCommand(unsigned char command)
{
  unsigned char inputBuffer[3];
  unsigned char outputBuffer[3];
  
  inputBuffer[0]= command;
  inputBuffer[1]= 0;
  inputBuffer[2]= 0;
  
  this->ClearLcdInterfaceCs();
  
  this->TransmitBytes(inputBuffer, outputBuffer, 3);
  
  this->SetLcdInterfaceCs();

}
//--- end HostCommand --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::WriteRegister32bits(unsigned long address, unsigned long value)
{
  unsigned char buffer[4];
  
  buffer[3]= (unsigned char)(value >> 24);
  buffer[2]= (unsigned char)(value >> 16);
  buffer[1]= (unsigned char)(value >> 8);
  buffer[0]= (unsigned char)value;
  
  this->WriteMemory(address, buffer, 4);
    
}
//--- end WriteRegister32bits ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::WriteRegister16bits(unsigned long address, unsigned short value)
{
  unsigned char buffer[2];
  
  buffer[1]= (unsigned char)(value >> 8);
  buffer[0]= (unsigned char)value;
  
  this->WriteMemory(address, buffer, 2);
  
}
//--- end WriteRegister16bits ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::WriteRegister8bits(unsigned long address, unsigned char value)
{
  unsigned char buffer[2];
  
  buffer[0]= value;
  
  this->WriteMemory(address, buffer, 1);
    
}
//--- end WriteRegister8bits -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned short TLcdInterface::WriteString(unsigned long address, const char* string)
{
  unsigned char* buffer;
  unsigned short sizeString;
  unsigned short additionalSize;
  
  sizeString= strlen(string) + 1;
  additionalSize= 4 - (sizeString % 4);
  if(additionalSize == 4) additionalSize= 0;
  sizeString += additionalSize;
  buffer= new unsigned char[sizeString];
  
  for(int i=0; i < sizeString; i++) buffer[i]= string[i];
  //for(int i=0; i < (sizeString-additionalSize); i++) buffer[i]= string[i];
  //for(int i=0; i < additionalSize; i++) buffer[sizeString-additionalSize+i]= 0;
  this->WriteMemory(address, buffer, sizeString);
  
  delete(buffer);
  
  return(sizeString);
}
//--- end WriteString --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TLcdInterface::ReadRegister8bits(unsigned long address)
{
  unsigned char buffer[2];
  
  this->ReadMemory(address, buffer, 1);
  
  return(buffer[0]);
}
//--- end ReadRegister8bits --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned short TLcdInterface::ReadRegister16bits(unsigned long address)
{
  unsigned char buffer[2];
  unsigned short result;
  
  this->ReadMemory(address, buffer, 2);
  
  result= buffer[1];
  result <<= 8;
  result += buffer[0];
  
  return(result);
}
//--- end ReadRegister16bits -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned long TLcdInterface::ReadRegister32bits(unsigned long address)
{
  unsigned char buffer[4];
  unsigned long result;
  
  this->ReadMemory(address, buffer, 4);
  
  result= buffer[3];
  result <<= 8;
  result += buffer[2];
  result <<= 8;
  result += buffer[1];
  result <<= 8;
  result += buffer[0];
  
  return(result);
  
}
//--- end ReadRegister32bits -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned short TLcdInterface::CalculateTouchX(unsigned long touchXY)
{
  unsigned short touchX;
  
  touchX= (unsigned short)(touchXY >> 16);
  
  if(this->flagRotate > 0) touchX= 1024 - touchX;
  
  touchX= (unsigned short)((float)touchX / kTouchX);
  
  return(touchX-40);
}
//--- end CalculateTouchX ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned short TLcdInterface::CalculateTouchY(unsigned long touchXY)
{
  unsigned short touchY;
  
  touchY= (unsigned short)touchXY;
  
  if(this->flagRotate > 0) touchY= 1024 - touchY;
  
  touchY= (unsigned short)((float)touchY / kTouchY);
  
  return(touchY-20);
}
//--- end CalculateTouchY ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::SetRotate(void)
{
  // Rotate display 180 degrees: 1 - rotate enable, 0 - rotate disable. //
  this->WriteRegister8bits(LCD_REG_ROTATE, 1);
  this->flagRotate= 1;
}
//--- end SetRotate ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TLcdInterface::ClearRotate(void)
{
  // Rotate display 180 degrees: 1 - rotate enable, 0 - rotate disable. //
  this->WriteRegister8bits(LCD_REG_ROTATE, 0);
  this->flagRotate= 0;
}
//--- end ClearRotate --------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TLcdInterface::GetRotate(void)
{
  // Rotate display 180 degrees: 1 - rotate enable, 0 - rotate disable. //
  return(this->flagRotate);
}
//--- end GetRotate ----------------------------------------------------------------

/**********************************************************************************/
