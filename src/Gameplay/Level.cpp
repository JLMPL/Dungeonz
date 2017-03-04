#include "Level.hpp"
#include "Living.hpp"
#include "../Ai/AiPlayer.hpp"
#include "../Ai/AiMob.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Gui/Gui.hpp"
#include "../Render/IndicationHandler.hpp"

void Level::init()
{
	map.setLevel(this);
	map.loadFromFile("map_test.tmx");
}

Entity* Level::addEntity(EntityPtr_t entity)
{
	m_entities.push_back(std::move(entity));
	m_entities.back()->setLevel(this);
	m_entities.back()->setId(m_lastEntityId);
	m_lastEntityId++;
	return m_entities.back().get();
}

ItemPtr_t Level::addItem(ItemPtr_t item)
{
	m_items.push_back(item);
	return m_items.back();
}

Missile* Level::addMissile(std::shared_ptr<Missile> missile)
{
	m_missiles.push_back(missile);
	m_missiles.back()->setLevel(this);
	m_missiles.back()->setId(m_lastEntityId);
	m_lastEntityId++;
	return m_missiles.back().get();
}

void Level::addBigParticle(const std::string& path, const vec2i& pos, float life)
{
	m_bigParticles.push_back(BigParticle());
	m_bigParticles.back().init(path, life);
	m_bigParticles.back().setPosition(pos);
}

void Level::update(float deltaTime)
{
	for (auto i = m_entities.begin(); i != m_entities.end();)
	{
		if ((*i)->isDestroyed())
			i = m_entities.erase(i);
		else
			i++;
	}

	for (auto i = m_missiles.begin(); i != m_missiles.end();)
	{
		if ((*i)->isDestroyed())
			i = m_missiles.erase(i);
		else 
			i++;
	}

	for (auto& i : m_entities)
		i->update(deltaTime);

	for (auto& i : m_missiles)
		i->update(deltaTime);

	for (auto i = m_bigParticles.begin(); i != m_bigParticles.end();)
	{
		if ((*i).isDead())
			i = m_bigParticles.erase(i);
		else
			i++;
	}

	for (auto& i : m_bigParticles)
	{
		i.update(deltaTime);
	}

	map.update();
	CollisionHandler::Get().update(deltaTime);

	auto camera_pos = GUI::Get().getTarget()->getPosition().geti();
	Renderer::Get().setCameraPos(camera_pos);

	IndicationHandler::Get().update(deltaTime);
	GUI::Get().update(deltaTime);
}

std::vector<Entity*> Level::getEntitiesInRange(const vec2f& pos, float range)
{
	std::vector<Entity*> ents;

	for (int i = 0; i < m_entities.size(); i++)
	{
		if (m_entities[i]->getPosition() != pos)
		{
			vec2f die = pos - m_entities[i]->getPosition();

			if (length(die) <= range)
			{
				ents.push_back(m_entities[i].get());
			}
		}
	}

	return ents;
}

Entity* Level::getEntityByCode(std::string code)
{
	for (int i = 0; i < m_entities.size(); i++)
	{
		if (m_entities[i]->getCode() == code)
		{
			return m_entities[i].get();
		}
	}
	return nullptr;
}

std::vector<Entity*> Level::getEntitiesByCode(std::string code)
{
	std::vector<Entity*> ents;

	for (int i = 0; i < m_entities.size(); i++)
	{
		if (m_entities[i]->getCode() == code)
		{
			ents.push_back(m_entities[i].get());
		}
	}
	return ents;
}