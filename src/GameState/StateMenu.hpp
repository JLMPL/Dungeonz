#ifndef STATE_MENU_HPP
#define STATE_MENU_HPP
#include "GameState.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

enum MenuOptions
{
    NewGame,
    Continue,
    HowToPlay,
    Exit,
    NumMenuOptions
};

enum class MenuState
{
    MainScreen,
    HelpScreen
};

class StateMenu : public GameState
{
    public:
        StateMenu();

        void init() override final;
        void loadHelp();
        void update(float deltaTime) override final;
        void leave() override final;

        void menuState();
        void helpState();

        void setNewGameFunc(std::function<void ()> func);
        void setContinueFunc(std::function<void (const std::string&)> func);

        std::string whereILeft();

    private:
        std::function<void ()> m_newGameFunc;
        std::function<void (const std::string&)> m_continueFunc;
        sf::Text m_tmpLogo;

        int m_chosen = 1;
        sf::Text m_options[MenuOptions::NumMenuOptions];
        sf::Clock m_timer;

        sf::Text m_helpText;

        MenuState m_state = MenuState::MainScreen;
};

#endif