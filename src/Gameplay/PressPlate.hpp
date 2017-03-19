#ifndef PRESS_PLATE_HPP
#define PRESS_PLATE_HPP
#include "Entity.hpp"
#include <vector>
#include <functional>

class PressPlate : public Entity
{
	public:
		PressPlate();

		void update(float deltaTime) override final;

		void activate();
		void deactivate();

		void setActivateFunc(std::function<void ()> func);
		void setDeactivateFunc(std::function<void ()> func);

	private:
		bool m_active = false;
		sf::Clock m_timer;

		std::function<void ()> m_activateFunc;
		std::function<void ()> m_deactivateFunc;
};

#endif