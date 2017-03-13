#ifndef COLLISION_HANDLER_HPP
#define COLLISION_HANDLER_HPP
#include "BoxPtr.hpp"
#include <vector>

//Singleton
class CollisionHandler
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

		void cleanUp();

	private:
		void react(BoxPtr_t a, BoxPtr_t b);
		void clean();

	private:
		std::vector<BoxPtr_t> m_bodies;
};

#endif
