set(src timer.cc)

add_library(cpp_tools ${src})
target_include_directories(cpp_tools PUBLIC "${CMAKE_SOURCE_DIR}/include")

find_package(GTest)
enable_testing()

add_executable(
  timer_test
  timer_test.cc
)
target_link_libraries(
  timer_test
  cpp_tools
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(timer_test)