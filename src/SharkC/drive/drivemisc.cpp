#pragma once
#include "SharkC/drive.h"
#include <math.h>

namespace shark {
  
  static double deadband(double value, double width) {
    return fabs(value) < width ? 0 : value;
  };

  Drive::Drive(
    vex::motor_group &leftMotors,
    vex::motor_group &rightMotors,
    int inertialPort,
    double wheelDiameter,
    double gearRatio,
    double scale)
    : left(leftMotors),
      right(rightMotors),
      gyro(inertialPort),
      inchesPerDegree(gearRatio / 360.0 * M_PI * wheelDiameter),
      gyroScale(scale),
      desiredHeading(0),
      driveK{10, 1.5, 0, 10, 0},
      headingK{6, .4, 0, 1, 0},
      turnK{12, .4, .03, 3, 15},
      swingK{12, .3, .001, 2, 15},
      driveExit{1.5, 300, 5000},
      turnExit{1, 300, 3000},
      swingExit{1, 300, 3000}
      {}

} // namespace shark
