/**********************************************************************************/
/**
*  @file
*  BoardFlashing.hpp - declaration of class TBoardFlashing.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __BoardFlashingH
#define __BoardFlashingH

/**********************************************************************************/
#include "..\LcdInterface.hpp"
#include "..\GraphicalPrimitives\Button.hpp"

/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TBoardFlashing : public TLcdInterface
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TBoardFlashing(void);
  void Draw(void);
  void SetColor(unsigned long);
  
protected:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  
  
private:
  ////// variables //////
  TButton ButtonFlashing;  // not active, used as label
  
  
  ////// constants //////
  
  
  ////// functions //////
  
  

};
//--- end class TBoardFlashing -----------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
