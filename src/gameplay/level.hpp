#ifndef level_hpp
#define level_hpp
#include "entity_ptr.hpp"
#include "living_profile.hpp"
#include "living.hpp"
#include "chest.hpp"
#include "door.hpp"
#include "lever.hpp"
#include "map.hpp"
#include "item_ptr.hpp"
#include <vector>

class Level
{
	public:
		void init();
		Entity* addEntity(EntityPtr_t entity);
		ItemPtr_t addItem(ItemPtr_t item);
		void update(float deltaTime);

		std::vector<Entity*> getEntitiesInRange(const vec2f& pos, float range);
		Entity* getEntityByCode(std::string code);

	private:
		std::vector<EntityPtr_t> m_Entities;
		uint m_lastEntityId = 0;
		std::vector<ItemPtr_t> m_Items;

		LivingProfile profile;
		// LivingProfile sht;
		// LivingProfile batpro;

		Living* player;
		// Living* frian;
		// Living* bat;

		// Chest* chest;
		// Door* door;
		// Lever* lever;

		Map mope;
		ItemPtr_t eitum;
		ItemPtr_t key;
		ItemPtr_t meat;
};

#endif
