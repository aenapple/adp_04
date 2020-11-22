/**********************************************************************************/
/**
*  @file
*  BoardSetupTime.hpp - declaration of class TBoardSetupTime.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __BoardSetupTimeH
#define __BoardSetupTimeH

/**********************************************************************************/
#include "BoardSetupDateTime.hpp"


/**********************************************************************************/


/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TBoardSetupTime : public TBoardSetupDateTime
{
public:
  ////// variables //////
  

  ////// constants //////
  

  ////// functions //////
  TBoardSetupTime(void);
  //void Perfom(void);
  //void Draw(unsigned short, unsigned short);
  //void Init(unsigned char, unsigned char, unsigned char, const char*, const char*, const char*);
  unsigned char GetHours(void);
  unsigned char GetMinutes(void);
  unsigned char GetSeconds(void);

  
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
//--- end class TBoardSetupTime ----------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
