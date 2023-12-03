#ifndef CPP_TOOLS_TIME_H_
#define CPP_TOOLS_TIME_H_

#include <chrono>

std::chrono::system_clock::time_point Now();

std::chrono::duration<double> Duration(std::chrono::system_clock::time_point t2,
                                       std::chrono::system_clock::time_point t1);

#endif  // CPP_TOOLS_TIME_H_