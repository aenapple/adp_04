/**********************************************************************************/
/**
*  @file
*  GraphicalInterface.hpp - declaration of class TGraphicalInterface.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __GraphicalInterfaceH
#define __GraphicalInterfaceH

/**********************************************************************************/
#include "System.hpp"

#ifdef __STM32F207
#include "stm32f2xx_gpio.h"
#include "stm32f2xx_rcc.h"
#endif

#ifdef __STM32F407
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#endif

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TGraphicalInterface : public TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void CreateTask(void);
 
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  static void Execute(void*);

};
//--- end class TGraphicalInterface ------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
