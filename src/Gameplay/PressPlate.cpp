#include "PressPlate.hpp"
#include "Door.hpp"
#include "SpikeTrap.hpp"
#include "../Collision/CollisionHandler.hpp"

PressPlate::PressPlate()
{
	m_type = EntityType::PressPlate;

	m_sprite = SpritePtr_t(new Sprite());
	m_sprite->loadFromFile("press_plate.png");
	m_sprite->setOrigin({0,0});
	m_sprite->setRect({0,0,32,32});

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,32,32);
	m_box->type = CollisionType::TriggerVolume;
	m_box->reactMaterial = CollMaterial::Living;
	m_box->callback = [this]()
	{
		activate();
	};

	CollisionHandler::Get().addBody(m_box);
}

void PressPlate::update(float deltaTime)
{
	if (m_timer.getElapsedTime().asSeconds() >= 5 and m_active)
	{
		deactivate();
	}

	m_sprite->setPosition({m_box->rect.x, m_box->rect.y});
	m_sprite->draw();
}

void PressPlate::whom(const std::vector<Entity*>& entity)
{
	m_whom = entity;
	printf("shit = %d\n", m_whom.size());
}

void PressPlate::activate()
{
	m_active = true;
	m_timer.restart();

	for (std::size_t i = 0; i < m_whom.size(); i++)
	{
		switch (m_whom[i]->getType())
		{
			case EntityType::Door:
			{
				auto door = static_cast<Door*>(m_whom[i]);
				door->open();
			}
			break;
			case EntityType::SpikeTrap:
			{
				auto trap = static_cast<SpikeTrap*>(m_whom[i]);
				trap->disable();
			}
			break;
			default:break;
		}
	}

	m_sprite->setRect({32,0,32,32});
}

void PressPlate::deactivate()
{
	m_active = false;

	for (std::size_t i = 0; i < m_whom.size(); i++)
	{
		switch (m_whom[i]->getType())
		{
			case EntityType::Door:
			{
				// auto door = static_cast<Door*>(m_whom);
				// door->open();
			}
			break;
			case EntityType::SpikeTrap:
			{
				auto trap = static_cast<SpikeTrap*>(m_whom[i]);
				trap->enable();
			}
			break;
			default:break;
		}
	}

	m_sprite->setRect({0,0,32,32});
}
