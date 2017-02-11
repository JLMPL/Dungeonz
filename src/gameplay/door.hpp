#ifndef door_hpp
#define door_hpp
#include "entity.hpp"

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