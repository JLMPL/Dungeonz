#include "CollisionHandler.hpp"
#include "CollisionAlgorithm.hpp"
#include <SFML/Window/Keyboard.hpp>

constexpr float g_Push = 0.02;

void CollisionHandler::init()
{
}

void CollisionHandler::update(float deltaTime)
{
	clean();

	if(m_bodies.size() > 1)
	for(int i = 0; i < m_bodies.size() - 1; i++)
	{
		for(int j = i + 1; j < m_bodies.size(); j++)
		{
			auto& a = *m_bodies[i];
			auto& b = *m_bodies[j];

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
							a.rect.x += move.x * 0.5 + g_Push;
							b.rect.x -= move.x * 0.5 + g_Push;
						}
						else
						{
							a.rect.y += move.y * 0.5 + g_Push;
							b.rect.y -= move.y * 0.5 + g_Push;
						}
						react(m_bodies[i], m_bodies[j]);
					}
				}
				else if(a.type == CollisionType::DYNAMIC and b.type == CollisionType::STATIC)
				{
					if(Collision::AABBOverlap(a.rect, b.rect))
					{
						vec2f move;
						Collision::AABBResponse(a.rect, b.rect, move);
						(move.y == 0) ? a.rect.x += move.x + g_Push : a.rect.y += move.y + g_Push;
						react(m_bodies[i], m_bodies[j]);
					}
				}
				else if(a.type == CollisionType::STATIC and b.type == CollisionType::DYNAMIC)
				{
					if(Collision::AABBOverlap(a.rect, b.rect))
					{
						vec2f move;
						Collision::AABBResponse(b.rect, a.rect, move);

						(move.y == 0) ? b.rect.x += move.x + g_Push : b.rect.y += move.y + g_Push;
						react(m_bodies[i], m_bodies[j]);
					}
				}
				else if(a.type == CollisionType::TRIGGER_VOLUME and b.type == CollisionType::DYNAMIC)
				{
					if(Collision::AABBOverlap(a.rect, b.rect))
					{
						react(m_bodies[i], m_bodies[j]);
					}
				}
				else if(b.type == CollisionType::TRIGGER_VOLUME and a.type == CollisionType::DYNAMIC)
				{
					if(Collision::AABBOverlap(a.rect, b.rect))
					{
						react(m_bodies[i], m_bodies[j]);
					}
				}
			}
		}
	}

	if(false)
	for(int i = 0; i < m_bodies.size(); i++)
	{
		m_bodies[i]->draw();
	}
}

void CollisionHandler::addBody(BoxPtr_t box)
{
	m_bodies.push_back(box);
}

void CollisionHandler::react(BoxPtr_t a, BoxPtr_t b)
{
	if(b->material == a->reactMaterial)
	{	
		if(a->callback)
			a->callback();
	}

	if(a->material == b->reactMaterial)
	{	
		if(b->callback)
			b->callback();
	}
}

void CollisionHandler::clean()
{
	for(auto i = m_bodies.begin(); i != m_bodies.end();)
	{
		auto& the = *i;
		if(the.use_count() == 1)
		{
			the.reset();
			i = m_bodies.erase(i);
		}
		else i++;
	}
}
