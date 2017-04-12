#ifndef COLLISION_HANDLER_HPP
#define COLLISION_HANDLER_HPP
#include "Box.hpp"
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

        void addBody(Box::Ptr box);
        vec2f castRay(vec2f origin, vec2f end);

        void cleanUp();

    private:
        void react(Box::Ptr a, Box::Ptr b);
        void clean();

    private:
        std::vector<Box::Ptr> m_bodies;
};

#endif
