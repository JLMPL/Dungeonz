#ifndef STATE_MENU_HPP
#define STATE_MENU_HPP
#include "GameState.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

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
    HelpScreen,
    Warning
};

class StateMenu : public GameState
{
    public:
        StateMenu();

        void init() override final;
        void initWarning();
        void setupWarning(const std::string& message);

        void loadHelp();
        void update(float deltaTime) override final;
        void leave() override final;

        void menuState();
        void helpState();

        void chosenMessage();

        void setNewGameFunc(std::function<void ()> func);
        void setContinueFunc(std::function<void (const std::string&)> func);

        std::string whereILeft();

    private:
        MenuState m_state = MenuState::MainScreen;
        std::function<void ()> m_newGameFunc;
        std::function<void (const std::string&)> m_continueFunc;
        sf::Text m_tmpLogo;

        int m_chosen = 1;
        sf::Text m_options[MenuOptions::NumMenuOptions];
        sf::Clock m_timer;

        sf::Text m_helpText;
        sf::Text m_warningMessage;
};

#endif