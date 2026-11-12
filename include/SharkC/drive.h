#pragma once
#include "v5.h"
#include "v5_vcs.h"
#include "SharkC/pid.h"

namespace shark {

  class Drive {
    public:
      Drive(vex::motor_group &leftMotors, vex::motor_group &rightMotors, int inertialPort, double wheelDiameter, double gearRatio, double scale = 360);

      // Setup
      void calibrate(); // calibrates the inertial sensor (~2 sec, keep the robot still)

      void setDriveConstants(double maxVoltage, double kP, double kI, double kD, double startI);
      void setHeadingConstants(double maxVoltage, double kP, double kI, double kD, double startI);
      void setTurnConstants(double maxVoltage, double kP, double kI, double kD, double startI);
      void setSwingConstants(double maxVoltage, double kP, double kI, double kD, double startI);

      void setDriveExitConditions(double settleError, double settleTime, double timeout);
      void setTurnExitConditions(double settleError, double settleTime, double timeout);
      void setSwingExitConditions(double settleError, double settleTime, double timeout);

      // Auton moves
      void driveDistance(double inches);                                // keeps current heading
      void driveDistance(double inches, double speed);                  // keeps current heading
      void driveDistance(double inches, double speed, double heading);  // holds this heading
      void turnToAngle(double angle);
      void turnToAngle(double angle, double speed);
      void leftSwingToAngle(double angle);  // only the left side moves
      void rightSwingToAngle(double angle); // only the right side moves

      // Driver control
      void arcade(vex::controller &ctrl); // left stick drives, right stick turns
      void tank(vex::controller &ctrl);   // each stick runs one side

      // Low level
      void driveVoltage(double leftVolts, double rightVolts);
      void stop(vex::brakeType mode = vex::hold);

      // Sensors
      double getHeading();  // 0 to 360 degrees
      void setHeading(double angle);
      double getLeftInches();
      double getRightInches();
      void resetPosition();

    private:
      vex::motor_group &left;
      vex::motor_group &right;
      vex::inertial gyro;
      double inchesPerDegree;
      double gyroScale;
      double desiredHeading;

      PIDConstants driveK, headingK, turnK, swingK;
      ExitConditions driveExit, turnExit, swingExit;
  };

} // namespace shark
