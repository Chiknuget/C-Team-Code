#include "SharkC/pid.h"
#include <math.h>

namespace shark {

  PID::PID(double startingError, PIDConstants constants, ExitConditions exitConditions)
    : k(constants), exitConds(exitConditions), accumulatedError(0),
      previousError(startingError), timeSettled(0), timeRunning(0) {}

  double PID::compute(double error) {
    if (fabs(error) < k.startI) accumulatedError += error;

    // Reset the integral when we cross the target so it doesn't overshoot
    if ((error > 0 && previousError < 0) || (error < 0 && previousError > 0))
      accumulatedError = 0;

    double output = k.kP * error + k.kI * accumulatedError + k.kD * (error - previousError);
    previousError = error;

    if (fabs(error) < exitConds.settleError) timeSettled += LOOP_MS;
    else timeSettled = 0;
    timeRunning += LOOP_MS;

    return clamp(output, -k.maxVoltage, k.maxVoltage);
  }

  bool PID::isSettled() {
    if (exitConds.timeout != 0 && timeRunning > exitConds.timeout) return true;
    return timeSettled > exitConds.settleTime;
  }

  double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
  }

  double wrapAngle180(double angle) {
    while (angle > 180) angle  -= 360;
    while (angle < -180) angle += 360;
    return angle;
  }

} // namespace shark
