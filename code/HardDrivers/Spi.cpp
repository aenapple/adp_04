/**********************************************************************************/
/**
*  @file
*  Spi.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Spi.hpp"

#ifdef __FREE_RTOS
#include "FreeRTOS.h"
#include "task.h"
#endif

/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSpi::SetSpiLcdSlowSpeed(void)
{
  this->EnableLcdInterface(SPI_BaudRatePrescaler_8);  // speed is 10.5MHz.
}
//--- end SetSpiLcdSlowSpeed -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSpi::SetSpiLcdHighSpeed(void)
{
  this->EnableLcdInterface(SPI_BaudRatePrescaler_4);  // speed is 21MHz.
}
//--- end SetSpiLcdHighSpeed -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSpi::EnableLcdInterface(unsigned short speed)
{
  SPI_InitTypeDef SPI_InitStruct;
  
#ifdef __DEBUG_GUI
  SPI_I2S_DeInit(SPI1);
#else
  SPI_I2S_DeInit(SPI2);
#endif
  
  SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
  SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStruct.SPI_BaudRatePrescaler = speed;
  SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStruct.SPI_CRCPolynomial = 7;
  
#ifdef __DEBUG_GUI
  SPI_Init(SPI1, &SPI_InitStruct);
  SPI_Cmd(SPI1, ENABLE);
#else
  SPI_Init(SPI2, &SPI_InitStruct);
  SPI_Cmd(SPI2, ENABLE);
#endif
  
}
//--- end Enable -------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSpi::SetFlashCs(void)
{
  GPIO_SetBits(GPIOB, GPIO_Pin_12);  // FLASH_CS - set '1'.
}
//--- end SetFlashCs ---------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSpi::ClearFlashCs(void)
{
  GPIO_ResetBits(GPIOB, GPIO_Pin_12);  // FLASH_CS - set '0'.
}
//--- end ClearFlashCs -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSpi::SetLcdInterfaceCs(void)
{
  __enable_interrupt();
    
#ifdef __DEBUG_GUI
  GPIO_SetBits(GPIOA, GPIO_Pin_15);
#else
  GPIO_SetBits(GPIOG, GPIO_Pin_14);  // TP_CS - set '1'.
#endif

}
//--- end SetLcdInterfaceCs --------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TSpi::ClearLcdInterfaceCs(void)
{
#ifdef __DEBUG_GUI
  GPIO_ResetBits(GPIOA, GPIO_Pin_15);
#else
  GPIO_ResetBits(GPIOG, GPIO_Pin_14);  // TP_CS - set '0'.
#endif
  
  __disable_interrupt();

}
//--- end ClearLcdInterfaceCs ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned char TSpi::TransmitByte(unsigned char byte)
{
  unsigned char inputBuffer[2];
  unsigned char outputBuffer[2];
  
  inputBuffer[0]= byte;
  TransmitBytes(inputBuffer, outputBuffer, 1);
  
  return(outputBuffer[0]);
}
//--- end TransmitByte -------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
#ifdef __DEBUG_GUI
unsigned int TSpi::TransmitBytes(unsigned char* inputBuffer, unsigned char* outputBuffer, unsigned int numberBytes)
{
  unsigned int i;
  
  // Send first byte. //
  SPI_I2S_SendData(SPI1, inputBuffer[0]);
  for(i=1; i < numberBytes; i++)
  {
    // Send next byte. //
    while(true)
    {
      if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == SET) break;
    }
    SPI_I2S_SendData(SPI1, inputBuffer[i]);
    
    // Receive next byte. //
    while(true)
    {
      if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == SET)
      {
        outputBuffer[i-1]= SPI_I2S_ReceiveData(SPI1);
        break;
      }
      
    }
    
  }

  // Receive last byte. //
  while(true)
  {
    if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == SET)
    {
      outputBuffer[numberBytes-1]= SPI_I2S_ReceiveData(SPI1);
      break;
    }
  }
  
  // Wait untill SPI is busy. //
  while(true)
  {
    if(SPI_I2S_GetFlagStatus(SPI1, SPI_FLAG_BSY) == RESET) break;
  }
  
  return(i);
}
#else
unsigned int TSpi::TransmitBytes(unsigned char* inputBuffer, unsigned char* outputBuffer, unsigned int numberBytes)
{
  unsigned int i;
  
  // Send first byte. //
  SPI_I2S_SendData(SPI2, inputBuffer[0]);
  for(i=1; i < numberBytes; i++)
  {
    // Send next byte. //
    while(true)
    {
      if(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == SET) break;
    }
    SPI_I2S_SendData(SPI2, inputBuffer[i]);
    
    // Receive next byte. //
    while(true)
    {
      if(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == SET)
      {
        outputBuffer[i-1]= SPI_I2S_ReceiveData(SPI2);
        break;
      }
      
    }
    
  }

  // Receive last byte. //
  while(true)
  {
    if(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == SET)
    {
      outputBuffer[numberBytes-1]= SPI_I2S_ReceiveData(SPI2);
      break;
    }
  }
  
  // Wait untill SPI is busy. //
  while(true)
  {
    if(SPI_I2S_GetFlagStatus(SPI2, SPI_FLAG_BSY) == RESET) break;
  }
  
  return(i);
}
#endif
//--- end TransmitBytes ------------------------------------------------------------

/**********************************************************************************/
