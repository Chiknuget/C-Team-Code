#include "SharkC/drive.h"
#include <math.h>
#include "drivemisc.cpp"

namespace shark {
  
  // Driver control

void Drive::arcade(vex::controller &ctrl) {
  double throttle = deadband(ctrl.Axis3.position(), 5);
  double turn = deadband(ctrl.Axis1.position(), 5);

  double leftVolts = (throttle + turn) * 12.0 / 100.0;
  double rightVolts = (throttle - turn) * 12.0 / 100.0;

  // Full throttle plus full turn can ask for more than 12 V. Scale both sides
  // together so the robot still turns instead of one side maxing out.
  double largest = fmax(fabs(leftVolts), fabs(rightVolts));
  if (largest > 12.0) {
    leftVolts *= 12.0 / largest;
    rightVolts *= 12.0 / largest;
  }

  driveVoltage(leftVolts, rightVolts);
}

  void Drive::tank(vex::controller &ctrl) {
    double leftStick = deadband(ctrl.Axis3.position(), 5);
    double rightStick = deadband(ctrl.Axis2.position(), 5);
    driveVoltage(leftStick * 12.0 / 100.0, rightStick * 12.0 / 100.0);
  }

} // namespace shark
