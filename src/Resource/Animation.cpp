#include "Animation.hpp"
#include "../Core/Error.hpp"
#include <fstream>
#include <sstream>

#include <iostream>

void Animation::loadFromFile(const std::string& path)
{
    std::string finalpath = "data/Animations/" + path;
    std::ifstream file(finalpath.c_str());

    if (!file.good())
        ShowErrorBox("Failed to load animation file \"" + finalpath + "\"!");
    else
    {
        file >> image;
        file >> numFrames;
        file >> duration;
        file >> size.x;
        file >> size.y;
        file >> origin.x;
        file >> origin.y;
        file >> looping;
    }
    file.close();
}

void Animation::loadFromMemory(void* mems)
{
    const char* file = (char*)mems;

    std::string cont = file;
    std::stringstream stream(cont);

    stream >> image;
    stream >> numFrames;
    stream >> duration;
    stream >> size.x;
    stream >> size.y;
    stream >> origin.x;
    stream >> origin.y;
    stream >> looping;
}