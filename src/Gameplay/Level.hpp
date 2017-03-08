#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "EntityPtr.hpp"
#include "ItemPtr.hpp"
#include "FireMissile.hpp"
#include "IceMissile.hpp"
#include "Map.hpp"
#include "../Render/BigParticle.hpp"
#include <vector>

class Level
{
	public:
		void init();
		Entity* addEntity(EntityPtr_t entity);
		ItemPtr_t addItem(ItemPtr_t item);
		FireMissile* addFireMissile(std::shared_ptr<FireMissile> missile);
		IceMissile* addIceMissile(std::shared_ptr<IceMissile> missile);
		void addBigParticle(const std::string& path, const vec2i& pos, const vec2i& offset, float life);
		void update(float deltaTime);

		std::vector<Entity*> getEntitiesInRange(const vec2f& pos, float range);
		Entity* getEntityByCode(std::string code);
		std::vector<Entity*> getEntitiesByCode(std::string code);

	private:
		std::vector<EntityPtr_t> m_entities;
		uint m_lastEntityId = 0;
		std::vector<ItemPtr_t> m_items;
		std::vector<BigParticle> m_bigParticles;
		std::vector<std::shared_ptr<FireMissile>> m_missiles;
		std::vector<std::shared_ptr<IceMissile>> m_iceMissiles;

		Map map;
};

#endif
