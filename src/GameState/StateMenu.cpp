#include "StateMenu.hpp"
#include "../Core/Screen.hpp"
#include "../Resource/FontCache.hpp"
#include "../Render/Renderer.hpp"
#include "../Input/InputHandler.hpp"
#include "../Core/Files.hpp"
#include <fstream>

constexpr int g_menuOptionsOffset = 48;

StateMenu::StateMenu()
{
    m_type = Type::Menu;
}

void StateMenu::init()
{
    m_tmpLogo.setFont(*FontCache::Get().getFont("BLKCHCRY.ttf"));
    m_tmpLogo.setCharacterSize(128);
    m_tmpLogo.setString("Dungeonz");
    m_tmpLogo.setOrigin(static_cast<int>(m_tmpLogo.getLocalBounds().width /2),
                        static_cast<int>(m_tmpLogo.getLocalBounds().height /2));
    m_tmpLogo.setPosition({Screen::Get().halfWidth, Screen::Get().height /4});

    for (int i = 0; i < MenuOptions::NumMenuOptions; i++)
    {
        m_options[i].setFont(*FontCache::Get().getFont("BLKCHCRY.ttf"));
        m_options[i].setCharacterSize(32);
    }

    m_options[MenuOptions::NewGame].setString("New Game");
    m_options[MenuOptions::Continue].setString("Continue");
    m_options[MenuOptions::HowToPlay].setString("How To Play");
    m_options[MenuOptions::Exit].setString("Exit");

    for (int i = 0; i < MenuOptions::NumMenuOptions; i++)
    {
        m_options[i].setOrigin(static_cast<int>(m_options[i].getLocalBounds().width /2), 0);
        m_options[i].setPosition(Screen::Get().halfWidth,
                                 Screen::Get().halfHeight + i * g_menuOptionsOffset);
    }

    m_helpText.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
    m_helpText.setCharacterSize(30);
    loadHelp();
    m_helpText.setOrigin(static_cast<int>(m_helpText.getLocalBounds().width/2),
                         static_cast<int>(m_helpText.getLocalBounds().height/2));
    m_helpText.setPosition({Screen::Get().halfWidth, Screen::Get().halfHeight});

    initWarning();
    chosenMessage();
}

void StateMenu::initWarning()
{
    m_warningMessage.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
    m_warningMessage.setCharacterSize(10);
    m_warningMessage.setFillColor({255,255,255});
    m_warningMessage.setPosition(Screen::Get().halfWidth, Screen::Get().height - 48);
}

void StateMenu::setupWarning(const std::string& message)
{
    m_warningMessage.setString(message);
    m_warningMessage.setOrigin(static_cast<int>(m_warningMessage.getLocalBounds().width/2), m_warningMessage.getLocalBounds().height);
    m_warningMessage.setPosition(Screen::Get().halfWidth, Screen::Get().height - 48);
}

void StateMenu::loadHelp()
{
    std::ifstream file("data/help");
    std::string line;
    std::string content;

    if (!file.good())
        printf("Error: Couldn't load \"data/help\" file!\n");
    else
    {
        while (!file.eof())
        {
            std::getline(file, line);
            content += line + '\n';
        }
    }
    m_helpText.setString(content);

    file.close();
}

void StateMenu::update(float deltaTime)
{
    switch (m_state)
    {
        case MenuState::MainScreen:
            menuState();
            break;
        case MenuState::HelpScreen:
            helpState();
            break;
    }

    Renderer::Get().submitOverlay(&m_warningMessage);
}

void StateMenu::menuState()
{
    if (InputHandler::Get().isUp() and m_timer.getElapsedTime().asMilliseconds() > 150)
    {
        if (m_chosen > 0)
            m_chosen--;

        chosenMessage();
        m_timer.restart();
    }
    else if (InputHandler::Get().isDown() and m_timer.getElapsedTime().asMilliseconds() > 150)
    {
        if (m_chosen < MenuOptions::NumMenuOptions -1)
            m_chosen++;

        chosenMessage();        
        m_timer.restart();
    }
    else if (InputHandler::Get().isKeyPressed(sf::Keyboard::Return))
    {
        switch (m_chosen)
        {
            case MenuOptions::NewGame:
            {
                m_newGameFunc();
            }
            break;
            case MenuOptions::Continue:
            {
                if (Files::doesFileExist("data/checkpoint.sav"))
                    m_continueFunc(whereILeft());
            }
            break;
            case MenuOptions::HowToPlay:
                m_state = MenuState::HelpScreen;
                break;
            case MenuOptions::Exit:
                m_exitFunction();
                break;
        }
    }

    for (auto& i : m_options)
        i.setFillColor({128,128,128});

    m_options[m_chosen].setFillColor(sf::Color::White);

    Renderer::Get().submitOverlay(&m_tmpLogo);

    for (auto& i : m_options)
        Renderer::Get().submitOverlay(&i);
}

void StateMenu::helpState()
{
    if ((InputHandler::Get().isEscape() or InputHandler::Get().isInv()) and
        m_timer.getElapsedTime().asMilliseconds() > 150)
    {
        m_state = MenuState::MainScreen;
    }

    Renderer::Get().submitOverlay(&m_helpText);
}

void StateMenu::chosenMessage()
{
    std::string appendix;

    switch (m_chosen)
    {
        case MenuOptions::NewGame:
        {
            if (Files::doesFileExist("data/checkpoint.sav"))
                appendix = "(Your current save will be overriden!)";

            setupWarning("Starts a new game. " + appendix);
        }
        break;
        case MenuOptions::Continue:
        {
            if (!Files::doesFileExist("data/checkpoint.sav"))
                appendix = "(No saves on disk)";
            setupWarning("Loads saved game. " + appendix);
        }
        break;
        case MenuOptions::HowToPlay:
            setupWarning("Instructions");
            break;
        case MenuOptions::Exit:
            setupWarning("Close the program.");
            break;
    }
}

void StateMenu::leave()
{
}

void StateMenu::setNewGameFunc(std::function<void ()> func)
{
    m_newGameFunc = func;
}

void StateMenu::setContinueFunc(std::function<void (const std::string&)> func)
{
    m_continueFunc = func;
}

std::string StateMenu::whereILeft()
{
    char cstr[32];

    FILE* file = fopen("data/checkpoint.sav", "r");
    fscanf(file, "%s", cstr);
    fclose(file);

    std::string str = cstr;
    
    return str;
}