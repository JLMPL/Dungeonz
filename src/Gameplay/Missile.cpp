#include "Missile.hpp"
#include "../Render/AnimatedSprite.hpp"
#include "../Collision/CollisionHandler.hpp"

Missile::Missile()
{
	m_sprite = SpritePtr_t(new AnimatedSprite());
	m_sprite->loadFromFile("fajerbol.ani");
	m_sprite->setOrigin({12,12});

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,8,8);
	m_box->type = CollisionType::TRIGGER_VOLUME;
	m_box->reactMaterial = CollMaterial::REGULAR | CollMaterial::LIVING;
	m_box->callback = [this]()
	{
		this->destroy();
		printf("Yesz!\n");
	};
	m_box->enabled = false;

	CollisionHandler::Get().addBody(m_box);
}

void Missile::init(vec2f origin, Direction_t dir, EntityType type)
{
	m_type = type;
	m_direction = dir;
	m_box->rect.x = origin.x;
	m_box->rect.y = origin.y;
}

void Missile::update(float deltaTime)
{
	if(m_warmup.getElapsedTime().asSeconds() > 0.2)
	{
		m_box->enabled = true;
	}

	switch(m_direction)
	{
		case Direction::UP:
		{
			m_velocity = vec2f(0,-1);
		}
		break;
		case Direction::DOWN:
		{
			m_velocity = vec2f(0,1);
		}
		break;
		case Direction::LEFT:
		{
			m_velocity = vec2f(-1,0);
		}
		break;
		case Direction::RIGHT:
		{
			m_velocity = vec2f(1,0);
		}
		break;
	}

	vec2f translation(m_velocity * m_speed * deltaTime);
	move(translation);

	m_sprite->setPosition(vec2i(m_box->rect.x + m_box->rect.w/2, m_box->rect.y - 12));
	m_sprite->update(deltaTime);
}

void Missile::blow()
{

}
