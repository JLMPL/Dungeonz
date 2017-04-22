#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <functional>

class GameState
{
    public:
        enum class Type
        {
            Playing,
            Menu,
            Splash,
            Scrolling
        };

        GameState() {}
        virtual ~GameState() {}

        virtual void init() = 0;
        virtual void update(float deltaTime) = 0;
        virtual void leave() = 0;

        virtual void setExitFunc(std::function<void ()> func);

        Type getType();

    protected:
        Type m_type;
        std::function<void ()> m_exitFunction;
};

#endif