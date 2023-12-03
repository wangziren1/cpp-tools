#include "timer.h"


#include <iostream>
 
std::chrono::system_clock::time_point Now() {
  return std::chrono::system_clock::now();
}

std::chrono::duration<double> Duration(
    std::chrono::system_clock::time_point t2,
    std::chrono::system_clock::time_point t1) {
  return std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
}

