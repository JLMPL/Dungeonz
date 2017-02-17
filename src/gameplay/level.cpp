#include "level.hpp"
#include "living.hpp"
#include "../ai/ai_player.hpp"
#include "../ai/ai_mob.hpp"
#include "../collision/collision_handler.hpp"
#include "../gui/gui.hpp"
#include "../render/indication_handler.hpp"

void Level::init()
{
	map.setLevel(this);
	map.loadFromFile("data/map_test.tmx");
}

Entity* Level::addEntity(EntityPtr_t entity)
{
	m_Entities.push_back(std::move(entity));
	m_Entities.back()->setLevel(this);
	m_Entities.back()->setId(m_lastEntityId);
	m_lastEntityId++;
	return m_Entities.back().get();
}

ItemPtr_t Level::addItem(ItemPtr_t item)
{
	m_Items.push_back(item);
	return m_Items.back();
}

void Level::addBigParticle(const std::string& path, const vec2i& pos, float life)
{
	m_BigParticles.push_back(BigParticle());
	m_BigParticles.back().init(path, life);
	m_BigParticles.back().setPosition(pos);
}

void Level::update(float deltaTime)
{
	for(auto& i : m_Entities)
		i->update(deltaTime);

	for(auto i = m_BigParticles.begin(); i != m_BigParticles.end();)
	{
		if((*i).isDead())
			i = m_BigParticles.erase(i);
		else
			i++;
	}

	for(auto& i : m_BigParticles)
	{
		i.update(deltaTime);
	}

	map.update();
	CollisionHandler::Get().update(deltaTime);

	auto camera_pos = GUI::Get().getTarget()->getPosition().geti();
	Renderer::Get().setCameraPos(camera_pos);

	IndicationHandler::Get().update(deltaTime);
	GUI::Get().update();
}

std::vector<Entity*> Level::getEntitiesInRange(const vec2f& pos, float range)
{
	std::vector<Entity*> ents;

	for(int i = 0; i < m_Entities.size(); i++)
	{
		if(m_Entities[i]->getPosition() != pos)
		{
			vec2f die = pos - m_Entities[i]->getPosition();

			if(length(die) <= range)
			{
				ents.push_back(m_Entities[i].get());
			}
		}
	}

	return ents;
}

Entity* Level::getEntityByCode(std::string code)
{
	for(int i = 0; i < m_Entities.size(); i++)
	{
		if(m_Entities[i]->getCode() == code)
		{
			return m_Entities[i].get();
		}
	}
	return nullptr;
}

std::vector<Entity*> Level::getEntitiesByCode(std::string code)
{
	std::vector<Entity*> ents;

	for(int i = 0; i < m_Entities.size(); i++)
	{
		if(m_Entities[i]->getCode() == code)
		{
			ents.push_back(m_Entities[i].get());
		}
	}
	return ents;
}