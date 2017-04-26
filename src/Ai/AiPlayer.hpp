#ifndef AI_PLAYER_HPP
#define AI_PLAYER_HPP
#include "Ai.hpp"
#include <SFML/System/Clock.hpp>

//*/
#include <SFML/Graphics.hpp>
//*/

class Entity;

class AiPlayer : public Ai
{
    public:
        enum class State
        {
            Moving = 0,
            Idle,
            Attack,
            Picking,
            Casting,
            Rolling,
            Shoot
        };

        void setup() override final;
        void update(float deltaTime) override final;
        void focus();
        
        void movingState (float deltaTime);
        void idleState   (float deltaTime);
        void attackState (float deltaTime);
        void pickingState(float deltaTime);
        void castState   (float deltaTime);
        void rollState   (float deltaTime);
        void shootState  (float deltaTime);

        void castFireball();
        void castFrostbite();
        void castLightning(float deltaTime);
        void castSpeed();
        void castHeal();
        
        State getState();

    private:
        float       m_speed = 100;
        float       m_runSpeed = 100;
        float       m_walkSpeed = 100;
        Entity*     m_focus;
        sf::Clock   m_timer;
        State m_state;

        sf::Clock m_speedSpellTimer;
        bool      m_speedSpellActive = false;

        sf::Clock m_manaRestoreTimer;

        sf::RectangleShape m_hitPoint;
        sf::Vertex m_ray[2];

        sf::Clock m_stepTimer;

        bool m_noclip = false;
        float m_noclipTimer = 0;
};

#endif
