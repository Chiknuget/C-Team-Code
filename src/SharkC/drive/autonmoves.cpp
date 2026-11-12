#include "SharkC/drive.h"
#include <math.h>

namespace shark {

  // Auton moves

  void Drive::driveDistance(double inches) {
    driveDistance(inches, 100, desiredHeading);
  }

  void Drive::driveDistance(double inches, double speed) {
    driveDistance(inches, speed, desiredHeading);
  }

  void Drive::driveDistance(double inches, double speed, double heading) {
    desiredHeading = heading;

    PIDConstants k = driveK;
    k.maxVoltage *= clamp(speed, 0, 100) / 100.0;

    PID drivePID(inches, k, driveExit);
    PID headingPID(wrapAngle180(heading - getHeading()), headingK, ExitConditions{0, 0, 0});
    double start = (getLeftInches() + getRightInches()) / 2.0;

    while (!drivePID.isSettled()) {
      double traveled = (getLeftInches() + getRightInches()) / 2.0 - start;
      double driveOut = drivePID.compute(inches - traveled);
      double headingOut = headingPID.compute(wrapAngle180(heading - getHeading()));
      driveVoltage(driveOut + headingOut, driveOut - headingOut);
      vex::wait(LOOP_MS, vex::msec);
    }
    stop(vex::hold);
  }

  void Drive::turnToAngle(double angle) {
    turnToAngle(angle, 100);
  }

  void Drive::turnToAngle(double angle, double speed) {
    desiredHeading = angle;

    PIDConstants k = turnK;
    k.maxVoltage *= clamp(speed, 0, 100) / 100.0;

    PID turnPID(wrapAngle180(angle - getHeading()), k, turnExit);

    while (!turnPID.isSettled()) {
      double out = turnPID.compute(wrapAngle180(angle - getHeading()));
      driveVoltage(out, -out);
      vex::wait(LOOP_MS, vex::msec);
    }
    stop(vex::hold);
  }

  void Drive::leftSwingToAngle(double angle) {
    desiredHeading = angle;
    PID swingPID(wrapAngle180(angle - getHeading()), swingK, swingExit);

    while (!swingPID.isSettled()) {
      double out = swingPID.compute(wrapAngle180(angle - getHeading()));
      left.spin(vex::forward, out, vex::volt);
      right.stop(vex::hold);
      vex::wait(LOOP_MS, vex::msec);
    }
    stop(vex::hold);
  }

  void Drive::rightSwingToAngle(double angle) {
    desiredHeading = angle;
    PID swingPID(wrapAngle180(angle - getHeading()), swingK, swingExit);

    while (!swingPID.isSettled()) {
      double out = swingPID.compute(wrapAngle180(angle - getHeading()));
      right.spin(vex::reverse, out, vex::volt);
      left.stop(vex::hold);
      vex::wait(LOOP_MS, vex::msec);
    }
    stop(vex::hold);
  }

} // namespace shark
