#include "SharkC/subsystems.h"

namespace shark {

  // Claw

  Claw::Claw(
    vex::digital_out &gripPiston, 
    vex::digital_out &tiltPiston
  )
    : grip(gripPiston), 
    tilt(tiltPiston), 
    closedState(false), 
    downState(false) 
    {}

  void Claw::open() { 
    grip.set(true); 
    closedState = false; 
  }
  void Claw::close() { 
    grip.set(false);  
    closedState = true; 
  }
  void Claw::toggle() { 
    if (closedState) open();
    else close(); 
  }
  bool Claw::isClosed() { 
    return closedState; 
  }

  void Claw::tiltUp() { 
    tilt.set(true); 
    downState = false; 
  }
  void Claw::tiltDown() { 
    tilt.set(false);  
    downState = true; 
  }
  void Claw::toggleTilt() { 
    if (downState) tiltUp(); 
    else tiltDown(); 
  }
  bool Claw::isTiltedDown() {
    return downState; 
  }

  void Claw::control(
    const vex::controller::button &closeButton, 
    const vex::controller::button &openButton
  ) {
    if (closeButton.pressing() && !closedState) close();
    else if (openButton.pressing() && closedState) open();
  }

  void Claw::tiltControl(
    const vex::controller::button &downButton, 
    const vex::controller::button &upButton
  ) {
    if (downButton.pressing() && !downState) tiltDown();
    else if (upButton.pressing() && downState) tiltUp();
  }

} // namespace shark
