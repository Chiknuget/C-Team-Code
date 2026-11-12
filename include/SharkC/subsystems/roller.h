#pragma once
#include "v5.h"
#include "v5_vcs.h"

namespace shark {

  /*
   * Roller: motors that spin in or out
   */
  class Roller {
    public:
      Roller(
        vex::motor_group &motorgroup,
        vex::directionType inDirection = vex::forward,
        double speedPercent = 100
      );

      void in();    // start spinning until stop
      void out();   // start spinning out
      void stop();  // do I even need to explain this?
      void in(      // spin in for some time, then stop
        double seconds
      );
      void out(     // spin out for some time, then stop
        double seconds
      );

      void setSpeed(
        double percent
      );
      void setStopMode(
        vex::brakeType
      );

      /*
       * Driver control:
       * hold inButton to spin in,
       * outButton to spin out.
       */
      void control(
        const vex::controller::button &inButton,
        const vex::controller::button &outButton
      );

    private:
      vex::motor_group &motors;
      vex::directionType inDir, outDir;
      double speed;
      vex::brakeType stopMode;
  };
} // namespace shark
