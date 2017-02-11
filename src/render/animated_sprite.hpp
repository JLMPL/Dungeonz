#ifndef animated_sprite_hpp
#define animated_sprite_hpp
#include "sprite.hpp"
#include "../resource/animation_ptr.hpp"

class AnimatedSprite : public Sprite
{
	public:
		using Base = Sprite;

		virtual void loadFromFile(const std::string& path) override final;

		void update(float deltaTime);
		void reset();
		
		virtual void setAnimation(AnimPtr_t anim, std::function<void ()> call = [](){}) override final;

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
