# 3796C Pinnacle Code

This repository contains the VEX Robotics competition code for team 3796C, the C-Sharks, for the 2026-2027 season and the game Pinnacle.

The project is built in C++ using the VEX V5 platform and includes the team's custom SharkC library, which wraps common drivetrain and subsystem functionality into reusable abstractions.

## Overview

This codebase is responsible for:

- controlling the drivetrain during driver control and autonomous mode
- operating the intake roller
- controlling the cascade lift mechanism
- actuating the claw and claw tilt pistons
- selecting and running autonomous routines from the V5 brain screen

## Robot Design

The robot is configured in `src/robot-config.cpp` and exposes the following major systems:

- Drive base: 6-motor tank drive
- Intake: single motor intake roller
- Lift: dual-motor cascade system
- Claw: pneumatic grabber and tilt mechanism
- Sensor: inertial sensor for heading and autonomous movement

## Hardware Mapping

The robot is wired as follows:

- Left drive: Ports 12, 7, 8
- Right drive: Ports 9, 5, 4
- Intake: Port 1
- Cascade motors: Ports 2 and 3
- Inertial sensor: Port 6
- Pneumatics: Brain Three-Wire Port A and B

## Driver Controls

Driver control is implemented in `src/main.cpp`.

- Arcade drive: left stick moves forward/backward, right stick steers
- Intake:
  - Up = intake in
  - Down = intake out
- Cascade lift:
  - L1 = raise
  - L2 = lower
- Claw:
  - R2 = close
  - R1 = open
- Claw tilt:
  - B = tilt down
  - A = tilt up

## Autonomous Features

Autonomous routines are defined in `src/autons.cpp` and selected by the brain screen during `pre_auton()`.

The project includes:

- a custom `shark::Drive` class with PID-tuned movement commands
- autonomous distance, turn, and swing functions
- constants configured in `defaultConstants()` for drive, heading, turn, and swing behavior
- support for a brain-screen auton selector using `shark::autonSelector()`

## Project Structure

- `src/` – robot source files and subsystem logic
  - `main.cpp` – competition entry points and control loop
  - `robot-config.cpp` – hardware setup and subsystem initialization
  - `autons.cpp` – autonomous routines and PID constants
  - `SharkC/` – custom movement and subsystem library code
- `include/` – public headers for robot code and SharkC modules
- `vex/` – VEX build system configuration files
- `build/` – compiled outputs such as `.bin` and `.elf` files
- `makefile` – project build target for compiling the robot program

## Building

From the project root, run:

```bash
make
```

This will build the robot program using the VEX toolchain and place the output in the `build/` directory.

## Notes

This project is designed around reusable, modular robot code. The custom SharkC library abstracts common operations so that the main control file stays readable while autonomous and subsystem logic remain easy to tune and expand.
