#include "SharkC/drive.h"
#include <math.h>

namespace shark {
  
  // Setup

  void Drive::calibrate() {
    gyro.calibrate();
    while (gyro.isCalibrating()) vex::wait(25, vex::msec);
  }

  void Drive::setDriveConstants(double maxVoltage, double kP, double kI, double kD, double startI) {
    driveK = PIDConstants{
      maxVoltage, 
      kP, 
      kI, 
      kD, 
      startI
    };
  }
  void Drive::setHeadingConstants(double maxVoltage, double kP, double kI, double kD, double startI) {
    headingK = PIDConstants{
      maxVoltage, 
      kP, 
      kI, 
      kD, 
      startI
    };
  }
  void Drive::setTurnConstants(double maxVoltage, double kP, double kI, double kD, double startI) {
    turnK = PIDConstants{
      maxVoltage, 
      kP, 
      kI, 
      kD, 
      startI
    };
  }
  void Drive::setSwingConstants(double maxVoltage, double kP, double kI, double kD, double startI) {
    swingK = PIDConstants{
      maxVoltage, 
      kP, 
      kI, 
      kD, 
      startI
    };
  }

  void Drive::setDriveExitConditions(double settleError, double settleTime, double timeout) {
    driveExit = ExitConditions{
      settleError, 
      settleTime, 
      timeout
    };
  }
  void Drive::setTurnExitConditions(double settleError, double settleTime, double timeout) {
    turnExit = ExitConditions{
      settleError, 
      settleTime, 
      timeout
    };
  }
  void Drive::setSwingExitConditions(double settleError, double settleTime, double timeout) {
    swingExit = ExitConditions{
      settleError, 
      settleTime, 
      timeout
    };
  }
  
} // namespace shark
