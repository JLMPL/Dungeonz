#ifndef SHOOT_TRAP_HPP
#define SHOOT_TRAP_HPP
#include "Entity.hpp"
#include "../Core/Direction.hpp"

class ShootTrap : public Entity
{
    public:
        ShootTrap(Direction_t dir);

        void update(float deltaTime) override final;

        void enable();
        void disable();

    private:
        bool m_enabled = true;
        sf::Clock m_shootTimer;
        Direction_t m_aim;
};

#endif