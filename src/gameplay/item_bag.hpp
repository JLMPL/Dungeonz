#ifndef ITEM_BAG_HPP
#define ITEM_BAG_HPP
#include "chest.hpp"

class ItemBag : public Chest
{
	public:
		ItemBag();

		void update(float deltaTime);
		
	private:
};

#endif