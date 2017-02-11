#ifndef chest_hpp
#define chest_hpp
#include "entity.hpp"
#include "inventory.hpp"

class Chest : public Entity
{
	public:
		Chest();

		void update(float deltaTime);

		Inventory& accessInv();
	private:
		Inventory m_inv;
};

#endif