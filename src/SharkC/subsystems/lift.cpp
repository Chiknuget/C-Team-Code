#include "SharkC/subsystems.h"
#include "subsysmisc.cpp"

namespace shark {
  
  // Lift

  Lift::Lift(
    vex::motor_group &motorGroup, 
    vex::directionType upDirection, 
    double speedPercent
  )
    : motors(motorGroup), 
      upDir(upDirection), 
      downDir(opposite(upDirection)), 
      speed(speedPercent) 
      {}
  
  void Lift::raise() { 
    motors.spin(
      upDir, 
      speed, 
      vex::percent); 
    }
  void Lift::lower() { 
    motors.spin(downDir, 
      speed, 
      vex::percent); 
    }
  void Lift::hold() { 
    motors.stop(
      vex::hold
    ); 
  }

  void Lift::raise(
    double seconds
  ) { 
    raise(); 
    vex::wait(
      seconds, 
      vex::sec
    ); 
    hold(); 
  }
  void Lift::lower(
    double seconds
  ) { 
    lower(); 
    vex::wait(seconds, 
      vex::sec
    ); 
    hold(); 
  }

  void Lift::setSpeed(
    double percent
  ) { 
    speed = percent; 
  }

  void Lift::control(
    const vex::controller::button &upButton, 
    const vex::controller::button &downButon
  ) {
    if (upButton.pressing()) raise();
    else if (downButon.pressing()) lower();
    else hold();
  }

} // namespace shark
