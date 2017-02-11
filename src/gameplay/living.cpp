#include "living.hpp"
#include "../resource/texture_cache.hpp"
#include "../ai/ai_ptr.hpp"
#include "../render/animated_sprite.hpp"
#include "../collision/collision_handler.hpp"

Living::Living()
{
	m_type = EntityType::LIVING;
	m_sprite = SpritePtr_t(new AnimatedSprite());
}

Living::Living(const LivingProfile& profile)
{
	init(profile);
}

void Living::init(const LivingProfile& profile)
{
	m_profile = profile;

	m_sprite->loadFromFile("data/" + m_profile.apperance + "_walk.ani");
	m_code = m_profile.code;

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,14,6);
	m_box->type = CollisionType::DYNAMIC;

	m_shadow = sf::CircleShape(7);
	m_shadow.setFillColor({0,0,0,64});
	m_shadow.setOrigin({7,7});
	m_shadow.setScale({1,0.5});

	CollisionHandler::Get().addBody(m_box);

	m_attributes[Attribute::HP]      = m_profile.health;
	m_attributes[Attribute::HEALTH]  = m_profile.health;
	m_attributes[Attribute::MP]      = m_profile.magicka;
	m_attributes[Attribute::MAGICKA] = m_profile.magicka;
	m_attributes[Attribute::DAMAGE]  = m_profile.damage;
	m_attributes[Attribute::DEFENSE] = m_profile.defense;
	m_attributes[Attribute::LEVEL]   = m_profile.level;
	m_attributes[Attribute::XP]      = m_profile.xp;
	m_attributes[Attribute::TO_NEXT] = 250;
}

void Living::update(float deltaTime)
{
	m_ai->update(deltaTime);

	m_shadow.setPosition({m_box->rect.x + m_box->rect.w /2, m_box->rect.y + m_box->rect.h /2});
	Renderer::Get().submit(RenderData(&m_shadow, m_sprite->getPosition().y-0.00001), RenderAttribute::SORTED);

	m_sprite->setPosition({m_box->rect.x + m_box->rect.w /2, m_box->rect.y + m_box->rect.h /2});
	m_sprite->update(deltaTime);

	if(m_attributes[Attribute::XP] >= m_attributes[Attribute::TO_NEXT])
	{
		m_attributes[Attribute::XP] -= m_attributes[Attribute::TO_NEXT];
		m_attributes[Attribute::LEVEL]++;
		m_attributes[Attribute::TO_NEXT] *= 1.5;
		m_attributes[Attribute::HEALTH] *= 1.2;
		m_attributes[Attribute::MAGICKA] *= 1.2;
	}

	if(m_push)
	{
		m_pushTimer += deltaTime * (1/m_pushDuration);

		if(m_pushDir == Direction::LEFT or m_pushDir == Direction::RIGHT)
			m_box->rect.x = lerp(m_startPush.x, m_endPush.x, m_pushTimer);
		else
			m_box->rect.y = lerp(m_startPush.y, m_endPush.y, m_pushTimer);

		if(m_pushTimer >= 1)
			m_push = false;
	}
}

void Living::push(Direction_t dir, float dist, float duration)
{
	if(!m_busy and !m_push)
	{
		m_push = true;
		m_pushDir = dir;
		m_pushTimer = 0;
		m_pushDuration = duration;

		m_startPush = vec2f();
		m_endPush = vec2f();

		switch(m_pushDir)
		{
			case Direction::UP:
			{
				m_startPush.y = m_box->rect.y;
				m_endPush.y = m_box->rect.y - dist;
				break;
			}
			case Direction::DOWN:
			{
				m_startPush.y = m_box->rect.y;
				m_endPush.y = m_box->rect.y + dist;
				break;
			}
			case Direction::LEFT:
			{
				m_startPush.x = m_box->rect.x;
				m_endPush.x = m_box->rect.x - dist;
				break;
			}
			case Direction::RIGHT:
			{
				m_startPush.x = m_box->rect.x;
				m_endPush.x = m_box->rect.x + dist;
				break;
			}
		}
	}
}

void Living::damage(int damage)
{
	int& currHp = m_attributes[Attribute::HP];
	currHp -= damage;
	if(currHp < 0) currHp = 0;
}

void Living::equipWeapon(const std::string& code)
{
	// m_equipped[Equip::WEAPON] = code;
}

void Living::equipArmor(const std::string& code)
{
	// m_equipped[Equip::ARMOR] = code;
}

void Living::setDamage(int high)
{
	m_attributes[Attribute::DAMAGE] = high;
}

void Living::restoreBasicDamage()
{
	m_attributes[Attribute::DAMAGE] = 5;
}

void Living::restoreHealth(int heal)
{
	m_attributes[Attribute::HP] += heal;
}

void Living::restoreFullHealth()
{
	m_attributes[Attribute::HP] = m_attributes[Attribute::HEALTH];
}

void Living::restoreMana(int mana)
{
	m_attributes[Attribute::MP] += mana;
}

void Living::restoreFullMana()
{
	m_attributes[Attribute::MP] = m_attributes[Attribute::MAGICKA];
}

void Living::setEquippedItem(int where, Item* item)
{
	m_equipped[where] = item;
}

bool Living::isEquipped(int where, Item* item)
{
	if(m_equipped[where] == item)
		return true;
	else 
		return false;
}

void Living::addXp(int xp)
{
	m_attributes[Attribute::XP] += xp;
}

int Living::getXp()
{
	return m_profile.xp;
}

void Living::setAI(AIPtr_t ai)
{
	m_ai = std::move(ai);
	m_ai->init(this);
	m_ai->setup();
}

void Living::setDirection(Direction_t facing)
{
	m_facing = facing;
	if(m_sprite)
		m_sprite->setDirection(m_facing);
}

void Living::setAnimation(AnimPtr_t anim, std::function<void ()> call)
{
	if(m_sprite)
		m_sprite->setAnimation(anim, call);
}

void Living::setBusy(bool busy)
{
	m_busy = busy;
}

const LivingProfile& Living::getProfile() const
{
	return m_profile;
}

Direction_t Living::getDirection() const
{
	return m_facing;
}

int Living::getAttribute(Attribute att) const
{
	return m_attributes[att];
}

bool Living::isAnimFinished() const
{
	return static_cast<AnimatedSprite*>(m_sprite.get())->isFinished();
}

bool Living::isBusy() const
{
	return m_busy;
}

Inventory& Living::accessInv()
{
	return m_inv;
}