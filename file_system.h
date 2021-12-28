#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include <vector>

std::vector<std::string> get_files(std::string dir);
std::vector<std::string> file_system_read(std::string file_name);

#endif // FILE_SYSTEM_H
