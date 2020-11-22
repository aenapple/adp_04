/**********************************************************************************/
/**
*  @file
*  Spi.hpp - declaration of class TSpi.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __SpiH
#define __SpiH

/**********************************************************************************/
#include "System.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TSpi : public TSystem
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void SetSpiLcdSlowSpeed(void);
  void SetSpiLcdHighSpeed(void);
  
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void SetFlashCs(void);
  void ClearFlashCs(void);
  void SetLcdInterfaceCs(void);
  void ClearLcdInterfaceCs(void);
  
  unsigned char TransmitByte(unsigned char);
  unsigned int TransmitBytes(unsigned char*, unsigned char*, unsigned int);
  
  
private:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void EnableLcdInterface(unsigned short);
  

};
//--- end class TSpi ---------------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
