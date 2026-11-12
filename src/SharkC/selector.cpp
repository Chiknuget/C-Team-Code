#include "sharkc.h"

namespace shark {

static Auton autons[MAX_AUTONS];
static int count = 0;
static int selected = 0;

int autonCount() { return count; }
Auton &getAuton(int index) { return autons[index]; }

AutonRegistrar::AutonRegistrar(const char *name, void (*routine)()) {
  if (count < MAX_AUTONS) {
    autons[count].name = name;
    autons[count].routine = routine;
    count++;
  }
}

void autonSelector(vex::competition &comp) {
  int lastShownOnController = -1;

  while (!comp.isEnabled()) {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "SharkC v2 | C-Sharks 3796C");
    Brain.Screen.printAt(5, 40, "Battery: %d%%", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 60, "Heading: %.1f", chassis.getHeading());

    if (count == 0) {
      Brain.Screen.printAt(5, 100, "No autons registered");
    } else {
      Brain.Screen.printAt(5, 100, "Auton %d of %d:", selected + 1, count);
      Brain.Screen.printAt(5, 120, true, "%s", autons[selected].name);
      Brain.Screen.printAt(5, 160, "Tap screen to change");

      if (selected != lastShownOnController) {
        Controller1.Screen.clearLine(1);
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("%s", autons[selected].name);
        lastShownOnController = selected;
      }

      if (Brain.Screen.pressing()) {
        while (Brain.Screen.pressing()) vex::wait(10, vex::msec);
        selected = (selected + 1) % count;
      }
    }
    vex::wait(20, vex::msec);
  }
}

void runSelectedAuton() {
  if (count > 0) autons[selected].routine();
}

} // namespace shark
