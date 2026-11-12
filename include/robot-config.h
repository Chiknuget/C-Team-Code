#pragma once
#include "SharkC/subsystems.h"
#include "SharkC/drive.h"

using namespace vex;

extern brain Brain;
extern controller Controller1;  //The controller Connor will use

extern motor LF;        ///
extern motor LM;        //Left
extern motor LB;        ///
extern motor RF;        ///
extern motor RM;        //Right
extern motor RB;        ///
extern motor IN;        //Intake
extern motor CR;        //Cascade Right
extern motor CL;        //Cascade Left

extern digital_out CS;   //Claw State (Open/Closed)
extern digital_out CT;   //Claw Tilt (Up/Down)

extern motor_group leftDrive;
extern motor_group rightDrive;
extern motor_group intakeMotors;
extern motor_group cascadeMotors;

// SharkC subsystems
extern shark::Drive  chassis;
extern shark::Roller intake;
extern shark::Lift   cascade;
extern shark::Claw   claw;

void vexcodeInit(void);
