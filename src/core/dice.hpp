#ifndef DICE_HPP
#define DICE_HPP
#include <cstdlib>

namespace dice
{

static int roll(int min, int max)
{
	return (rand()%(max-min)) + min;
}

};

#endif