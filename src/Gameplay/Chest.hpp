#ifndef CHEST_HPP
#define CHEST_HPP
#include "Entity.hpp"
#include "Inventory.hpp"

class Chest : public Entity
{
    public:
        Chest();

        void update(float deltaTime);

        void setRequiredItem(const std::string& item);
        void tryOpening(Inventory* inv);
        void open();

        bool isOpen();
        Inventory& accessInv();

    protected:
        Inventory m_inv;
        std::string m_requiredKey;
        bool m_isOpen = false;
};

#endif