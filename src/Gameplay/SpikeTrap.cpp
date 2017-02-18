#include "SpikeTrap.hpp"
#include "../Render/AnimatedSprite.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Resource/AnimationCache.hpp"

SpikeTrap::SpikeTrap()
{
	m_type = EntityType::SPIKE_TRAP;

	m_sprite = SpritePtr_t(new AnimatedSprite());
	m_sprite->loadFromFile("data/spike_trap_idle.ani");
	m_sprite->setOrigin({16,16});
	m_sprite->setRect({0,0,32,32});

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,32,32);
	m_box->type = CollisionType::TRIGGER_VOLUME;
	m_box->material = CollMaterial::TRAP;
	m_box->reactMaterial = CollMaterial::LIVING;
	m_box->callback = [this]()
	{
		this->activate();
	};

	CollisionHandler::Get().addBody(m_box);
}

void SpikeTrap::update(float deltaTime)
{
	if(m_enabled)
	{
		m_timer += 1000 * deltaTime;

		if(m_timer >= 750)
		{
			deactivate();
		}
	}

	m_sprite->setPosition({m_box->rect.x + m_box->rect.w/2, m_box->rect.y + m_box->rect.h/2});
	m_sprite->update(deltaTime);
}

void SpikeTrap::activate()
{
	if(!m_active and m_enabled)
	{
		m_active = true;
		m_timer = 0;
		m_sprite->setAnimation(AnimationCache::Get().getAnimation("data/spike_trap_stab.ani"));
	}
}

void SpikeTrap::deactivate()
{
	if(m_active)
	{
		m_sprite->setAnimation(AnimationCache::Get().getAnimation("data/spike_trap_hide.ani"),
		[this]()
		{
			m_active = false;
		});
	}
}

void SpikeTrap::enable()
{
	m_enabled = true;
	m_box->enabled = true;
}

void SpikeTrap::disable()
{
	m_enabled = false;
	m_box->enabled = false;
}
