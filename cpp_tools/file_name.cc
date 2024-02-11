#include "file_name.h"

#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>

std::string GetFileName(const std::string& file_path) {
  return file_path.substr(file_path.find_last_of('/')+1);
}

std::string GetFileNameWithoutExtension(const std::string& file_path) {
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

// Create directory, if suceeded return 0, else return -1 
int MkDir(const std::string& path) {
  int ret = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if (ret) {
    std::cout << "create dir error: " << strerror(errno) << std::endl;
  }
  return ret;
}

std::vector<std::string> GetFilePaths(const std::string& dir) {
  std::vector<std::string> paths;
  DIR *pDir;
  struct dirent* ptr;
  if(!(pDir = opendir(dir.c_str()))) {
      std::cout << dir << " doesn't Exist!" << std::endl;
      return paths;
  }
  while((ptr = readdir(pDir))!=0) {
    if (ptr->d_type == 8) {
      std::string ext = GetFileExtension(ptr->d_name);
      if (ext == "jpg" || ext == "png") {
        paths.push_back(dir + "/" + ptr->d_name);
      }
    }
  }
  closedir(pDir);
  return paths;
}