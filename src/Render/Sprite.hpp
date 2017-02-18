#ifndef SPRITE_HPP
#define SPRITE_HPP
#include "../Core/Direction.hpp"
#include "../Core/Vec2.hpp"
#include "../Core/Rect.hpp"
#include "../Resource/TexturePtr.hpp"
#include "../Resource/AnimationPtr.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <functional>

class Sprite
{
	public:
		virtual ~Sprite() {}
		virtual void loadFromFile(const std::string& path);

		virtual void update(float deltaTime) {}
		virtual void setAnimation(AnimPtr_t anim, std::function<void ()> cell = [](){}) {};

		void draw();

		void setSize(vec2i size);
		void setRect(Recti rect);
		void setOrigin(vec2i origin);
		void setPosition(const vec2i& pos);
		void setDirection(Direction_t dir);

		vec2i getPosition() const;

	protected:
		sf::Sprite  m_sprite;
		Direction_t m_direction = Direction::UP;
};

#endif
