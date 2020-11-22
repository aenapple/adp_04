/**********************************************************************************/
/**
*  @file
*  Gpio.hpp - declaration of class TGpio.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __GpioH
#define __GpioH

/**********************************************************************************/
#include "System.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TGpio : public TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void Init(void);
  void LedIndicatorOff(void);
  void LedIndicatorOn(void);
  void LedIndicatorToggle(void);
  void Power5vOn(void);
  void Power5vOff(void);
  void OpticSensorOn(void);
  void OpticSensorOff(void);
  void SetImageSensorClk(void);
  void ResetImageSensorClk(void);
  void SetImageSensorSi(void);
  void ResetImageSensorSi(void);
  void TurnOnScanLed(void);
  void TurnOffScanLed(void);
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  
  
  
private:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void EnableClocks(void);
  void InitGpioPorts(void);
  void InitSpiPorts(void);
  void InitTimPorts(void);
  void InitExtiPorts(void);
  void InitAdcPorts(void);
  void InitDacPorts(void);
  

};
//--- end class TGpio --------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
