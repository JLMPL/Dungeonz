#include "AnimatedSprite.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Resource/AnimationCache.hpp"

void AnimatedSprite::loadFromFile(const std::string& path)
{
	setAnimation(AnimationCache::Get().getAnimation(path.c_str()));

	setPosition(vec2i(0,0));
}

void AnimatedSprite::update(float deltaTime)
{
	m_time += 1000 * deltaTime;

	if(m_anim)
	{
		if(m_finished)
			m_finished = false;
		else
		{
			if(m_time >= m_anim->duration)
			{
				m_frame++;
				m_time = 0;
			}
			if(m_frame > m_anim->numFrames -1)
			{
				if(m_anim->looping)
				{
					m_frame = 0;
					m_call();
					m_finished = true;
				}
				else
				{
					m_frame--;//= m_anim->numFrames -1;
					m_call();
					m_finished = true;
				}
			}
			setRect({
				m_frame * m_sprite.getLocalBounds().width, 
				m_direction * m_sprite.getLocalBounds().height, 
				m_sprite.getLocalBounds().width, 
				m_sprite.getLocalBounds().height
			});
		}
		draw();
	}
}

void AnimatedSprite::reset()
{
	m_anim = m_nextAnim;
	m_call = m_nextCall;
	m_nextAnim = nullptr;

	m_sprite.setTexture(*TextureCache::Get().getTexture(m_anim->image));
	setSize(m_anim->size);
	setOrigin(m_anim->origin);
	setRect({0,0, m_anim->size.x, m_anim->size.y});

	m_frame = 0;
	m_finished = false;
	m_time = 0;
}

void AnimatedSprite::setAnimation(AnimPtr_t anim, std::function<void ()> call)
{
	if(m_anim != anim)
	{
		m_nextAnim = anim;
		m_nextCall = call;

		if(m_anim)
		{
			if(m_anim->looping)
			{
				m_finished = true;
				reset();
			}
			else if(m_frame == m_anim->numFrames -1)
			{
				m_finished = true;
				reset();
			}
		}
		else
		{
			m_finished = true;
			reset();
		}
	}
}

bool AnimatedSprite::isFinished() const
{
	return m_finished;
}