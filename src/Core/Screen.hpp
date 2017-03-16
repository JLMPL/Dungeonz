#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <stdio.h>

struct Screen
{
	static Screen& Get()
	{
		static Screen self;
		return self;
	}

	int width = 0;
	int height = 0;
	int halfWidth = 0;
	int halfHeight = 0;
	bool fullscreen = false;
};

#endif