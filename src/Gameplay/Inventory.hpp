#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "ItemPtr.hpp"
#include <vector>
#include <array>

class Inventory
{
    public:
        bool addItem(ItemPtr_t item);
        void removeItem(const std::string& code);
        void removeItem(Item* item);
        bool hasItem(const std::string& code);

        const ItemPtr_t& getItem(int index);
        int getAmount();

    private:
        std::vector<ItemPtr_t> m_items;
};

#endif