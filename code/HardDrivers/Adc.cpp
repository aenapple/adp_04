/**********************************************************************************/
/**
*  @file
*  Adc.cpp - contains functions ... .
*
*  Target:  ...
*
*/

/**********************************************************************************/
/*   *****                                                                        */
/**********************************************************************************/
#include "Adc.hpp"

TAdc Adc;
/**********************************************************************************/



/**********************************************************************************/



/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TAdc::Init(void)
{
  this->InitAdc1();
  
}
//--- end Init ---------------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TAdc::InitAdc1(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);  // The ADC1 is connected the APB2 peripheral bus thus we will use its clock source.
  RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOCEN, ENABLE);  // Clock for the ADC port.
 
  ADC_DeInit();
  ADC1_InitStructure.ADC_DataAlign= ADC_DataAlign_Right;                       //data converted will be shifted to right
  ADC1_InitStructure.ADC_Resolution= ADC_Resolution_12b;                       //Input voltage is converted into a 12bit number giving a maximum value of 4096
  ADC1_InitStructure.ADC_ContinuousConvMode= ENABLE;                           //the conversion is continuous, the input data is converted more than once
  ADC1_InitStructure.ADC_ExternalTrigConv= ADC_ExternalTrigConv_T1_CC1;        // conversion is synchronous with TIM1 and CC1 (actually I'm not sure about this one :/)
  ADC1_InitStructure.ADC_ExternalTrigConvEdge= ADC_ExternalTrigConvEdge_None;  // no trigger for conversion
  ADC1_InitStructure.ADC_NbrOfConversion= 1;                                   //I think this one is clear :p
  ADC1_InitStructure.ADC_ScanConvMode= DISABLE;                                //The scan is configured in one channel
  ADC_Init(ADC1, &ADC1_InitStructure);                                           //Initialize ADC with the previous configuration

  ////// Enable ADC conversion. //////
  ADC_Cmd(ADC1, ENABLE);
  
  ////// Select the channel to be read from. //////
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_144Cycles);
  
 
  // PC1 - IMG_OUT - input (ADC123_11???)
  // PC2 - DROP_AC - input (ADC123_12???)
  // PC3 - DROP_DC - input (ADC123_13???)
}
//--- end InitAdc1 -----------------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TAdc::StartConversionAdc1(void)
{
  ADC_Cmd(ADC1, ENABLE);
  
  ////// Select the channel to be read from. //////
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_144Cycles);
}
//--- end StartConversionAdc1 ------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
void TAdc::StopConversionAdc1(void)
{
  ADC_Cmd(ADC1, DISABLE);
}
//--- end StopConversionAdc1 -------------------------------------------------------

//----------------------------------------------------------------------------------
/**
*  The function ... .
*
*  @return ... .
*/
unsigned short TAdc::ReadAdc1(void)
{
  ////// Start the conversion. //////
  ADC_SoftwareStartConv(ADC1);
  
  ////// Processing the conversion. //////
  while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
  
  return(ADC_GetConversionValue(ADC1));
}
//--- end ReadAdc1 -----------------------------------------------------------------

/**********************************************************************************/
