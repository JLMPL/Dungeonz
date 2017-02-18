#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "EntityPtr.hpp"
#include "ItemPtr.hpp"
#include "Map.hpp"
#include "../Render/BigParticle.hpp"
#include <vector>

class Level
{
	public:
		void init();
		Entity* addEntity(EntityPtr_t entity);
		ItemPtr_t addItem(ItemPtr_t item);
		void addBigParticle(const std::string& path, const vec2i& pos, float life);
		void update(float deltaTime);

		std::vector<Entity*> getEntitiesInRange(const vec2f& pos, float range);
		Entity* getEntityByCode(std::string code);
		std::vector<Entity*> getEntitiesByCode(std::string code);

	private:
		std::vector<EntityPtr_t> m_Entities;
		uint m_lastEntityId = 0;
		std::vector<ItemPtr_t> m_Items;
		std::vector<BigParticle> m_BigParticles;

		Map map;
};

#endif
