#include "Files.hpp"
#include <stdio.h>

namespace Files
{
    bool doesFileExist(const char* path)
    {
        FILE* file = nullptr;
        if (file = fopen(path, "r"))
        {
            fclose(file);
            return true;
        }
        return false;
    }
}