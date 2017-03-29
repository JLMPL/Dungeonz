#ifndef AI_MOB_MAGE
#define AI_MOB_MAGE
#include "AiMob.hpp"

class AiMobMage : public Ai
{
    public:
        void setup() override;
        void update(float deltaTime) override;
        void focus();

        void idleState(float deltaTime);
        void fleeState(float deltaTime, bool forward);
        void attackState(float deltaTime);
        void deadState(float deltaTime);
        
    private:
        Entity*   m_focus = nullptr;
        MobState  m_state;
        float     m_speed = 60;
        vec2f     m_direction;
        sf::Clock m_timer;
};

#endif