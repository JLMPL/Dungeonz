#ifndef ERROR_HPP
#define ERROR_HPP
#include <string>

static void ShowErrorBox(const std::string& message)
{
    printf("%s\n", message.c_str());
}

#endif
