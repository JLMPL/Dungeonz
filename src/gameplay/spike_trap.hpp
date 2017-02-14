#ifndef spike_trap_hpp
#define spike_trap_hpp
#include "entity.hpp"

class SpikeTrap : public Entity
{
	public:
		SpikeTrap();

		void update(float deltaTime) override final;

		void activate();
		void deactivate();

	private:
		bool m_active = false;
		float m_timer = 0;
};

#endif