#include "timer.h"


#include <iostream>
 
std::chrono::steady_clock::time_point Now() {
  return std::chrono::steady_clock::now();
}

double Duration(std::chrono::steady_clock::time_point t2,
                std::chrono::steady_clock::time_point t1) {
  return std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)
      .count();
}

