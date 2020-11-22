/**********************************************************************************/
/**
*  @file
*  Gpio.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Gpio.hpp"


TGpio Gpio;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::Init(void)
{
  this->EnableClocks();
  this->InitGpioPorts();
  this->InitSpiPorts();
  this->InitTimPorts();
  this->InitExtiPorts();
  this->InitAdcPorts();
  this->InitDacPorts();
  
}
//--- end Init ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
#ifdef __DEBUG_GUI
void TGpio::EnableClocks(void)
{
  // Enable clock for SPI1. //
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
  // Enable GPIO clock for SCK, MOSI, MISO - SPI1. //
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  // Enable GPIO clock for LED-indicator. //
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  // Enable GPIO clock for LCD-interface. //
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  
}
#else
void TGpio::EnableClocks(void)
{
  // Enable clock for SPI2(LCD-controller). //
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
  
  // Enable GPIO clock for PA-port. //
  // PA2 - DRUM_OPT - input
  // PA5 - DROP_DAC - output (DAC???)
  // PA7 - CAS_SENS - input
  // PA15 - STEP_SIN - TIM2_CH1 - input
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  // Enable GPIO clock for PB-port. //
  // PB0 - MT2R - TIM3_CH3 - (PWM??)output
  // PB1 - MT3R - TIM3_CH4 - (PWM??)output
  // PB2 - BOOT1/LED - output
  // PB3 - STEP_COS - TIM2_CH2 - input
  // PB4 - MT0R - TIM3_CH1 - (PWM??)output
  // PB5 - MT1R - TIM3_CH2 - (PWM??)output
  // PB6 - MT0F - TIM4_CH1 - (PWM??)output
  // PB7 - MT1F - TIM4_CH2 - (PWM??)output
  // PB8 - MT2F - TIM4_CH3 - (PWM??)output
  // PB9 - MT3F - TIM4_CH4 - (PWM??)output
  // PB10 - I2C_SCL - ON_SCAN_LED - output
  // PB11 - I2C_SDA
  // PB12 - FLASH_CS - output
  // PB13 - SCK(SPI2 - LCD-controller)
  // PB14 - MISO(SPI2 - LCD-controller)
  // PB15 - MOSI(SPI2 - LCD-controller)
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  
  // Enable GPIO clock for PC-port. //
  // PC1 - IMG_OUT - input (ADC123_11???)
  // PC2 - DROP_AC - input (ADC123_12???)
  // PC3 - DROP_DC - input (ADC123_13???)
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  // Enable GPIO clock for PD-port. //
  // PD5 - MODE(LCD-controller) - output
  // PD7 - PD_N(LCD-controller) - output
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  
  // Enable GPIO clock for PG-port. //
  // PG9 - CAR_HOME_R - input
  // PG11 - DRUM_HOME1 - input
  // PG12 - DRUM_HOME2 - input
  // PG13 - TP_IRQ(LCD-controller)  - input
  // PG14 - TP_CS(SPI2 - LCD-controller) - output
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
  
  // Enable GPIO clock for PE-port. //
  // PE2 - IMG_CLK - output
  // PE3 - IMG_SI - output
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
  
  // Enable GPIO clock for PF-port. //
  // PF6 - LEVER_STEP - input
  // PF7 - LEVER_HOME - input
  // PF8 - CAR_HOME_L - input
  // PF9 - DRUM_LOCK_0 - input
  // PF10 - DRUM_LOCK_1 - input
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

}
#endif
//--- end EnableClocks -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
#ifdef __DEBUG_GUI
void TGpio::InitGpioPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

  // For LED-indicator. //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  // Turn-off LED-indicator. //
  GPIO_ResetBits(GPIOC, GPIO_Pin_5);
  
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

  // Init PD_N and MODE pins. //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

}
#else
void TGpio::InitGpioPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  // Init output/input-pins PA-port. //
  // PA7 - CAS_SENS - input
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  // Init output/input-pins PB-port. //
  // PB2 - BOOT1/LED - output
  // PB10 - ON_SCAN_LED
  // PB12 - FLASH_CS - output
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_10 | GPIO_Pin_12;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOB, GPIO_Pin_2);   // turn-off LED
  GPIO_ResetBits(GPIOB, GPIO_Pin_10);  // turn-off ON_SCAN_LED
  GPIO_SetBits(GPIOB, GPIO_Pin_12);    // FLASH_CS - set '1'.
  
  // Init output/input-pins PD-port. //
  // PD5 - MODE(LCD-controller) - output
  // PD7 - PD_N(LCD-controller) - output
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOD, GPIO_Pin_5);  // MODE - set '0' - setup SPI-mode for LCD-controller
  GPIO_ResetBits(GPIOD, GPIO_Pin_7);
  
  // Init output/input-pins PD-port. //
  // PD5 - MODE(LCD-controller) - output
  // PD7 - PD_N(LCD-controller) - output
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOD, GPIO_Pin_5);  // MODE - set '0' - setup SPI-mode for LCD-controller
  GPIO_ResetBits(GPIOD, GPIO_Pin_7);  // PD_N - set '1'.
  
  // Init output/input-pins PG-port. //
  // PG6 - OPT_ON - output
  // PG7 - PWR5V_ON - output
  // PG14 - TP_CS(SPI2 - LCD-controller) - output
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_14;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOG, GPIO_Pin_6);  // OPT_ON - set '0'.
  GPIO_ResetBits(GPIOG, GPIO_Pin_7);  // PWR5V_ON - set '0'.
  GPIO_SetBits(GPIOG, GPIO_Pin_14);   // TP_CS - set '1'.
  // PG9 - CAR_HOME_R - input
  // PG11 - DRUM_HOME1 - input
  // PG12 - DRUM_HOME2 - input
  // PG13 - TP_IRQ(LCD-controller)  - input
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  
  // Init output/input-pins PE-port. //
  // PE2 - IMG_CLK - output
  // PE3 - IMG_SI - output
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  
  // Init output/input-pins PF-port. //
  // PF7 - LEVER_HOME - input
  // PF8 - CAR_HOME_L - input
  // PF9 - DRUM_LOCK_0 - input
  // PF10 - DRUM_LOCK_1 - input
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  
}
#endif
//--- end InitGpioPorts ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
#ifdef __DEBUG_GUI
void TGpio::InitSpiPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  // SPI for LCD-controller. //
  // Enable peripherals alternate function. //
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1); // for SCK - SPI1.
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1); // for MISO - SPI1.
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1); // for MOSI - SPI1.
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  
  // SPI1 - SCK, MISO, MOSI pins configuration //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  // Init CS pin. //
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  
  // Init EXT_CS1 pin. //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_SetBits(GPIOA, GPIO_Pin_15);
  
}
#else
void TGpio::InitSpiPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  // SPI for LCD-controller. //
  // Enable peripherals alternate function. //
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_SPI2); // for SCK - SPI2.
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_SPI2); // for MISO - SPI2.
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI2); // for MOSI - SPI2.
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
}
#endif
//--- end InitSpiPorts -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::InitTimPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  // Init output TIM3-pins PB-port. //
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3); // PB4/TIM3-CH1 - MT0R.
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3); // PB5/TIM3-CH2 - MT1R.
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3); // PB0/TIM3-CH3 - MT2R.
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3); // PB1/TIM3-CH4 - MT3R.
  // Init output TIM4-pins PB-port. //
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4); // PB6/TIM4-CH1 - MT0F.
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4); // PB7/TIM4-CH2 - MT1F.
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM4); // PB8/TIM4-CH3 - MT2F.
  //GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4); // PB9/TIM4-CH4 - MT3F.
  
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  
  

}
//--- end InitTimPorts -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::InitExtiPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  // PA2 - DRUM_OPT(step) - input
  // PA15 - STEP_SIN - input
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_15;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  // PB3 - STEP_COS - input
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  // PF6 - LEVER_STEP - input
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOF, &GPIO_InitStructure);

}
//--- end InitExtiPorts ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::InitAdcPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /*
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  // PC1 - IMG_OUT - input ADC123_11.
  // PC2 - DROP_AC - input ADC123_12.
  // PC3 - DROP_DC - input ADC123_13.
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
}
//--- end InitAdcPorts -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::InitDacPorts(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  // PA5 - DROP_DAC - output
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOA, GPIO_Pin_5);
  
  // DAC - init. ///

}
//--- end InitDacPorts -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::LedIndicatorOff(void)
{
#ifdef __DEBUG_GUI
  GPIO_ResetBits(GPIOC, GPIO_Pin_5);
#else
  GPIO_ResetBits(GPIOB, GPIO_Pin_2);
#endif
}
//--- end LedIndicatorOff ----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::LedIndicatorOn(void)
{
#ifdef __DEBUG_GUI
  GPIO_SetBits(GPIOC, GPIO_Pin_5);
#else
  GPIO_SetBits(GPIOB, GPIO_Pin_2);
#endif
}
//--- end LedIndicatorOn -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::LedIndicatorToggle(void)
{
#ifdef __DEBUG_GUI
  GPIO_ToggleBits(GPIOC, GPIO_Pin_5);
#else
  GPIO_ToggleBits(GPIOB, GPIO_Pin_2);
#endif
}
//--- end LedIndicatorToggle -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::Power5vOn(void)
{
  GPIO_SetBits(GPIOG, GPIO_Pin_7);
}
//--- end Power5vOn ----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::Power5vOff(void)
{
  GPIO_ResetBits(GPIOG, GPIO_Pin_7);
}
//--- end Power5vOff ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::OpticSensorOn(void)
{
  GPIO_SetBits(GPIOG, GPIO_Pin_6);
}
//--- end OpticSensorOn ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::OpticSensorOff(void)
{
  GPIO_ResetBits(GPIOG, GPIO_Pin_6);
}
//--- end OpticSensorOff -----------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::SetImageSensorClk(void)
{
  GPIO_SetBits(GPIOE, GPIO_Pin_2);
}
//--- end SetImageSensorClk --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::ResetImageSensorClk(void)
{
  GPIO_ResetBits(GPIOE, GPIO_Pin_2);
}
//--- end ResetImageSensorClk ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::SetImageSensorSi(void)
{
  GPIO_SetBits(GPIOE, GPIO_Pin_3);
}
//--- end SetImageSensorSi ---------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::ResetImageSensorSi(void)
{
  GPIO_ResetBits(GPIOE, GPIO_Pin_3);
}
//--- end ResetImageSensorSi -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::TurnOnScanLed(void)
{
  GPIO_SetBits(GPIOB, GPIO_Pin_10);
}
//--- end TurnOnScanLed ------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TGpio::TurnOffScanLed(void)
{
  GPIO_ResetBits(GPIOB, GPIO_Pin_10);
}
//--- end TurnOffScanLed -----------------------------------------------------------

/**********************************************************************************/
