#include "sharkc.h"

using namespace vex;

/*
 *  All robot hardware lives here.
 *  Order matters: things are defined before they are used below.
 */

brain Brain;
controller Controller1 = controller(primary);

// Intake / Cascade
motor IN = motor(PORT1, ratio18_1, true);
motor CL = motor(PORT2, ratio18_1, false);
motor CR = motor(PORT3, ratio18_1, true);

// Left
motor LF = motor(PORT12, ratio18_1, true);
motor LM = motor(PORT7, ratio18_1, true);
motor LB = motor(PORT8, ratio18_1, true);

// Right
motor RF = motor(PORT9, ratio18_1, false);
motor RM = motor(PORT5, ratio18_1, false);
motor RB = motor(PORT4, ratio18_1, false);

// Pneumatics
digital_out CS = digital_out(Brain.ThreeWirePort.A);
digital_out CT = digital_out(Brain.ThreeWirePort.B);

// Motor groups
motor_group leftDrive(LF, LM, LB);
motor_group rightDrive(RF, RM, RB);
motor_group intakeMotors(IN);
motor_group cascadeMotors(CR, CL);

// Drivetrain
//                   left       right       inertial  wheel gear  gyro
shark::Drive chassis(leftDrive, rightDrive, PORT6,    3.25, 0.75, 360);

// Subsystems
shark::Roller intake(intakeMotors, forward);    // Up arrow (forward) = in
shark::Lift   cascade(cascadeMotors, reverse);  // L1 (reverse) = up
shark::Claw   claw(CS, CT);                     // CS true = closed, CT true = down

void vexcodeInit(void) {
  // nothing to initialize
}
