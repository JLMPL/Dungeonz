#include "Game.hpp"
#include "Error.hpp"
#include "Screen.hpp"
#include "../Render/Renderer.hpp"
#include "../Input/InputHandler.hpp"
#include "../Resource/FontCache.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Resource/AnimationCache.hpp"
#include "../Render/IndicationHandler.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Gui/Gui.hpp"
#include "../GameState/StatePlaying.hpp"
#include "../GameState/StateSplash.hpp"
#include "../GameState/StateMenu.hpp"
#include <fstream>

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

constexpr int g_majorVersion = 0;
constexpr int g_minorVersion = 2;
constexpr int g_updateVersion = 7; //<- Everytime I add a public feature

Game::Game()
{
	loadCfg();

	Uint32 style = sf::Style::Close;

	if (Screen::Get().fullscreen)
		style = sf::Style::Fullscreen;

	sf::VideoMode mode(Screen::Get().width, Screen::Get().height);

	Window.create(mode, "", style);

	TextureCache::Get().init();
	FontCache::Get().init();
	AnimationCache::Get().init();
	InputHandler::Get().init();
	GUI::Get().init();
	CollisionHandler::Get().init();
	Renderer::Get().init(&Window);
	IndicationHandler::Get().init();

	version.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	version.setCharacterSize(10);
	version.setString("Version " + std::to_string(g_majorVersion) + "." +
								   std::to_string(g_minorVersion) + "." +
								   std::to_string(g_updateVersion) + " WIP");
	version.setPosition(sf::Vector2f(5,5));

	GUI::Get().setBackToMenuFunc(
	[this]()
	{
		begForState(new StateMenu());
		Renderer::Get().setCameraPos({Screen::Get().halfWidth, Screen::Get().halfHeight});
	});

	begForState(new StateSplash());
}

Game::~Game()
{
}

void Game::loadCfg()
{
	std::ifstream file("config.cfg");
	std::string line;
	std::stringstream sstr;

	if (!file.good())
		printf("Could not find cfg file");
	else
	{
		while (!file.eof())
		{
			std::getline(file, line);

			if (line.find("//") != std::string::npos)
				continue;
			else if (line.find("[") != std::string::npos)
				continue;
			else if (line.find("screen_width") != std::string::npos)
			{
				line[line.find("=")] = ' ';

				int target;
				char junk[32];

				sscanf(line.c_str(), "%s %d", junk, &target);

				if (target < 640) target = 640;
				Screen::Get().width = target;
				Screen::Get().halfWidth = Screen::Get().width/2;
			}
			else if (line.find("screen_height") != std::string::npos)
			{
				line[line.find("=")] = ' ';

				int target;
				char junk[32];

				sscanf(line.c_str(), "%s %d", junk, &target);

				if (target < 480) target = 480;
				Screen::Get().height = target;
				Screen::Get().halfHeight = Screen::Get().height/2;
			}
			else if (line.find("screen_full") != std::string::npos)
			{
				line[line.find("=")] = ' ';
				
				if (line.find("true") != std::string::npos)
					Screen::Get().fullscreen = true;
				else
					Screen::Get().fullscreen = false;
			}
		}
	}
}

void Game::update()
{	
	deltaTime = Clock.restart().asSeconds();

	if (m_currentState.get() != m_nextState)
	{
		setState(m_nextState);
	}

	m_currentState->update(deltaTime);

	auto ver_pos = Renderer::Get().getCameraPos() + vec2i(5,5);
	version.setPosition(ver_pos.getSfVecf());
}

void Game::mainLoop()
{
	while (Window.isOpen())
	{
		bench_begin = Benchmark.getElapsedTime().asMilliseconds();

		while (Window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				Window.close();
			if (Event.type == sf::Event::KeyPressed and Event.key.code == sf::Keyboard::F4)
				Window.close();
		}
		update();

		Renderer::Get().submitOverlay(&version);
		Renderer::Get().flush();

		bench_end = Benchmark.getElapsedTime().asMilliseconds();

		if (bench_end % 100 == 0)
		{
			Window.setTitle("Window - " + std::to_string(bench_end - bench_begin) + "ms");
		}
	}
}

void Game::setState(GameState* state)
{
	if (m_currentState)
		m_currentState->leave();
	m_currentState.reset(state);
	m_currentState->init();

	switch (m_currentState->getType())
	{
		case StateType::Splash:
		{
			auto splash = static_cast<StateSplash*>(m_currentState.get());
			splash->setExitFunc(
			[this]()
			{
				begForState(new StateMenu());
			});
		}
		break;
		case StateType::Menu:
		{
			auto menu = static_cast<StateMenu*>(m_currentState.get());
			menu->setNewGameFunc(
			[this]()
			{
				begForState(new StatePlaying());
			});

			menu->setExitFunc(
			[this]()
			{
				Window.close();
			});
		}
		break;
	}
}

void Game::begForState(GameState* state)
{
	m_nextState = state;
}