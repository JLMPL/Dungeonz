#ifndef STATE_MENU_HPP
#define STATE_MENU_HPP
#include "GameState.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

enum MenuOptions
{
	NewGame,
	HowToPlay,
	Exit,
	NumMenuOptions
};

class StateMenu : public GameState
{
	public:
		StateMenu();

		void init() override final;
		void update(float deltaTime) override final;
		void leave() override final;

		void setNewGameFunc(std::function<void ()> func);

	private:
		std::function<void ()> m_newGameFunc;
		sf::Text m_tmpLogo;

		int m_chosen = 0;
		sf::Text m_options[MenuOptions::NumMenuOptions];
		sf::Clock m_timer;
};

#endif