#ifndef LIVING_HPP
#define LIVING_HPP
#include "Entity.hpp"
#include "LivingProfile.hpp"
#include "Stats.hpp"
#include "Inventory.hpp"
#include "Spells.hpp"
#include "../Ai/AiPtr.hpp"
#include "../Core/Direction.hpp"
#include "../Resource/AnimationPtr.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <functional>

class Living : public Entity
{
	public:
		using Base = Entity;

		Living();
		Living   (const LivingProfile& profile);
		void init(const LivingProfile& profile);

		void update(float deltaTime) override final;

		void push(Direction_t dir, float dist, float duration);
		void damage(int damage);

		void setDamage(int value);
		void restoreBasicDamage();

		void setDefense(int value);
		void restoreBasicDefense();

		void restoreHealth(int heal);
		void restoreFullHealth();

		void restoreMana(int mana);
		void restoreFullMana();
		void drainMana(int mana);
		
		void setEquippedItem(int where, Item* item);
		bool isEquipped(int where, Item* item);

		void setReadySpell(int spell);
		void learnSpell(int spell);
		bool knowsSpell(int spell);
		int getReadySpell();

		void addXp(int xp);
		int  getXp();

		void setAI(AIPtr_t ai);
		void setDirection(Direction_t facing);
		void setAnimation(AnimPtr_t anim, std::function<void ()> call = [](){});
		void setBusy(bool busy);
		
		const LivingProfile& getProfile() const;
		Direction_t          getDirection() const;
		int 				 getAttribute(Attribute att) const;
		bool 				 isAnimFinished() const;
		bool 				 isBusy() const;
		Inventory& 			 accessInv();
		bool 				 isDead() const;

	private:
		LivingProfile m_profile;
		Direction_t   m_facing;
		AIPtr_t       m_ai = nullptr;
		bool          m_busy = false;

		sf::CircleShape m_shadow;

		bool        m_push = false;
		Direction_t m_pushDir;
		float		m_pushTimer;
		vec2f 		m_pushStart;
		vec2f 		m_pushEnd;
		float       m_pushDuration;

		float 		m_trapTimer = 0;

		int       m_attributes[Attribute::NUM_ATTS];
		Inventory m_inv;
		Item*     m_equipped[Equip::NUM_EQ];
		bool	  m_spells[Spell::NUM_SPELLS];
		int 	  m_readySpell = -1;
};

#endif
