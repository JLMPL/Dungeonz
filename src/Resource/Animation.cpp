#include "Animation.hpp"
#include "../Core/Error.hpp"
#include <fstream>

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

		// std::cout << image << "\n";
		// std::cout << numFrames << "\n";
		// std::cout << duration << "\n";
		// std::cout << size.x << "\n";
		// std::cout << size.y << "\n";
		// std::cout << origin.x << "\n";
		// std::cout << origin.y << "\n";
		// std::cout << looping << "\n";
	}
	file.close();
}