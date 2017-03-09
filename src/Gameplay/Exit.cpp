#include "Exit.hpp"

Exit::Exit()
{
	m_type = EntityType::Exit;

	m_sprite = SpritePtr_t(new Sprite());
	m_sprite->loadFromFile("exit_door.png");
	m_sprite->setOrigin({16,32});

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,1,1);
	m_box->type = CollisionType::Static;
	m_box->enabled = false;

	// CollisionHandler::Get().addBody(m_box);
}

void Exit::update(float deltaTime)
{
	m_sprite->setPosition({m_box->rect.x, m_box->rect.y});
	m_sprite->draw();
}

void Exit::setNext(const std::string& next)
{
	m_next = next;
}

const std::string& Exit::getNext() const
{
	return m_next;
}