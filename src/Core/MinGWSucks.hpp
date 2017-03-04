#ifndef MINGW_SUCKS_HPP
#define MINGW_SUCKS_HPP
#include <sstream>
#include <cstdio>

/*
    Not knowing why MinGW shipped with CodeBlocks 16.01
    doesn't support these functions. I hate compiling stuff
    on windows(MinGW) it's always such a pain in the ass.
*/

namespace std
{

template <typename T>
static std::string to_string(T v)
{
    std::stringstream ss;
    ss << v;
    printf("MinGW Sucks Ass!!!\n");
    return ss.str();
}

static int stoi(std::string str)
{
    int result = 0;
    std::stringstream ss;
    ss << str;
    ss >> result;
    printf("MinGW Sucks Ass!!!\n");
    return result;
}

static float stof(std::string str)
{
    float result = 0;
    std::stringstream ss;
    ss << str;
    ss >> result;
    printf("MinGW Sucks Ass!!!\n");
    return result;
}

};

#endif