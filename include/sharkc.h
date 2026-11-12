/*
 * SharkC - the 3796C C-Sharks robot library
 * Include this file and all will be available to you:
 * VEX, JAR-Template, hardware, subsystems, and autons
 */
#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "v5.h"
#include "v5_vcs.h"

#include "SharkC/pid.h"
#include "SharkC/drive.h"
#include "SharkC/subsystems.h"
#include "robot-config.h"
#include "autons.h"
#include "SharkC/selector.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
