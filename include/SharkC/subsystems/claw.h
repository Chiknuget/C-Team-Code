#pragma once
#include "v5_vcs.h"

namespace shark {
  
  /*
   * Claw: one piston to grip,
   * one piston to tilt.
   */
  class Claw {
    public:
      Claw(
        vex::digital_out &gripPiston,
        vex::digital_out &tiltPiston
      );

      // Claw state
      void open();
      void close();
      void toggle();
      bool isClosed();

      // Claw tilt
      void tiltUp();
      void tiltDown();
      void toggleTilt();
      bool isTiltedDown();

      /*
       * Drive control:
       * press closeButton to close,
       * openButton to open.
       */
      void control(
        const vex::controller::button &closeButton,
        const vex::controller::button &openButton
      );

      /*
       * Drive control:
       * press downButton to tilt down,
       * upButton to tilt up.
       */
      void tiltControl(
        const vex::controller::button &downButton,
        const vex::controller::button &upButton
      );

    private:
      vex::digital_out &grip;
      vex::digital_out &tilt;
      bool closedState;
      bool downState;
  };
  
} // namespace shark
