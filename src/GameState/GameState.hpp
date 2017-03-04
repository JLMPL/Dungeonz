#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

class GameState
{
	public:
		GameState() {}

		virtual void init() = 0;
		virtual void update(float deltaTime) = 0;
		virtual void leave() = 0;

	protected:

};

#endif