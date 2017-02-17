#ifndef BIG_PARTICLE_HPP
#define BIG_PARTICLE_HPP
#include "animated_sprite.hpp"
#include "../core/vec2.hpp"
#include <SFML/System/Clock.hpp>

class BigParticle
{
	public:
		BigParticle();

		void init(const std::string& path, float lifeLenght);
		void update(float deltaTime);
		void setPosition(const vec2i& pos);
		bool isDead();

	private:
		AnimatedSprite m_sprite;
		float          m_lifeLenght = 1;
		bool           m_dead = false;
		sf::Clock      m_timer;
};

#endif