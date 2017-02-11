#ifndef dice_hpp
#define dice_hpp
#include <cstdlib>

namespace dice
{

static int roll(int min, int max)
{
	return (rand()%(max-min)) + min;
}

};

#endif