#ifndef CPP_TOOLS_FILE_MANAGER_H_
#define CPP_TOOLS_FILE_MANAGER_H_

#include <string>
#include <vector>

std::string GetFileName(const std::string& file_path);

std::string GetFileNameWithoutExtension(const std::string& file_path);

std::string GetFileExtension(const std::string& file_path);

int MkDir(const std::string& path);

std::vector<std::string> GetFilePaths(const std::string& dir);

#endif  // CPP_TOOLS_FILE_MANAGER_H_