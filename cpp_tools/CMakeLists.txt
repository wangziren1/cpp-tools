set(src timer.cc file_name.cc)

add_library(cpp_tools ${src})
add_library(cpp_tools::cpp_tools ALIAS cpp_tools)
target_include_directories(cpp_tools PUBLIC "${CMAKE_SOURCE_DIR}/include")

# find_package(GTest)

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

add_executable(
  file_name_test
  file_name_test.cc
)
target_link_libraries(
  file_name_test
  cpp_tools
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(timer_test)
gtest_discover_tests(file_name_test)
# install