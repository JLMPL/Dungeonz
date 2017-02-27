#include "PressPlate.hpp"
#include "Door.hpp"
#include "../Collision/CollisionHandler.hpp"

PressPlate::PressPlate()
{
	m_type = EntityType::PRESS_PLATE;

	m_sprite = SpritePtr_t(new Sprite());
	m_sprite->loadFromFile("press_plate.png");
	m_sprite->setOrigin({0,0});
	m_sprite->setRect({0,0,32,32});

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,32,32);
	m_box->type = CollisionType::TRIGGER_VOLUME;
	m_box->reactMaterial = CollMaterial::LIVING;
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

void PressPlate::whom(Entity* entity)
{
	m_whom = entity;
}

void PressPlate::activate()
{
	m_active = true;
	m_timer.restart();

	switch(m_whom->getType())
	{
		case EntityType::DOOR:
		{
			auto door = static_cast<Door*>(m_whom);
			door->open();
		}
		break;
		default:break;
	}

	m_sprite->setRect({32,0,32,32});
}

void PressPlate::deactivate()
{
	m_active = false;
	m_sprite->setRect({0,0,32,32});
}
