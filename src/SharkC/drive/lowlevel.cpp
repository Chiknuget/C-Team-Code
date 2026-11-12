#include "SharkC/drive.h"
#include <math.h>

namespace shark {
  
  // Low level

  void Drive::driveVoltage(double leftVolts, double rightVolts) {
    left.spin(vex::forward, leftVolts, vex::volt);
    right.spin(vex::forward, rightVolts, vex::volt);
  }

  void Drive::stop(vex::brakeType mode) {
    left.stop(mode);
    right.stop(mode);
  }

} // namespace shark
