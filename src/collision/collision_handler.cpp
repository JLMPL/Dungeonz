#include "collision_handler.hpp"
#include "../message/message_bus.hpp"
#include "collision_algorithm.hpp"
#include <SFML/Window/Keyboard.hpp>

constexpr float gPush = 0.02;

void CollisionHandler::init()
{
}

void CollisionHandler::update(float deltaTime)
{
	clean();

	if(m_Bodies.size() > 1)
	for(int i = 0; i < m_Bodies.size() - 1; i++)
	{
		for(int j = i + 1; j < m_Bodies.size(); j++)
		{
			auto& a = *m_Bodies[i];
			auto& b = *m_Bodies[j];

			if(a.enabled and b.enabled)
			{
				if(a.type == CollisionType::DYNAMIC and b.type == CollisionType::DYNAMIC)
				{
					if(Collision::AABBOverlap(a.rect, b.rect))
					{
						vec2f move;
						Collision::AABBResponse(a.rect, b.rect, move);
						if(move.y == 0)
						{
							a.rect.x += move.x * 0.5 + gPush;
							b.rect.x -= move.x * 0.5 + gPush;
						}
						else
						{
							a.rect.y += move.y * 0.5 + gPush;
							b.rect.y -= move.y * 0.5 + gPush;
						}
					}
				}
				else if(a.type == CollisionType::DYNAMIC and b.type == CollisionType::STATIC)
				{
					if(Collision::AABBOverlap(a.rect, b.rect))
					{
						vec2f move;
						Collision::AABBResponse(a.rect, b.rect, move);
						(move.y == 0) ? a.rect.x += move.x + gPush : a.rect.y += move.y + gPush;
					}
				}
				else if(a.type == CollisionType::STATIC and b.type == CollisionType::DYNAMIC)
				{
					if(Collision::AABBOverlap(a.rect, b.rect))
					{
						vec2f move;
						Collision::AABBResponse(b.rect, a.rect, move);

						(move.y == 0) ? b.rect.x += move.x + gPush : b.rect.y += move.y + gPush;
					}
				}
			}
		}
	}

	if(false)
	for(int i = 0; i < m_Bodies.size(); i++)
	{
		m_Bodies[i]->draw();
	}
}

void CollisionHandler::addBody(BoxPtr_t box)
{
	m_Bodies.push_back(box);
}

void CollisionHandler::clean()
{
	for(auto i = m_Bodies.begin(); i != m_Bodies.end();)
	{
		auto& the = *i;
		if(the.use_count() == 1)
		{
			the.reset();
			i = m_Bodies.erase(i);
		}
		else i++;
	}
}

void CollisionHandler::sendMessage(int message, MessagePtr_t value)
{
}
