/**********************************************************************************/
/**
*  @file
*  Sensors.hpp - declaration of class TSensors.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __SensorsH
#define __SensorsH

/**********************************************************************************/
#include "System.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TSensors : public TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  static void Init(void);
  unsigned char GetStateCarrigeStartPositionSensor(void);
  unsigned char GetStateCarrigeEndPositionSensor(void);
  unsigned char GetStateLeverStartPositionSensor(void);
  
  
protected:
  ////// variables //////
  
  
  ////// constants //////

  ////// functions //////
  
  
private:
  ////// variables //////
  
  ////// constants //////

  ////// functions //////
  
  
  

};
//--- end class TTim ---------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
