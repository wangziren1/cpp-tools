#ifndef CPP_TOOLS_TIMER_H_
#define CPP_TOOLS_TIMER_H_

#include <chrono>

std::chrono::steady_clock::time_point Now();

// how many milliseconds are there between t1 and t2
double Duration(std::chrono::steady_clock::time_point t2,
                std::chrono::steady_clock::time_point t1);

#endif  // CPP_TOOLS_TIMER_H_