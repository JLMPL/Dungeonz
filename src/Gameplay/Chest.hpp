#ifndef CHEST_HPP
#define CHEST_HPP
#include "Entity.hpp"
#include "Inventory.hpp"

class Chest : public Entity
{
	public:
		Chest();

		void update(float deltaTime);
		Inventory& accessInv();

	protected:
		Inventory m_inv;
};

#endif