#ifndef ITEM_BAG_HPP
#define ITEM_BAG_HPP
#include "Chest.hpp"

class ItemBag : public Chest
{
    public:
        ItemBag();

        void update(float deltaTime);
        
    private:
        sf::CircleShape m_shadow;
};

#endif