#include "sharkc.h"

// Set to 1 to add the test routines to the auton selector.
#define SHARK_TESTS 0

/**
 * Resets the constants for auton movement.
 */
void defaultConstants(){
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

SHARK_AUTON("One Pin") {
  cascade.raise(0.2);
  chassis.driveDistance(7, 50);
  claw.tiltUp();
  cascade.lower(0.2);
  wait(10, vex::msec);
  claw.open();
}

SHARK_AUTON("Blood Hunt L") {
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

SHARK_AUTON("Blood Hunt R") {
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
SHARK_AUTON("Test: Drive") {
  chassis.driveDistance(6);
  chassis.driveDistance(12);
  chassis.driveDistance(18);
  chassis.driveDistance(-36);
}

// Should make a full turn and return to the start angle.
SHARK_AUTON("Test: Turn") {
  chassis.turnToAngle(5);
  chassis.turnToAngle(30);
  chassis.turnToAngle(90);
  chassis.turnToAngle(225);
  chassis.turnToAngle(0);
}

// Should swing in an S shape.
SHARK_AUTON("Test: Swing") {
  chassis.leftSwingToAngle(90);
  chassis.rightSwingToAngle(0);
}

// Should end roughly where it started.
SHARK_AUTON("Test: Full") {
  chassis.driveDistance(24);
  chassis.turnToAngle(-45);
  chassis.driveDistance(-36);
  chassis.rightSwingToAngle(-90);
  chassis.driveDistance(24);
  chassis.turnToAngle(0);
}

#endif
