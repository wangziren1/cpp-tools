#include "file_name.h"

std::string GetFileName(const std::string& file_path) {
  return file_path.substr(file_path.find_last_of('/')+1);
}

std::string GetFileNameWithoutSuffix(const std::string& file_path) {
  std::string file_name = GetFileName(file_path);
  return file_name.substr(0, file_name.find_last_of('.'));
}

std::string GetFileExtension(const std::string& file_path) {
  auto pos = file_path.find_last_of('.');
  if (pos == std::string::npos)
    return "";
  else
    return file_path.substr(pos+1);
}