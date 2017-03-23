#ifndef ARROW_HPP
#define ARROW_HPP
#include "Entity.hpp"

class Arrow : public Entity
{
    public:
        Arrow();

        void init(const vec2f& pos, Direction_t dir);
        void update(float deltaTime) override final;

        void setOwner(Entity* owner);
    private:
        Entity*     m_owner = nullptr;
        Direction_t m_direction;
        vec2f       m_velocity;
        float       m_speed = 250;
};

#endif