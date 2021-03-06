#include <string>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "file_system.h"

std::vector<std::string> get_files(std::string dir)
{
    std::vector<std::string> files;

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
            files.push_back(file_name);
        }
    }

    closedir(dp);

    return files;
}

std::vector<std::string> file_system_read(std::string file_name)
{
    std::vector<std::string> result;

    std::ifstream in(file_name);

    if (in.is_open())
    {
        std::string file_line;

        while (getline(in, file_line))
        {
            result.push_back(file_line);
        }
    }

    in.close();

    return result;
}
