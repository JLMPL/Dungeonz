#ifndef collision_handler_hpp
#define collision_handler_hpp
#include "../message/listener.hpp"
#include "box_ptr.hpp"
#include <vector>

//Singleton
class CollisionHandler : public Listener
{
	public:
		static CollisionHandler& Get()
		{
			static CollisionHandler self;
			return self;
		}

		void init();
		void update(float deltaTime);

		void addBody(BoxPtr_t box);

		virtual void sendMessage(int message, MessagePtr_t value) override final;

	private:
		void clean();

	private:
		std::vector<BoxPtr_t> m_Bodies;
};

#endif
