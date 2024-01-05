#include "file_name.h"

#include <gtest/gtest.h>

TEST(FileNameTest, FileName) {
  std::string path = "/home/wang/cpp-tools/cpp_tools/timer.cc";
  std::string file_name = GetFileName(path);
  EXPECT_EQ(file_name, "timer.cc") << file_name;

  path = "timer.cc";
  file_name = GetFileName(path);
  EXPECT_EQ(file_name, "timer.cc") << file_name;
}

TEST(FileNameTest, FileNameWithoutSuffix) {
  std::string path = "/home/wang/cpp-tools/cpp_tools/timer.cc";
  std::string file_name_without_suffix = GetFileNameWithoutSuffix(path);
  EXPECT_EQ(file_name_without_suffix, "timer") << file_name_without_suffix;

  path = "/home/wang/cpp-tools/cpp_tools/timer";
  file_name_without_suffix = GetFileNameWithoutSuffix(path);
  EXPECT_EQ(file_name_without_suffix, "timer") << file_name_without_suffix;
}

TEST(FileNameTest, FileExtension) {
  std::string path = "/home/wang/cpp-tools/cpp_tools/timer.cc";
  std::string file_suffix = GetFileExtension(path);
  EXPECT_EQ(file_suffix, "cc") << file_suffix;

  path = "/home/wang/cpp-tools/cpp_tools/timer";
  file_suffix = GetFileExtension(path);
  EXPECT_EQ(file_suffix, "");
}