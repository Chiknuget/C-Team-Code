#include "SharkC/drive.h"
#include <math.h>

namespace shark {
  
  // Sensors

  double Drive::getHeading() {
    double heading = fmod(gyro.rotation(vex::degrees) * 360.0 / gyroScale, 360.0);
    if (heading < 0) heading += 360;
    return heading;
  }
  
  void Drive::setHeading(double angle) {
    gyro.setRotation(angle * gyroScale / 360.0, vex::degrees);
    desiredHeading = angle;
  }
  
  double Drive::getLeftInches() {
    return left.position(vex::degrees) * inchesPerDegree;
  }
  double Drive::getRightInches() {
    return right.position(vex::degrees) * inchesPerDegree;
  }
  
  void Drive::resetPosition() {
    left.resetPosition();
    right.resetPosition();
  }

} // namespace shark
