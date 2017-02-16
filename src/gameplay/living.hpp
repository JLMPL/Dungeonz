#ifndef LIVING_HPP
#define LIVING_HPP
#include "entity.hpp"
#include "living_profile.hpp"
#include "stats.hpp"
#include "inventory.hpp"
#include "../ai/ai_ptr.hpp"
#include "../core/direction.hpp"
#include "../resource/animation_ptr.hpp"
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

		void equipWeapon(const std::string& code);
		void equipArmor(const std::string& code);

		/* This shit's gonna be in scripts (equip() & takeoff()) */
		void setDamage(int high);
		void restoreBasicDamage();

		void restoreHealth(int heal);
		void restoreFullHealth();

		void restoreMana(int mana);
		void restoreFullMana();
		
		void setEquippedItem(int where, Item* item);
		bool isEquipped(int where, Item* item);

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

	private:
		LivingProfile m_profile;
		Direction_t   m_facing;
		AIPtr_t       m_ai = nullptr;
		bool          m_busy = false;

		sf::CircleShape m_shadow;

		bool        m_push = false;
		Direction_t m_pushDir;
		vec2f       m_startPush;
		vec2f       m_endPush;
		float       m_pushTimer = 0;
		float       m_pushDuration;

		float 		m_trapTimer = 0;

		int       m_attributes[Attribute::NUM_ATTS];
		Inventory m_inv;
		Item*     m_equipped[Equip::NUM_EQ];
};

#endif
