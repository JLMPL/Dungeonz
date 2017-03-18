#ifndef PRESS_PLATE_HPP
#define PRESS_PLATE_HPP
#include "Entity.hpp"
#include <vector>

class PressPlate : public Entity
{
	public:
		PressPlate();

		void update(float deltaTime) override final;

		void whom(const std::vector<Entity*>& entity);

		void activate();
		void deactivate();

	private:
		bool      m_active = false;
		sf::Clock m_timer;
		std::vector<Entity*> m_whom;
};

#endif