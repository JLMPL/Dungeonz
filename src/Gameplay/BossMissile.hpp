#ifndef BOSS_MISSILE_HPP
#define BOSS_MISSILE_HPP
#include "Entity.hpp"

class BossMissile : public Entity
{
    public:
        enum class Type
        {
            Big,
            Small
        };

        BossMissile();

        void init(vec2f origin, Direction_t dir, Type type);
        void setOwner(Entity* owner);

        void setDirection(const vec2f& dir);

        void update(float deltaTime) override final;
        void blow(Entity* ent);
        void emitTrail();
        void shootOthers();

    private:
        Entity*     m_owner = nullptr;
        Type        m_type;
        Direction_t m_direction;
        vec2f       m_velocity;
        float       m_speed = 400;
        sf::Clock   m_warmup;
        sf::Clock   m_trailTimer;
};

#endif