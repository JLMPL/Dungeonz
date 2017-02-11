#ifndef inventory_hpp
#define inventory_hpp
#include "item_ptr.hpp"
#include <vector>
#include <array>

class Inventory
{
	public:
		bool addItem(ItemPtr_t item);
		void removeItem(const std::string& code);
		void removeItem(Item* item);
		bool hasItem(const std::string& code);

		ItemPtr_t getItem(int index);
		int getAmount();

	private:
		std::vector<ItemPtr_t> m_Items;
};

#endif