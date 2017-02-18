#include "AiMob.hpp"
#include "../Gameplay/Living.hpp"
#include "../Gameplay/Level.hpp"
#include "../Resource/AnimationCache.hpp"

void AIMob::setup()
{
	m_state = MobState::IDLE;
	m_target->setDirection(Direction::DOWN);
}

void AIMob::focus()
{
	m_focus = nullptr;
	auto ents = m_target->getLevel()->getEntitiesInRange(m_target->getPosition(), 100);

	for (auto i = ents.begin(); i != ents.end();)
	{
		if((*i)->getType() != EntityType::LIVING)
			i = ents.erase(i);
		else 
			i++;
	}

	if (ents.size() > 0)
	{
		if (ents.size() > 1)
		std::sort(begin(ents), end(ents),
		[&](Entity* a, Entity* b)
		{
			float dist_a = length(a->getPosition() - m_target->getPosition());
			float dist_b = length(b->getPosition() - m_target->getPosition());

			return dist_a < dist_b;
		});

		m_focus = ents[0];
	}
}

void AIMob::update(float deltaTime)
{
	focus();
	
	switch(m_state)
	{
		case MobState::IDLE:
		{
			if(m_target->getAttribute(Attribute::HP) > 0)
			{
				if(m_focus)
				{
					if (distance(m_target->getPosition(), m_focus->getPosition()) < 28)
					{
						m_state = MobState::ATTACK;
					}
					else 
						m_state = MobState::MOVE;
				}
			}
			else
				m_state = MobState::DEAD;
			m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_idle.ani"));
		}
		break;
		case MobState::MOVE:
		{
			if(m_focus)
			{
				m_direction = m_focus->getPosition() - m_target->getPosition();
				m_direction = normalize(m_direction);

				m_target->setDirection(Direction::deduceDirection(m_direction));
				m_target->move(m_direction * m_speed * deltaTime);
				m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_walk.ani"));

				if(distance(m_target->getPosition(), m_focus->getPosition()) < 28)
				{
					m_state = MobState::IDLE;
				}
			}
			else
				m_state = MobState::IDLE;
		}
		break;
		case MobState::ATTACK:
		{
			if(m_timer.getElapsedTime().asMilliseconds() > 1000)
			{
				auto enemy = static_cast<Living*>(m_focus);
				enemy->damage(m_target->getAttribute(Attribute::DAMAGE));
				enemy->push(m_target->getDirection(), 5, 0.1);
				m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_attack.ani"),
				[&]()
				{
					m_state = MobState::IDLE;
					m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_idle.ani"));
				});
				m_timer.restart();
			}
			if(m_target->getAttribute(Attribute::HP) <= 0)
				m_state = MobState::DEAD;
		}
		break;
		case MobState::DEAD:
		{
			m_target->setDirection(Direction::UP);
			m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_dead.ani"));
		}
		break;
	}
}
