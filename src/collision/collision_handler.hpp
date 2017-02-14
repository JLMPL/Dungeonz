#ifndef collision_handler_hpp
#define collision_handler_hpp
#include "box_ptr.hpp"
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

	private:
		void react(BoxPtr_t a, BoxPtr_t b);
		void clean();

	private:
		std::vector<BoxPtr_t> m_Bodies;
};

#endif
