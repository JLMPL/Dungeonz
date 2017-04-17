#ifndef ARROW_HPP
#define ARROW_HPP
#include "Entity.hpp"

class Arrow : public Entity
{
    public:
        Arrow();

        void init(const vec2f& pos, Direction_t dir);
        void update(float deltaTime) override final;

        void blow(Entity* ent);

        void setOwner(Entity* owner);
        void setDamage(int damage);
        void setDecay(float seconds);

    private:
        Entity*     m_owner = nullptr;
        Direction_t m_direction;
        vec2f       m_velocity;
        float       m_speed = 250;
        int         m_damage = 100;
        float       m_decay = 2;
        sf::Clock   m_decayTimer;
        sf::Clock   m_warmup;
};

#endif