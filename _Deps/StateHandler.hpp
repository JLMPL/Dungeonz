#ifndef STATE_HANDLER_HPP
#define STATE_HANDLER_HPP

class GameState;

class StateHandler
{
	public:
		StateHandler();
		~StateHandler();

		void update(float deltaTime);

		void setState(GameState* state);

	private:
		GameState* m_state;
};

#endif