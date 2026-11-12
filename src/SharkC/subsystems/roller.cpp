#include "SharkC/subsystems.h"
#include "subsysmisc.cpp"

namespace shark {
  
  // Roller

  Roller::Roller(
    vex::motor_group &motorGroup,
    vex::directionType inDirection,
    double speedPercent
  )
    : motors(motorGroup),
      inDir(inDirection),
      outDir(opposite(inDirection)),
      speed(speedPercent), stopMode(vex::hold)
      {}
  
  void Roller::in() { 
    motors.spin(
      inDir, 
      speed, 
      vex::percent
    ); 
  }
  void Roller::out() { 
    motors.spin(
      outDir, 
      speed, 
      vex::percent
    ); 
  }
  void Roller::stop() { 
    motors.stop(
      stopMode
    ); 
  }

  void Roller::in(
    double seconds
  ) { 
    in();  
    vex::wait(
      seconds, 
      vex::sec
    ); 
    stop();
  }
  void Roller::out(
    double seconds
  ) { 
    out(); 
    vex::wait(
      seconds, 
      vex::sec
    ); 
    stop(); 
  }

  void Roller::setSpeed(
    double percent
  ) { 
    speed = percent; 
  }
  void Roller::setStopMode(
    vex::brakeType mode
  ) { 
    stopMode = mode; 
  }

  void Roller::control(
    const vex::controller::button &inButton, 
    const vex::controller::button &outButton
  ) {
    if (inButton.pressing()) in();
    else if (outButton.pressing()) out();
    else stop();
  }

} // namespace shark
