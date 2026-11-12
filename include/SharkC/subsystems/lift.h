#pragma once
#include "v5.h"
#include "v5_vcs.h"

namespace shark {
  class Lift {
    public:
      Lift(
        vex::motor_group &motorGroup,
        vex::directionType upDirection = vex::forward,
        double speedPercent = 100
      );

      void raise();
      void lower();
      void hold();
      void raise(
        double seconds
      );
      void lower(
        double seconds
      );

      void setSpeed(
        double percent
      );

      /*
       * Driver control:
       * hold upButton to raise,
       * downButton to lower.
       */
      void control(
        const vex::controller::button &upButton,
        const vex::controller::button &downButton
      );

    public:
      vex::motor_group &motors;
      vex::directionType upDir, downDir;
      double speed;
  };
} // namespace shark
