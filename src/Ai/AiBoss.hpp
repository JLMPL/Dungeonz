#ifndef AI_BOSS
#define AI_BOSS
#include "AiMob.hpp"

class AiBoss : public Ai
{
    public:
        void setup() override;
        void update(float deltaTime) override;
        void focus();

        void idleState(float deltaTime);
        void moveState(float deltaTime);
        void attackState(float deltaTime);
        void deadState(float deltaTime);

        void fuckEmUp();
        
    private:
        Entity*   m_focus = nullptr;
        MobState  m_state;
        float     m_speed = 60;
        vec2f     m_direction;
        sf::Clock m_timer;
};

#endif