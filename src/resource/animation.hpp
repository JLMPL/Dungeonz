#ifndef animation_hpp
#define animation_hpp
#include "../core/vec2.hpp"
#include <string>

struct Animation
{
	std::string image;
	int numFrames = 0;
	int duration = 0;
	vec2i size;
	vec2i origin;
	bool looping = false;

	void loadFromFile(const std::string& path);
};

#endif
