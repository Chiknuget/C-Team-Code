#pragma once

namespace shark {

  const double LOOP_MS = 10;  // all control loops run every 10 ms

  struct PIDConstants {
    double maxVoltage;
    double kP, kI, kD;
    double startI; // only build up kI when error is smaller than this
  };

  struct ExitConditions {
    double settleError; // close enough (inches or degrees)
    double settleTime;  // must stay close enough for this long (ms)
    double timeout;     // give up after this long (ms), 0 = never
  };

  class PID {
    public:
      PID(double startingError, PIDConstants constants, ExitConditions exitConditions);
      double compute(double error); // call once per loop, returns volts
      bool isSettled();

    private:
      PIDConstants k;
      ExitConditions exitConds;
      double accumulatedError;
      double previousError;
      double timeSettled;
      double timeRunning;
  };

  double clamp(double value, double min, double max);
  double wrapAngle180(double angle);  // turns any angle into -180 to 180

} // namespace shark
