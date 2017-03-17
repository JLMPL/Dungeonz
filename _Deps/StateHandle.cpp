#include "StateHandler.hpp"
#include "GameState.hpp"
#include "StateMenu.hpp"

StateHandler::StateHandler()
{
	setState(new Shit());
}

StateHandler::~StateHandler()
{
	if (m_state)
		delete m_state;
}

void StateHandler::update(float deltaTime)
{
	m_state->update(deltaTime);
}

void StateHandler::setState(GameState* state)
{
	if (m_state)
		delete m_state;

	m_state = state;
}
