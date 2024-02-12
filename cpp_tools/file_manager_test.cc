#include "file_manager.h"

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
  std::string file_name_without_suffix = GetFileNameWithoutExtension(path);
  EXPECT_EQ(file_name_without_suffix, "timer") << file_name_without_suffix;

  path = "/home/wang/cpp-tools/cpp_tools/timer";
  file_name_without_suffix = GetFileNameWithoutExtension(path);
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

TEST(mkdirTest, makedir) {
  std::string dir = "./test";
  EXPECT_EQ(MkDir(dir), 0);
}

TEST(mkdirTest, make_existing_dir) {
  std::string dir = "./test";
  EXPECT_EQ(MkDir(dir), -1);
}

TEST(mkdirTest, make_recursive_dir) {
  std::string dir = "./test/a";
  EXPECT_EQ(MkDir(dir), 0);
}

TEST(GetFilePathsTest, list) {
  std::string dir = ".";
  GetFilePaths(dir);
}