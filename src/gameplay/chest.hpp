#ifndef CHEST_HPP
#define CHEST_HPP
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