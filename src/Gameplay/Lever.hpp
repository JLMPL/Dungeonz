#ifndef LEVER_HPP
#define LEVER_HPP
#include "Entity.hpp"
#include <functional>

class Lever : public Entity
{
    public:
        Lever();

        void update(float deltaTime) override final;
        void activate();

        void setActivateFunc(std::function<void ()> func);

    private:
        std::function<void ()> m_func;
};

#endif