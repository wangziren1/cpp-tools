#include "timer.h"

#include <thread>

#include <gtest/gtest.h>

void f() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

TEST(TimerTest, BasicAssertions) {
  auto t1 = Now();
  f();
  auto t2 = Now();
  std::cout << Duration(t2, t1).count() << std::endl;
}