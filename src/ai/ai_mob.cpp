#include "ai_mob.hpp"
#include "../gameplay/living.hpp"
#include "../gameplay/level.hpp"
#include "../resource/animation_cache.hpp"

void AIMob::setup()
{
	m_target->setDirection(Direction::DOWN);
}

void AIMob::update(float deltaTime)
{
	m_focus = nullptr;
	auto ents = m_target->getLevel()->getEntitiesInRange(m_target->getPosition(), 100);

	for(auto i = ents.begin(); i != ents.end();)
	{
		if((*i)->getType() != EntityType::LIVING)
			i = ents.erase(i);
		else 
			i++;
	}
	
	if(m_target->getAttribute(Attribute::HP) > 0)
	{
		if(ents.size() > 0)
		{
			if(ents.size() > 1)
			std::sort(begin(ents), end(ents),
			[&](Entity* a, Entity* b)
			{
				float dist_a = length(a->getPosition() - m_target->getPosition());
				float dist_b = length(b->getPosition() - m_target->getPosition());

				return dist_a < dist_b;
			});

			m_focus = ents[0];
		}

		if(m_focus)
		{
			switch(m_focus->getType())
			{
				case EntityType::LIVING:
				{
					auto living = static_cast<Living*>(m_focus);
					if(living->getAttribute(Attribute::HP) >= 0)
					{
						m_direction = m_focus->getPosition() - m_target->getPosition();
						m_target->setDirection(Direction::deduceDirection(normalize(m_direction)));
						auto enemy = (Living*)(m_focus);
						
						if(!m_target->isBusy())
						{
							if(length(m_direction) > 28)
							{
								m_direction = normalize(m_direction);
								m_target->move(m_direction * m_speed * deltaTime);
								m_target->setAnimation(AnimationCache::Get().getAnimation("data/" + m_target->getProfile().apperance + "_walk.ani"));
							}
							else
							{
								if(m_timer.getElapsedTime().asMilliseconds() > 300)
								{
									enemy->damage(m_target->getAttribute(Attribute::DAMAGE));
									enemy->push(m_target->getDirection(), 5, 0.075);
									m_target->setBusy(true);

									Living* shit = m_target;

									m_target->setAnimation(AnimationCache::Get().getAnimation("data/" + m_target->getProfile().apperance + "_attack.ani"),
									[=]()
									{
										shit->setBusy(false);
										printf("Is busy now? %d\n", shit->isBusy());
									});
									m_timer.restart();
								}
							}
						}
						else {}
					}
				}
				break;
				default:
				{
					m_target->setAnimation(AnimationCache::Get().getAnimation("data/" + m_target->getProfile().apperance + "_idle.ani"));
				}
				break;
			}
		}
		else
		{
			m_target->setAnimation(AnimationCache::Get().getAnimation("data/" + m_target->getProfile().apperance + "_idle.ani"));
		}
	}
	else
	{
		m_target->setDirection(Direction::UP);
		m_target->setAnimation(AnimationCache::Get().getAnimation("data/" + m_target->getProfile().apperance + "_dead.ani"));
	}
}
