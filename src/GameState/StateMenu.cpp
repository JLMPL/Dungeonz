#include "StateMenu.hpp"
#include "../Core/Screen.hpp"
#include "../Resource/FontCache.hpp"
#include "../Render/Renderer.hpp"
#include "../Input/InputHandler.hpp"

constexpr int g_menuOptionsOffset = 48;

StateMenu::StateMenu()
{
}

void StateMenu::init()
{
	m_tmpLogo.setFont(*FontCache::Get().getFont("BLKCHCRY.ttf"));
	m_tmpLogo.setCharacterSize(128);
	m_tmpLogo.setString("Dungeonz");
	m_tmpLogo.setOrigin(m_tmpLogo.getLocalBounds().width /2, 0);
	m_tmpLogo.setPosition({400, 0});

	for (int i = 0; i < MenuOptions::NumMenuOptions; i++)
	{
		m_options[i].setFont(*FontCache::Get().getFont("BLKCHCRY.ttf"));
		m_options[i].setCharacterSize(32);
	}

	m_options[MenuOptions::NewGame].setString("New Game");
	m_options[MenuOptions::HowToPlay].setString("How To Play");
	m_options[MenuOptions::Exit].setString("Exit");

	for (int i = 0; i < MenuOptions::NumMenuOptions; i++)
	{
		m_options[i].setOrigin(static_cast<int>(m_options[i].getLocalBounds().width /2), 0);
		m_options[i].setPosition(400, 300 + i * g_menuOptionsOffset);
	}
}

void StateMenu::update(float deltaTime)
{
	if (InputHandler::Get().isUp() and m_timer.getElapsedTime().asMilliseconds() > 150)
	{
		if (m_chosen > 0)
			m_chosen--;
		m_timer.restart();
	}
	else if (InputHandler::Get().isDown() and m_timer.getElapsedTime().asMilliseconds() > 150)
	{
		if (m_chosen < MenuOptions::NumMenuOptions-1)
			m_chosen++;
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
			case MenuOptions::HowToPlay:
			{

			}
			break;
			case MenuOptions::Exit:
			{
				m_exitFunction();
			}
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

void StateMenu::leave()
{

}

void StateMenu::setNewGameFunc(std::function<void ()> func)
{
	m_newGameFunc = func;
}