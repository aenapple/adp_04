/**********************************************************************************/
/**
*  @file
*  BoardSetupDate.hpp - declaration of class TBoardSetupDate.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __BoardSetupDateH
#define __BoardSetupDateH

/**********************************************************************************/
#include "BoardSetupDateTime.hpp"


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TBoardSetupDate : public TBoardSetupDateTime
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TBoardSetupDate(void);
  unsigned char GetDay(void);
  unsigned char GetMonth(void);
  unsigned char GetYear(void);

  
protected:
  ////// variables //////

  
  ////// constants //////

  ////// functions //////
  void IncrementDigit1(void);  // VIRTUAL
  void IncrementDigit2(void);  // VIRTUAL
  void IncrementDigit3(void);  // VIRTUAL
  void DecrementDigit1(void);  // VIRTUAL
  void DecrementDigit2(void);  // VIRTUAL
  void DecrementDigit3(void);  // VIRTUAL
  
  
private:
  ////// variables //////
  
  ////// constants //////
  
  
  ////// functions //////
  

};
//--- end class TBoardSetupDate ----------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
