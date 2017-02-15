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

		void enable();
		void disable();

	private:
		bool m_active = false;
		bool m_enabled = true;
		float m_timer = 0;
};

#endif