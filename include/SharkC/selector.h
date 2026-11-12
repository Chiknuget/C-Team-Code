#pragma once
#include "v5.h"
#include "v5_vcs.h"

namespace shark {

  const int MAX_AUTONS = 32;

  struct Auton {
    const char *name;
    void (*routine)();
  };

  // How many autons are registered, and access to each one.
  int autonCount();
  Auton &getAuton(int index);

  struct AutonRegistrar {
    AutonRegistrar(const char *name, void (*routine)());
  };

  // Brain-screen auton selector. Tap the screen to cycle.
  // Runs until the robot is enabled (match starts).
  void autonSelector(vex::competition &comp);

  // Runs whichever auton was selected.
  void runSelectedAuton();

} // namespace shark

/*
 *  SHARK_AUTON("Name") { ...steps... }
 *  Defines an auton and adds it to the selector automatically.
 */
#define SHARK_CONCAT_(a, b) a##b
#define SHARK_CONCAT(a, b) SHARK_CONCAT_(a, b)

#define SHARK_AUTON(name)                                                      \
  static void SHARK_CONCAT(shark_auton_fn_, __LINE__)();                       \
  static shark::AutonRegistrar SHARK_CONCAT(shark_auton_reg_, __LINE__)(       \
      name, SHARK_CONCAT(shark_auton_fn_, __LINE__));                          \
  static void SHARK_CONCAT(shark_auton_fn_, __LINE__)()
