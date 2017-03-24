#ifndef LIGHTNING_HPP
#define LIGHTNING_HPP
#include "Entity.hpp"
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Clock.hpp>

class LightningBolt : public Entity
{
    public:
        LightningBolt();

        void init(const vec2f& start, const vec2f& end);
        void update(float deltaTime) override final;
        void compute();

    private:
        sf::Vertex m_line[10];
        sf::Vertex m_secLine[10];
        vec2f      m_start;
        vec2f      m_end;
        sf::Clock  m_timer;
        sf::Clock  m_life;
};

#endif