/**********************************************************************************/
/**
*  @file
*  Tim.hpp - declaration of class TTim.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __TimH
#define __TimH

/**********************************************************************************/
#include "System.hpp"

/**********************************************************************************/


/**********************************************************************************/
typedef enum
{
  ModeTim4_StartOc1=0,
  ModeTim4_StartOc2,
  ModeTim4_StartOc3,
  ModeTim4_StartOc4,
  ModeTim4_StopOc1Level0,
  ModeTim4_StopOc1Level1,
  ModeTim4_StopOc2Level0,
  ModeTim4_StopOc2Level1,
  ModeTim4_StopOc3Level0,
  ModeTim4_StopOc3Level1,
  ModeTim4_StopOc4Level0,
  ModeTim4_StopOc4Level1,
} EModeTim4;

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TTim : public TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void Init(void);
  void IRQ_HandlerTim3(void);
  void StopTim3(void);
  void StartTim3(unsigned short);
  void StartTim4(EModeTim4, unsigned char);
  void StopTim4(EModeTim4);
  
  SemaphoreHandle_t GetHandleSemaphoreScanDrum(void);
  ESystemStatus TakeScanDrumSemaphore(unsigned short);
  void GiveScanDrumSemaphore(void);
  void GiveScanDrumSemaphoreFromIsr(void);
  
  
protected:
  ////// variables //////
  TIM_TimeBaseInitTypeDef TIM3_TimeBaseInitStructure;
  TIM_TimeBaseInitTypeDef TIM4_TimeBaseInitStructure;
  //TIM_OCInitTypeDef TIM3_OCInitStructure;
  TIM_OCInitTypeDef TIM4_OCInitStructure;
  
  ////// constants //////

  ////// functions //////
  
  
private:
  ////// variables //////
  SemaphoreHandle_t semaphoreScanDrum;
  
  ////// constants //////

  ////// functions //////
  void InitTim3(void);
  void InitTim4(void);
  
  

};
//--- end class TTim ---------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
