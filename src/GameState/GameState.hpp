#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <functional>

class GameState
{
	public:
		GameState() {}
		virtual ~GameState() {}

		virtual void init() = 0;
		virtual void update(float deltaTime) = 0;
		virtual void leave() = 0;

		virtual void setExitFunc(std::function<void ()> func);

	protected:
		std::function<void ()> m_exitFunction;
};

#endif