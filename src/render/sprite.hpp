#ifndef sprite_hpp
#define sprite_hpp
#include "../resource/texture_ptr.hpp"
#include "../resource/animation_ptr.hpp"
#include "../core/direction.hpp"
#include "../core/vec2.hpp"
#include "../core/rect.hpp"
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
