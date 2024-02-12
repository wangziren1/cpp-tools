find_package(OpenCV REQUIRED)

set(src timer.cc file_manager.cc object_detect.cc)

add_library(cpp_tools ${src})
add_library(cpp_tools::cpp_tools ALIAS cpp_tools)
target_include_directories(cpp_tools PUBLIC "${CMAKE_SOURCE_DIR}/include" ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cpp_tools PUBLIC ${OpenCV_LIBS})

# test
enable_testing()

function(cpp_tools_test test_file)
  get_filename_component(test_target_name "${test_file}" NAME_WE)
  add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
      PRIVATE
        "${test_file}"
    )
  target_link_libraries("${test_target_name}" cpp_tools GTest::gtest_main)
  add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
endfunction(cpp_tools_test)

cpp_tools_test(timer_test.cc)
cpp_tools_test(file_manager_test.cc)
cpp_tools_test(object_detect_test.cc)