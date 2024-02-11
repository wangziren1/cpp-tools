#include "timer.h"

std::chrono::steady_clock::time_point Now() {
  return std::chrono::steady_clock::now();
}

// How many seconds are there between t2 and t1
double Duration(std::chrono::steady_clock::time_point t2,
                std::chrono::steady_clock::time_point t1) {
  return std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)
      .count();
}

