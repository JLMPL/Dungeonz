#ifndef EXIT_HPP
#define EXIT_HPP
#include "Entity.hpp"

class Exit : public Entity
{
	public:
		Exit();

		void update(float deltaTime) override final;

		void setNext(const std::string& next);
		const std::string& getNext() const;

	private:
		std::string m_next;
};

#endif