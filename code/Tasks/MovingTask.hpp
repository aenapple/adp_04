/**********************************************************************************/
/**
*  @file
*  MovingTask.hpp - declaration of class TGMovingTask.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __MovingTaskeH
#define __MovingTaskH

/**********************************************************************************/
#include "Task.hpp"


/**********************************************************************************/
#define MOTOR_CARRIAGE_MAX_STEPS  1200
#define MOTOR_LEVER_MAX_STEPS     80
#define MOTOR_LEVER_END_STEPS     60
#define MOTOR_LEVER_SCAN_STEPS    29
#define MOTOR_DRUM_MAX_STEPS      260

#define MOTOR_DRUM_POSITION_NONE   0
#define MOTOR_DRUM_POSITION_HOME1  1
#define MOTOR_DRUM_POSITION_HOME2  2

#define MOTOR_LOCK_DRUM_POSITION_NONE    0
#define MOTOR_LOCK_DRUM_POSITION_LOCK    1
#define MOTOR_LOCK_DRUM_POSITION_UNLOCK  2

#define MOTOR_LEVER_POSITION_NONE   0
#define MOTOR_LEVER_POSITION_START  1
#define MOTOR_LEVER_POSITION_END    2
#define MOTOR_LEVER_POSITION_SCAN   3

#define MOTOR_CARRIAGE_POSITION_NONE  0
#define MOTOR_CARRIAGE_POSITION_CAS1  1
#define MOTOR_CARRIAGE_POSITION_CAS2  2
#define MOTOR_CARRIAGE_POSITION_CAS3  3
#define MOTOR_CARRIAGE_POSITION_CAS4  4
#define MOTOR_CARRIAGE_POSITION_CAS5  5
#define MOTOR_CARRIAGE_POSITION_CAS6  6
#define MOTOR_CARRIAGE_POSITION_END   7


#define MOVING_TASK_MAX_NUMBER_CASSETTES  6

/**********************************************************************************/
typedef enum
{
  ETaskMovingReset=0,
  ETaskMovingCarriageToStartPosition,
  ETaskMovingCarriageToEndPosition,
  ETaskMovingLeverToStartPosition,
  ETaskMovingLeverToScanPosition,
  ETaskMovingLeverToEndPosition,
  ETaskMovingDrumToHome1Position,
  ETaskMovingDrumToHome2Position,
  ETaskMovingScanCassettes,
  ETaskMovingCarriageToPosition1,
  ETaskMovingCarriageToPosition2,
  ETaskMovingCarriageToPosition3,
  ETaskMovingCarriageToPosition4,
  ETaskMovingCarriageToPosition5,
  ETaskMovingCarriageToPosition6,

} ETaskMovingQueue;

/**********************************************************************************/
//----------------------------------------------------------------------------------
/**
*  The class containes ... .
*/
class TMovingTask : public TTask
{
public:
  ////// variables //////

  ////// constants //////

  ////// functions //////
  void CreateTask(void);
  QueueHandle_t GetQueueHandle(void);
  SemaphoreHandle_t GetHandleSemaphoreEndAction(void);
  ESystemStatus TakeEndActionSemaphore(unsigned short);
  void GiveEndActionSemaphore(void);
  void GiveEndActionSemaphoreFromIsr(void);
  void SetState(ESystemStatus);
  ESystemStatus GetState(void);
  
  
  ESystemStatus UnlockDrum(void);
  
protected:
  ////// variables //////

  ////// constants //////


  
private:
  ////// variables //////
  QueueHandle_t xQueue;
  SemaphoreHandle_t semaphoreEndAction;
  ESystemStatus state;
  
  unsigned short stepCounter;
  unsigned char arrayCassettesSteps[MOTOR_CARRIAGE_MAX_STEPS];
  unsigned short motorCarriageMaxSteps;
  unsigned short stepsPosition[MOVING_TASK_MAX_NUMBER_CASSETTES-1];
  unsigned char numberCassettes;
  
  // DEBUG
  unsigned short scanArray[240*128];
  unsigned short indexScanArray;
  //unsigned long calculateArray[240];
  unsigned short calibrateArray[128];
  void Calculate(void);
  void Calibrate(void);
  // DEBUG
  
  ////// constants //////

  ////// functions //////
  static void Execute(void*);
  ESystemStatus Reset(void);
  ESystemStatus SetupCarriageToStartPosition(void);
  ESystemStatus SetupCarriageToEndPosition(void);
  ESystemStatus SetupLeverToScanPosition(void);
  ESystemStatus SetupLeverToStartPosition(void);
  ESystemStatus SetupLeverToEndPosition(void);
  ESystemStatus SetupDrumToHome1Position(void);
  ESystemStatus SetupDrumToHome2Position(void);
  ESystemStatus ScanDrum(void);
  void ScanOneStep(void);
  void NoScanOneStep(void);
  
  ESystemStatus LockDrum(void);
  ESystemStatus ScanCassettes(void);
  ESystemStatus SetupCarriageToPosition(unsigned char);

};
//--- end class TMovingTask --------------------------------------------------------

/**********************************************************************************/


/**********************************************************************************/

#endif
