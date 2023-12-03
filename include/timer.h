#ifndef CPP_TOOLS_TIME_H_
#define CPP_TOOLS_TIME_H_

#include <chrono>

std::chrono::steady_clock::time_point Now();

double Duration(std::chrono::steady_clock::time_point t2,
                std::chrono::steady_clock::time_point t1);

#endif  // CPP_TOOLS_TIME_H_