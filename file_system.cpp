#include <string>
#include <errno.h>
#include <dirent.h>
#include <iostream>

#include "file_system.h"

std::string files[FILE_SYSTEM_MAX_FILES_COUNT];

void file_system_show_txt_files(std::string dir)
{
    DIR *dp;
    struct dirent *dirp;

    if((dp  = opendir(dir.c_str())) == NULL) {
        std::cout << "Error: can't find files in " << dir << "\n";
    }


    while ((dirp = readdir(dp)) != NULL)
    {
        std::string file_name = std::string(dirp->d_name);
        size_t file_len = file_name.length();
        char file_type[4];

        if (file_len > 4)
        {
            for (size_t i = 1; i <= 4; ++i)
            {
                file_type[4 - i] = file_name[file_len - i];
            }
        }

        if (std::string(file_type) == ".txt")
        {
            std::cout << file_name << "\n";
        }
    }

    closedir(dp);
}
