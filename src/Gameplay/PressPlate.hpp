#ifndef PRESS_PLATE_HPP
#define PRESS_PLATE_HPP
#include "Entity.hpp"

class PressPlate : public Entity
{
	public:
		PressPlate();

		void update(float deltaTime) override final;

		void whom(Entity* entity);

		void activate();
		void deactivate();

	private:
		bool      m_active = false;
		sf::Clock m_timer;
		Entity*   m_whom = nullptr;
};

#endif