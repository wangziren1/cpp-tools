#ifndef CPP_TOOLS_FILE_NAME_H_
#define CPP_TOOLS_FILE_NAME_H_

#include <string>

std::string GetFileName(const std::string& file_path);

std::string GetFileNameWithoutSuffix(const std::string& file_path);

std::string GetFileExtension(const std::string& file_path);

#endif  // CPP_TOOLS_FILE_NAME_H_