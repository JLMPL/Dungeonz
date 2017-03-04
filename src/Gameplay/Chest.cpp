#include "Chest.hpp"
#include "../Collision/CollisionHandler.hpp"

Chest::Chest()
{
	m_type = EntityType::CHEST;
	m_sprite = SpritePtr_t(new Sprite());
	m_sprite->loadFromFile("chest.png");
	m_sprite->setOrigin({16,32});

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,26,16);
	m_box->type = CollisionType::STATIC;

	CollisionHandler::Get().addBody(m_box);
}

void Chest::update(float deltaTime)
{
	m_sprite->setPosition({m_box->rect.x + m_box->rect.w/2, m_box->rect.y + m_box->rect.h});
	m_sprite->draw();
}

Inventory& Chest::accessInv()
{
	return m_inv;
}