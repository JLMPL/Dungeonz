#ifndef DOOR_HPP
#define DOOR_HPP
#include "Entity.hpp"

class Inventory;

class Door : public Entity
{
	public:
		Door();

		void update(float deltaTime);
		void tryOpening(Inventory* inv);
		void open();

		void setRequiredItem(const std::string& code);
		
	private:
		std::string m_requiredKey;
		bool m_isOpen = false;
};

#endif