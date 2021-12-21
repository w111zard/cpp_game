#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>

const size_t FILE_SYSTEM_MAX_FILES_COUNT = 32;

extern std::string files[FILE_SYSTEM_MAX_FILES_COUNT];

#endif // FILE_SYSTEM_H

char **file_system_show_txt_files(std::string dir);
