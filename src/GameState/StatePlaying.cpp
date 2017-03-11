#include "StatePlaying.hpp"
#include "../Gameplay/Living.hpp"

StatePlaying::StatePlaying()
{
}

void StatePlaying::init()
{
	// m_level.init("map_test.tmx", nullptr);
	// auto exit0 = (Exit*)m_level.getEntityByCode("exit");

	// exit0->setFunc(
	// [=]()
	// {
	// 	printf("Here change will happen %s!\n", exit0->getNext().c_str());
	// });

	m_currLevel = std::unique_ptr<Level>(new Level());
	m_currLevel->init("map_test.tmx", nullptr);

	auto exit0 = (Exit*)m_currLevel->getEntityByCode("exit");

	exit0->setFunc(
	[=]()
	{
		printf("Here change will happen %s!\n", exit0->getNext().c_str());
		// setLevel(exit0->getNext());
	});
}

void StatePlaying::update(float deltaTime)
{
	m_currLevel->update(deltaTime);
}

void StatePlaying::leave()
{

}

void StatePlaying::setLevel(const std::string& level)
{
	// Living player = m_currLevel->getPlayer();

	// std::unique_ptr<Level> nextLevel(new Level());
	// nextLevel->init(level, player);

	// m_currLevel.reset(nullptr);
	// m_currLevel = std::move(nextLevel);
}