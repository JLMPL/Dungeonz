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

		void setFunc(std::function<void ()> func);
		void goFurther();

	private:
		std::string m_next;
		std::function<void ()> m_exit;
};

#endif