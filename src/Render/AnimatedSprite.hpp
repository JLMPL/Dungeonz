#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP
#include "Sprite.hpp"
#include "../Resource/AnimationPtr.hpp"

class AnimatedSprite : public Sprite
{
	public:
		using Base = Sprite;

		void loadFromFile(const std::string& path) override final;

		void update(float deltaTime);
		void reset();
		
		void setAnimation(AnimPtr_t anim, std::function<void ()> call = [](){}) override final;

		bool isFinished() const;

	private:
		int   m_frame = 0;
		float m_time = 0;
		bool  m_finished = false;

		AnimPtr_t m_anim;
		AnimPtr_t m_nextAnim;

		std::function<void ()> m_call;
		std::function<void ()> m_nextCall;
};

#endif
