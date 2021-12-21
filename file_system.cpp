#include <string>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "file_system.h"

const size_t STEP = 10;

std::string files[FILE_SYSTEM_MAX_FILES_COUNT];

char **file_system_show_txt_files(std::string dir)
{
    size_t size = STEP;
    char **result = (char**) malloc(size * sizeof(char*));
    size_t index = 0;

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
            result[index] = (char*) malloc(file_name.length() * sizeof (char));
            memcpy(result[index], file_name.c_str(), file_name.length());
            ++index;

            if (index == size)
            {
                size += STEP;
                result = (char**) realloc(result, size * sizeof(char*));
            }
        }
    }

    closedir(dp);

    if (index == size)
    {
        size++;
        result = (char**) realloc(result, size * sizeof(char*));
    }

    result[index] = NULL;

    return result;
}
