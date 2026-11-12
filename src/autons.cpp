#include "sharkc.h"

// Set to 1 to add the test routines to the auton selector.
#define SHARK_TESTS 0

/**
 * Resets the constants for auton movement.
 */
void defaultConstants()
{
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.setDriveConstants(10, 1.5, 0, 10, 0);
  chassis.setHeadingConstants(6, .4, 0, 1, 0);
  chassis.setTurnConstants(12, .4, .03, 3, 15);
  chassis.setSwingConstants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.setDriveExitConditions(1.5, 300, 5000);
  chassis.setTurnExitConditions(1, 300, 3000);
  chassis.setSwingExitConditions(1, 300, 3000);
}

/*
 * YOUR AUTONS
 *
 * Each SHARK_AUTON shows up in the brain screen selector, in the order
 * it appears in this file. Nothing else to declare or register.
 */

// SHARK_AUTON("Example") {
//   chassis.drive_distance(24);
//   claw.close();
//   cascade.raise(1.5);   // raise for 1.5 seconds, then hold
//   intake.in(2);         // run intake for 2 seconds
//   chassis.turn_to_angle(90);
//   claw.open();
// }

SHARK_AUTON("One Pin")
{
  cascade.raise(0.2);
  chassis.driveDistance(7, 50);
  claw.tiltUp();
  cascade.lower(0.2);
  wait(10, vex::msec);
  claw.open();
}

SHARK_AUTON("Ghoulscore L")
{
  cascade.raise(0.5);
  claw.close();
  chassis.driveDistance(7, 50);
  chassis.turnToAngle(45, 50);
  claw.open();
  chassis.driveDistance(10, 50);
  cascade.lower(0.2);
  claw.close();
  cascade.raise(0.5);
}

SHARK_AUTON("Ghoulscore R")
{
  cascade.raise(0.5);
  claw.close();
  chassis.driveDistance(7, 50);
  chassis.turnToAngle(-45, 50);
  claw.open();
  chassis.driveDistance(10, 50);
  cascade.lower(0.2);
  claw.close();
  cascade.raise(0.5);
}

SHARK_AUTON("Neutral")
{
  claw.close();
  chassis.driveDistance(15, 50);
  cascade.raise(0.6);
  chassis.driveDistance(1, 50);
  cascade.lower(0.2);
  claw.open();                      // this is where the starting pin goes down
  chassis.driveDistance(-3.40, 50);
  cascade.lower(0.4);
  chassis.turnToAngle(180, 30);     // should be able to turn and go where it started to pick up new pin
  chassis.driveDistance(13, 50);
  claw.close();                     // picks up new pin
  chassis.driveDistance(-3.40, 50);
  chassis.turnToAngle(180, 30);
  chassis.driveDistance(12, 50);
  cascade.raise(0.8);
  chassis.driveDistance(1, 50);
  cascade.lower(0.2);               // this is where the picked up pin goes down
  claw.open();
  chassis.driveDistance(-3.40, 50);
  cascade.lower(0.6);
  chassis.turnToAngle(180, 30);
  chassis.driveDistance(13, 50);
  claw.close();                     // this is where the second pin gets picked up
  chassis.driveDistance(-3, 50);
  chassis.turnToAngle(180, 30);
  chassis.driveDistance(12, 50);
  cascade.raise(1.0);
  chassis.driveDistance(1, 50);
  cascade.lower(0.2);
  claw.open();
  chassis.driveDistance(-3.40, 50);
  cascade.lower(0.6);
}

// SHARK_AUTON("Shark") {
//   cascade.raise(0.4);
//   chassis.driveDistance(13, 50);
//   claw.tiltUp();
//   cascade.lower(0.2);
//   claw.open();
// }
//
// SHARK_AUTON("Middle_L"){
//   chassis.turnToAngle(-45);
//   cascade.raise(0.5);
//   chassis.driveDistance(15, 50);
//   claw.open();
//   cascade.lower(0.2);
// }
//
// SHARK_AUTON("left_side"){
//     cascade.raise(0.5);
//     claw.close();
//     chassis.turnToAngle(45,50);
//     chassis.driveDistance(10,50);
//     cascade.lower(0.2);
//     claw.open();
// }
//
// SHARK_AUTON("right_side"){
//     cascade.raise(0.5);
//     claw.close();
//     chassis.driveDistance(7,50);
//     chassis.turnToAngle(-45,50);
//     chassis.driveDistance(10,50);
//     cascade.lower(0.2);
//     claw.open();
// }
//
// SHARK_AUTON("neutral"){
//     cascade.raise(0.4);
// }

/*
 * JAR TEST ROUTINES (SHARK_TESTS)
 */
#if SHARK_TESTS

// Should return to the start position.
SHARK_AUTON("Test: Drive")
{
  chassis.driveDistance(6);
  chassis.driveDistance(12);
  chassis.driveDistance(18);
  chassis.driveDistance(-36);
}

// Should make a full turn and return to the start angle.
SHARK_AUTON("Test: Turn")
{
  chassis.turnToAngle(5);
  chassis.turnToAngle(30);
  chassis.turnToAngle(90);
  chassis.turnToAngle(225);
  chassis.turnToAngle(0);
}

// Should swing in an S shape.
SHARK_AUTON("Test: Swing")
{
  chassis.leftSwingToAngle(90);
  chassis.rightSwingToAngle(0);
}

// Should end roughly where it started.
SHARK_AUTON("Test: Full")
{
  chassis.driveDistance(24);
  chassis.turnToAngle(-45);
  chassis.driveDistance(-36);
  chassis.rightSwingToAngle(-90);
  chassis.driveDistance(24);
  chassis.turnToAngle(0);
}

#endif
