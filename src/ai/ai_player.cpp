#include "ai_player.hpp"
#include "../core/dice.hpp"
#include "../gameplay/living.hpp"
#include "../gameplay/level.hpp"
#include "../gameplay/chest.hpp"
#include "../gameplay/door.hpp"
#include "../gameplay/lever.hpp"
#include "../gui/gui.hpp"
#include "../input/input_handler.hpp"
#include "../render/indication_handler.hpp"
#include "../resource/animation_cache.hpp"

void AIPlayer::setup()
{
	m_state = PlayerState::MOVING;
}

void AIPlayer::update(float deltaTime)
{
	if(!m_target->isBusy())
	{
		focus();

		switch(m_state)
		{
			case PlayerState::MOVING:
			{
				movingState(deltaTime);
				break;
			}
			case PlayerState::IDLE:
			{
				idleState(deltaTime);
				break;
			}
			case PlayerState::ATTACK:
			{
				if(m_timer.getElapsedTime().asMilliseconds() > 300)
				{
					m_target->setAnimation(AnimationCache::Get().getAnimation("data/player_attack.ani"),
					[&]()
					{
						m_state = PlayerState::MOVING;
					});

					if(m_focus)
					{
						float dist = length(m_focus->getPosition() - m_target->getPosition());

						if(dist <= 32)
						{
							switch(m_focus->getType())
							{
								case EntityType::LIVING:
								{
									auto living = static_cast<Living*>(m_focus);

									if(living->getAttribute(Attribute::HP) > 0)
									{
										int damage = m_target->getAttribute(Attribute::DAMAGE);
										living->damage(damage);
										living->push(m_target->getDirection(), 5, 0.075);

										IndicationHandler::Get().addIndication("-" + std::to_string(damage), sf::Color(0,255,0), m_focus->getPosition() + vec2f(0,-50));

										if(living->getAttribute(Attribute::HP) <= 0)
										{
											m_target->addXp(living->getXp());
											IndicationHandler::Get().addIndication("+" + std::to_string(living->getXp()) + "xp", sf::Color(0,128,255), m_target->getPosition() + vec2f(0,-35));
										}
									}
									break;
								}
							}
						}
					}
					m_timer.restart();
				}
				break;
			}
			case PlayerState::PICKING:
			{
				pickingState(deltaTime);
				break;
			}
		}
	}
	else
		m_target->setAnimation(AnimationCache::Get().getAnimation("data/player_idle.ani"));
}

void AIPlayer::movingState(float deltaTime)
{
	if(InputHandler::Get().isUp())
	{
		m_target->move({0, -deltaTime * m_speed});
		m_target->setDirection(Direction::UP);
	}
	else if(InputHandler::Get().isDown())
	{
		m_target->move({0, deltaTime * m_speed});
		m_target->setDirection(Direction::DOWN);
	}
	if(InputHandler::Get().isLeft())
	{
		m_target->move({-deltaTime * m_speed, 0});
		m_target->setDirection(Direction::LEFT);
	}
	else if(InputHandler::Get().isRight())
	{
		m_target->move({deltaTime * m_speed, 0});
		m_target->setDirection(Direction::RIGHT);
	}

	m_target->setAnimation(AnimationCache::Get().getAnimation("data/player_walk.ani"));

	if(!InputHandler::Get().isAnyKeyPressed())
		m_state = PlayerState::IDLE;
	else if(InputHandler::Get().isAttack())
	{
		m_state = PlayerState::ATTACK;
	}
	else if(InputHandler::Get().isAction())
	{
		m_state = PlayerState::PICKING;
	}
}

void AIPlayer::idleState(float deltaTime)
{
	m_target->setAnimation(AnimationCache::Get().getAnimation("data/player_idle.ani"));

	if(InputHandler::Get().isUp() or
	   InputHandler::Get().isDown() or
	   InputHandler::Get().isLeft() or
	   InputHandler::Get().isRight())
	{
		m_state = PlayerState::MOVING;
	}
	else if(InputHandler::Get().isAttack())
	{
		m_state = PlayerState::ATTACK;
	}
	else if(InputHandler::Get().isAction())
	{
		m_state = PlayerState::PICKING;
	}
}

void AIPlayer::attackState(float deltaTime)
{
	if(m_timer.getElapsedTime().asMilliseconds() > 300)
	{
		m_target->setAnimation(AnimationCache::Get().getAnimation("data/player_attack.ani"),
		[&]()
		{
			m_state = PlayerState::MOVING;
		});

		if(m_focus)
		{
			float dist = length(m_focus->getPosition() - m_target->getPosition());

			if(dist <= 32)
			{
				switch(m_focus->getType())
				{
					case EntityType::LIVING:
					{
						auto living = static_cast<Living*>(m_focus);

						if(living->getAttribute(Attribute::HP) > 0)
						{
							int damage = m_target->getAttribute(Attribute::DAMAGE);
							living->damage(damage);
							living->push(m_target->getDirection(), 5, 0.075);

							IndicationHandler::Get().addIndication("-" + std::to_string(damage), sf::Color(0,255,0), m_focus->getPosition() + vec2f(0,-50));

							if(living->getAttribute(Attribute::HP) <= 0)
							{
								m_target->addXp(living->getXp());
								IndicationHandler::Get().addIndication("+" + std::to_string(living->getXp()) + "xp", sf::Color(0,128,255), m_target->getPosition() + vec2f(0,-35));
							}
						}
						break;
					}
				}
			}
		}
		m_timer.restart();
	}
}

void AIPlayer::pickingState(float deltaTime)
{
	if(m_focus and m_timer.getElapsedTime().asMilliseconds() > 150)
	{
		float dist = length(m_focus->getPosition() - m_target->getPosition());

		if(dist <= 32)
		{
			switch(m_focus->getType())
			{
				case EntityType::LIVING:
				{
					auto living = static_cast<Living*>(m_focus);
					if (living->getAttribute(Attribute::HP) <= 0)
					{
						if (living->accessInv().getAmount() > 0)
							GUI::Get().goLoot(&living->accessInv(), living->getPosition().geti());
						else
							IndicationHandler::Get().addIndication("empty", sf::Color(255,255,0), living->getPosition() + vec2f(0,-50));
					}
					break;
				}
				case EntityType::CHEST:
				{
					auto chest = static_cast<Chest*>(m_focus);
					if(true/*chest->isOpen()*/)
					{
						if(chest->accessInv().getAmount() > 0)
							GUI::Get().goLoot(&chest->accessInv(), chest->getPosition().geti());
						else
							IndicationHandler::Get().addIndication("empty", sf::Color(255,255,0), chest->getPosition() + vec2f(0,-50));
					}
					break;
				}
				case EntityType::DOOR:
				{
					auto door = static_cast<Door*>(m_focus);
					door->tryOpening(&m_target->accessInv());
					break;
				}
				case EntityType::LEVER:
				{
					auto lever = static_cast<Lever*>(m_focus);
					lever->activate();
					break;
				}
			}
		}
		m_timer.restart();
	}
	m_state = PlayerState::MOVING;
}

void AIPlayer::focus()
{
	auto ents = m_target->getLevel()->getEntitiesInRange(m_target->getPosition(), 48);
	m_focus = nullptr;

	if(ents.size() > 0)
	{
		if(ents.size() > 1)
		{
			std::sort(begin(ents), end(ents),
			[&](Entity* a, Entity* b)
			{
				float dista = length(a->getPosition() - m_target->getPosition());
				float distb = length(b->getPosition() - m_target->getPosition());

				return dista < distb;
			});
		}

		m_focus = ents[0];

		switch(m_focus->getType())
		{
			case EntityType::LIVING:
			{
				auto focal = static_cast<Living*>(m_focus);
				std::string name = focal->getProfile().name;
				vec2i pos = vec2i(m_focus->getFakePos().x, m_focus->getFakePos().y - 40);
				GUI::Get().setFocusLabel(name, pos);
				GUI::Get().showFocusHealthbar(focal->getAttribute(Attribute::HP),
											  focal->getAttribute(Attribute::HEALTH),
											  pos);
				break;
			}
			case EntityType::CHEST:
			{
				vec2i pos = vec2i(m_focus->getFakePos().x, m_focus->getFakePos().y - 40);
				GUI::Get().setFocusLabel("Chest", pos);
				break;
			}
			case EntityType::DOOR:
			{
				vec2i pos = vec2i(m_focus->getFakePos().x, m_focus->getFakePos().y - 40);
				GUI::Get().setFocusLabel("Door", pos);
				break;
			}
			case EntityType::LEVER:
			{
				vec2i pos = vec2i(m_focus->getPosition().x, m_focus->getPosition().y - 40);
				GUI::Get().setFocusLabel("Lever", pos);
				break;
			}
		}
	}
}