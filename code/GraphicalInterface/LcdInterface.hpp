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
#include "..\HardDrivers\Spi.hpp"


/**********************************************************************************/
#define LCD_HOSTCOMMAND_ACTIVE   0x00
#define LCD_HOSTCOMMAND_STANDBY  0x41
#define LCD_HOSTCOMMAND_SLEEP    0x42
#define LCD_HOSTCOMMAND_PWRDOWN  0x50
#define LCD_HOSTCOMMAND_CLKEXT   0x44
#define LCD_HOSTCOMMAND_CLK48M   0x62
#define LCD_HOSTCOMMAND_CLK36M   0x61
#define LCD_HOSTCOMMAND_CORERST  0x68

//#define LCD_GRAPHICS_RAM_ADDRESS_START 0x000000
//#define LCD_GRAPHICS_RAM_ADDRESS_END   0x03FFFF

#define LCD_DLSWAP_FRAME  2

#define LCD_RAM_G          0x00000000  // Main graphics RAM, size 256kB - 0x00000000-0x0003FFFF.
#define LCD_ROM_CHIPID     0x000C0000  // FT800 chip identification and revision information, size 4B - 0x000C0000-0x000C0003.
#define LCD_ROM_FONT       0x000BB23C  // Font table and bitmap, size 275kB - 0x000BB23C-0x000FFFFB.
#define LCD_ROM_FONT_ADDR  0x000FFFFC  // Font table pointer address, size 4B - 0x000FFFFC-0x000FFFFF.
#define LCD_RAM_DL         0x00100000  // Display List RAM, size 8kB - 0x00100000-0x00101FFF.
#define LCD_RAM_PAL        0x00102000  // Palette RAM, size 1kB - 0x00102000-0x001023FF.
#define LCD_RAM_REG        0x00102400  // Registers, size 380B - 0x00102400-0x0010257F.
#define LCD_RAM_CMD        0x00108000  // Graphics Engine Command Buffer, size 4kB - 0x00108000-0x00108FFF.
#define LCD_RAM_SREENSHOT  0x001C2000  // Screenshot readout buffer, size 2kB - 0x001C2000-0x001C27FF.

#define LCD_REG_HCYCLE    0x00102428
#define LCD_REG_HOFFSET   0x0010242C
#define LCD_REG_HSIZE     0x00102430
#define LCD_REG_HSYNC0    0x00102434
#define LCD_REG_HSYNC1    0x00102438
#define LCD_REG_VCYCLE    0x0010243C
#define LCD_REG_VOFFSET   0x00102440
#define LCD_REG_VSIZE     0x00102444
#define LCD_REG_VSYNC0    0x00102448
#define LCD_REG_VSYNC1    0x0010244C
#define LCD_REG_DLSWAP    0x00102450
#define LCD_REG_ROTATE    0x00102454
#define LCD_REG_OUTBITS   0x00102458
#define LCD_REG_DITHER    0x0010245C
#define LCD_REG_SWIZZLE   0x00102460
#define LCD_REG_CSPREAD   0x00102464
#define LCD_REG_PCLK_POL  0x00102468
#define LCD_REG_PCLK      0x0010246C

#define LCD_REG_TOUCH_SCREEN_XY  0x00102510

//#define REG_ANALOG           1058104UL
//#define REG_ANA_COMP         1058160UL
//#define REG_CLOCK            1057800UL
//#define REG_CMD_DL           1058028UL
#define LCD_REG_CMD_READ   0x001024E4
#define LCD_REG_CMD_WRITE  0x001024E8
//#define REG_CPURESET         1057820UL
//#define REG_CRC              1058152UL
//#define REG_CYA0             1058000UL
//#define REG_CYA1             1058004UL
//#define REG_CYA_TOUCH        1058100UL
//#define REG_DATESTAMP        1058108UL
//#define REG_FRAMES           1057796UL
//#define REG_FREQUENCY        1057804UL
#define LCD_REG_GPIO       0x00102490
#define LCD_REG_GPIO_DIR   0x0010248C

#define LCD_REG_ID  0x00102400

// Co-processor engine. //
#define LCD_CMD_DLSTART       0xFFFFFF00
#define LCD_CMD_DLSWAP        0xFFFFFF01
#define LCD_CMD_COLDSTART     0xFFFFFF32
#define LCD_CMD_INTERRUPT     0xFFFFFF02
#define LCD_CMD_APPEND        0xFFFFFF1E
#define LCD_CMD_REGREAD       0xFFFFFF19
#define LCD_CMD_MEMWRITE      0xFFFFFF1A
#define LCD_CMD_INFLATE       0xFFFFFF22
#define LCD_CMD_LOADIMAGE     0xFFFFFF24
#define LCD_CMD_MEMCRC        0xFFFFFF18
#define LCD_CMD_MEMZERO       0xFFFFFF1C
#define LCD_CMD_MEMSET        0xFFFFFF1B
#define LCD_CMD_MEMCPY        0xFFFFFF1D
#define LCD_CMD_BUTTON        0xFFFFFF0D
#define LCD_CMD_CLOCK         0xFFFFFF14
#define LCD_CMD_FGCOLOR       0xFFFFFF0A
#define LCD_CMD_BGCOLOR       0xFFFFFF09
#define LCD_CMD_GRADCOLOR     0xFFFFFF34
#define LCD_CMD_GAUGE         0xFFFFFF13
#define LCD_CMD_GRAGIENT      0xFFFFFF0B
#define LCD_CMD_KEYS          0xFFFFFF0E
#define LCD_CMD_PROGRESS      0xFFFFFF0F
#define LCD_CMD_SCROLLBAR     0xFFFFFF11
#define LCD_CMD_SLIDER        0xFFFFFF10
#define LCD_CMD_DIAL          0xFFFFFF2D
#define LCD_CMD_TOGGLE        0xFFFFFF12
#define LCD_CMD_TEXT          0xFFFFFF0C
#define LCD_CMD_NUMBER        0xFFFFFF2E
#define LCD_CMD_LOADIDENTITY  0xFFFFFF26
#define LCD_CMD_SETMATRIX     0xFFFFFF2A
#define LCD_CMD_GETPTR        0xFFFFFF23
#define LCD_CMD_GETPROPS      0xFFFFFF25
#define LCD_CMD_SCALE         0xFFFFFF28
#define LCD_CMD_ROTATE        0xFFFFFF29
#define LCD_CMD_TRANSLATE     0xFFFFFF27
#define LCD_CMD_CALIBRATE     0xFFFFFF15
#define LCD_CMD_SPINNER       0xFFFFFF16
#define LCD_CMD_SCREENSAVER   0xFFFFFF2F
#define LCD_CMD_SKETCH        0xFFFFFF30
#define LCD_CMD_STOP          0xFFFFFF17
#define LCD_CMD_SETFONT       0xFFFFFF2B
#define LCD_CMD_TRACK         0xFFFFFF2C
#define LCD_CMD_SNAPSHOT      0xFFFFFF1F
#define LCD_CMD_LOGO          0xFFFFFF31



#define LCD_COMMAND_BEGIN            0x1F000000
#define LCD_COMMAND_CLEAR_COLOR_RGB  0x02000000
#define LCD_COMMAND_CLEAR            0x26000000
#define LCD_COMMAND_COLOR_RGB        0x04000000
#define LCD_COMMAND_DISPLAY          0x00000000
#define LCD_COMMAND_END              0x21000000
#define LCD_COMMAND_POINT_SIZE       0x0D000000
#define LCD_COMMAND_VERTEX2II        0x80000000


#define LCD_BEGIN_PRIMITIVE_BITMAPS       0x01
#define LCD_BEGIN_PRIMITIVE_POINTS        0x02
#define LCD_BEGIN_PRIMITIVE_LINES         0x03
#define LCD_BEGIN_PRIMITIVE_LINE_STRIP    0x04
#define LCD_BEGIN_PRIMITIVE_EDGE_STRIP_R  0x05
#define LCD_BEGIN_PRIMITIVE_EDGE_STRIP_L  0x06
#define LCD_BEGIN_PRIMITIVE_EDGE_STRIP_A  0x07
#define LCD_BEGIN_PRIMITIVE_EDGE_STRIP_B  0x08
#define LCD_BEGIN_PRIMITIVE_RECTS         0x09

#define LCD_COLOR_WHITE        0xFFFFFF
#define LCD_COLOR_LIGHT_GRAY1  0xC8C8C8
#define LCD_COLOR_LIGHT_GRAY2  0xA0A0A0
#define LCD_COLOR_DARK_GRAY1   0x404040
#define LCD_COLOR_DARK_GRAY2   0x808080
#define LCD_COLOR_DARK_BLUE    0x003870  // default foreground color.
#define LCD_COLOR_BLUE         0x0038C8
#define LCD_COLOR_DARK_GREEN   0x387000
#define LCD_COLOR_LIGHT_GREEN  0x38C800
#define LCD_COLOR_GREEN        0x00FF00
#define LCD_COLOR_BANANA       0xB9B900
#define LCD_COLOR_ORANGE       0xB97300
#define LCD_COLOR_CHERRY       0xB90007
#define LCD_COLOR_RED          0xFF0000

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
  void Start(void);
  unsigned long ReadRegTouchScreenXY(void);
  void WaitPullButton(void);
  unsigned short CalculateTouchX(unsigned long);
  unsigned short CalculateTouchY(unsigned long);
  
  void Debug(void);
  
  void WriteRegister32bits(unsigned long, unsigned long);
  void WriteRegister16bits(unsigned long, unsigned short);
  void WriteRegister8bits(unsigned long, unsigned char);
  unsigned short WriteString(unsigned long, const char*);
  
  unsigned long ReadRegister32bits(unsigned long);
  unsigned short ReadRegister16bits(unsigned long);
  unsigned char ReadRegister8bits(unsigned long);
  
  
protected:
  ////// variables //////
  static volatile unsigned short ramCmdOffset;
  
  
  ////// constants //////

  ////// functions //////
  void DlSwapFrame(void);
  void CommandExec(void);
  unsigned long WriteCommandClearColorRGB(unsigned long, unsigned long);
  unsigned long WriteCommandClear(unsigned long, unsigned char, unsigned char, unsigned char);
  unsigned long WriteCommandDisplay(unsigned long);
  unsigned long WriteCommandBegin(unsigned long, unsigned char);
  unsigned long WriteCommandVertex2II(unsigned long, unsigned short, unsigned short, unsigned char, unsigned char);
  unsigned long WriteCommandEnd(unsigned long);
  unsigned long WriteCommandColorRGB(unsigned long, unsigned long);
  unsigned long WriteCommandPointSize(unsigned long, unsigned short);
  
  void ClearRamCmdOffset(void);
  void IncrementRamCmdOffset(unsigned char);
  void WriteCommandToRamCmd(unsigned long);
  void CommandDlstart(void);
  void CommandDlSwap(void);
  
  void CommandButton(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, const char*);
  void CommandClock(unsigned short, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char, unsigned short);
  void CommandKeys(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, const char*);
  void CommandText(unsigned short, unsigned short, unsigned short, unsigned short, const char*);
  void CommandNumber(unsigned short, unsigned short, unsigned short, unsigned short, unsigned long);
  void CommandSpinner(unsigned short, unsigned short, unsigned short, unsigned short);
  void Calibrate(void);
  void CommandFgcolor(unsigned long);
  void CommandBgcolor(unsigned long);
  void CommandColdstart(void);
  
  void SetRotate(void);
  void ClearRotate(void);
  unsigned char GetRotate(void);
  
  
private:
  ////// variables //////
  static float kTouchX;
  static float kTouchY;
  static unsigned char flagRotate;
  
  ////// constants //////
  

  ////// functions //////
  unsigned char WriteMemory(unsigned long, unsigned char*, unsigned int);
  void ReadMemory(unsigned long, unsigned char*, unsigned int);
  void HostCommand(unsigned char);
  
  void ResetControllerLcd(void);
  
  
  
  

};
//--- end class TLedIndicator ------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
