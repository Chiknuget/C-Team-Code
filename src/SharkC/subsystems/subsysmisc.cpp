#pragma once
#include "SharkC/subsystems.h"

namespace shark {
  
  static vex::directionType opposite(vex::directionType dir) {
    return dir == vex::forward ? vex::reverse : vex::forward;
  }

} // namespace shark
