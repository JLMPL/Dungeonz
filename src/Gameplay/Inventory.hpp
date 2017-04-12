#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "Item.hpp"
#include <vector>
#include <array>

class Inventory
{
    public:
        bool addItem(Item::Ptr item);
        void removeItem(const std::string& code);
        void removeItem(Item* item);
        bool hasItem(const std::string& code);

        const Item::Ptr& getItem(int index);
        int getAmount();

    private:
        std::vector<Item::Ptr> m_items;
};

#endif