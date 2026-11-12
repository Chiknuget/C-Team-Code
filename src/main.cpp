#include "sharkc.h"

competition Competition;

void pre_auton() {
  vexcodeInit();          // DO NOT REMOVE
  chassis.calibrate();    // keep the robot still for ~2 seconds
  claw.tiltUp();          // start tilted up
  claw.close();           // and closed
  defaultConstants();
  shark::autonSelector(Competition);  // tap the brain screen to pick an auton
}

void autonomous() {
  shark::runSelectedAuton();
}

void usercontrol() {
  while (true) {
    chassis.arcade(Controller1);                                  // left stick: forward/back, right stick: turn
    intake.control(Controller1.ButtonX, Controller1.ButtonY);     // X: in, Y: out
    cascade.control(Controller1.ButtonL2, Controller1.ButtonL1);  // L2: up, L1: down
    claw.control(Controller1.ButtonR2, Controller1.ButtonR1);     // R2: close, R1: open
    claw.tiltControl(Controller1.ButtonB, Controller1.ButtonA);   // B: down, A: up
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
