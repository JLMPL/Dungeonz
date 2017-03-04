#include "StatePlaying.hpp"

StatePlaying::StatePlaying()
{

}

void StatePlaying::init()
{
	level.init();
}

void StatePlaying::update(float deltaTime)
{
	level.update(deltaTime);
}

void StatePlaying::leave()
{

}
