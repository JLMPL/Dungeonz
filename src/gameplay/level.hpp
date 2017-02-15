#ifndef level_hpp
#define level_hpp
#include "entity_ptr.hpp"
#include "item_ptr.hpp"
#include "map.hpp"
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
		std::vector<Entity*> getEntitiesByCode(std::string code);

	private:
		std::vector<EntityPtr_t> m_Entities;
		uint m_lastEntityId = 0;
		std::vector<ItemPtr_t> m_Items;

		Map map;
};

#endif
