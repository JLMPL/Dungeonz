#include "StatePlaying.hpp"

StatePlaying::StatePlaying()
{
}

void StatePlaying::init()
{
	level.init("second_test.tmx", nullptr);
}

void StatePlaying::update(float deltaTime)
{
	level.update(deltaTime);
}

void StatePlaying::leave()
{

}
