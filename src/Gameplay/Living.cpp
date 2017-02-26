#include "Living.hpp"
#include "Level.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Ai/AiPtr.hpp"
#include "../Render/AnimatedSprite.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Gui/Gui.hpp"

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

	m_sprite->loadFromFile(m_profile.apperance + "_walk.ani");
	m_code = m_profile.code;

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,14,6);
	m_box->type = CollisionType::DYNAMIC;
	m_box->material = CollMaterial::LIVING;
	m_box->reactMaterial = CollMaterial::TRAP;
	m_box->callback = [this]()
	{
		if(this->m_trapTimer > 750 + 60 + 160)
		{
			this->damage(2);
			this->m_trapTimer = 0;
		}
	};

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


	for(int i = 0; i < Spell::NUM_SPELLS; i++)
	{
		m_spells[i] = false;
	}
}

void Living::update(float deltaTime)
{
	m_trapTimer += 1000 * deltaTime;

	m_ai->update(deltaTime);

	m_shadow.setPosition({m_box->rect.x + m_box->rect.w /2, m_box->rect.y + m_box->rect.h /2});
	Renderer::Get().submitBackground(&m_shadow);

	m_sprite->setPosition({m_box->rect.x + m_box->rect.w /2, m_box->rect.y + m_box->rect.h /2});
	m_sprite->update(deltaTime);

	if (m_attributes[Attribute::XP] >= m_attributes[Attribute::TO_NEXT])
	{
		m_attributes[Attribute::XP] -= m_attributes[Attribute::TO_NEXT];
		m_attributes[Attribute::LEVEL]++;
		m_attributes[Attribute::TO_NEXT] *= 1.5;
		m_attributes[Attribute::HEALTH] *= 1.2;
		m_attributes[Attribute::MAGICKA] *= 1.2;

		GUI::Get().addLabel("Level Up!");
	}

	if (m_push)
	{
		m_pushTimer += deltaTime * (1/m_pushDuration);

		auto pushVec = lerp(m_pushStart, m_pushEnd, m_pushTimer);
		m_box->rect.x = pushVec.x;
		m_box->rect.y = pushVec.y;

		if (m_pushTimer >= 1)
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

		m_pushStart = vec2f(m_box->rect.x, m_box->rect.y);

		switch(m_pushDir)
		{
			case Direction::UP:
				m_pushEnd = m_pushStart + vec2f(0, -dist);
			break;
			case Direction::DOWN:
				m_pushEnd = m_pushStart + vec2f(0, dist);
			break;
			case Direction::LEFT:
				m_pushEnd = m_pushStart + vec2f(-dist, 0);
			break;
			case Direction::RIGHT:
				m_pushEnd = m_pushStart + vec2f(dist, 0);
			break;
		}
	}
}

void Living::damage(int damage)
{
	int& currHp  = m_attributes[Attribute::HP];
	int& defense = m_attributes[Attribute::DEFENSE];

	currHp -= damage;

	if(currHp < 0)
		currHp = 0;

	m_level->addBigParticle("blood_splash.ani", vec2i(m_box->rect.x + m_box->rect.w/2, m_box->rect.y + m_box->rect.h/2 + 1), 0.150);
}

void Living::setDamage(int value)
{
	m_attributes[Attribute::DAMAGE] = value;
}

void Living::restoreBasicDamage()
{
	m_attributes[Attribute::DAMAGE] = m_profile.damage;
}

void Living::setDefense(int value)
{
	m_attributes[Attribute::DEFENSE] = value;
}

void Living::restoreBasicDefense()
{
	m_attributes[Attribute::DEFENSE] = m_profile.defense;
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

void Living::drainMana(int mana)
{
	int& magicka = m_attributes[Attribute::MP];
	magicka -= mana;

	if(magicka < 0)
		magicka = 0;
}

void Living::setEquippedItem(int where, Item* item)
{
	m_equipped[where] = item;
}

bool Living::isEquipped(int where, Item* item)
{
	return m_equipped[where] == item;
}

void Living::setReadySpell(int spell)
{
	if(m_spells[spell])
		m_readySpell = spell;
}

void Living::learnSpell(int spell)
{
	m_spells[spell] = true;
	m_readySpell = spell;

	switch(spell)
	{
		case Spell::FIREBALL:
			GUI::Get().addLabel("Learned spell \"Fireball\"!");
		break;
		case Spell::FROSTBITE:
			GUI::Get().addLabel("Learned spell \"Frostbite\"!");
		break;
	}
}

bool Living::knowsSpell(int spell)
{
	return m_spells[spell];
}

int Living::getReadySpell()
{
	return m_readySpell;
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

bool Living::isDead() const
{
	return m_attributes[Attribute::HP] <= 0;
}