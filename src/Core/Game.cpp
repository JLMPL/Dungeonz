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
#include <fstream>
#include <sstream>

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

Game::Game()
{
	loadCfg();

	//Window.create(sf::VideoMode(800, 600), "Window", sf::Style::Close); //res
	Window.create(sf::VideoMode(Screen::Get().width, Screen::Get().height), "Window", sf::Style::Close);

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
	version.setString("Version 0.2.3 WIP");
	version.setPosition(sf::Vector2f(5,5));

	m_playingState.init();

	m_splashState.init();
	m_splashState.setExitFunc(
	[&]()
	{
		m_currentState = &m_menuState;
	});

	m_menuState.init();
	m_menuState.setNewGameFunc(
	[&]()
	{
		m_currentState = &m_playingState;
	});
	m_menuState.setExitFunc(
	[&]()
	{
		Window.close();
	});

	m_currentState = &m_splashState;
}

Game::~Game()
{
}

#include <iostream>

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
			printf("%s\n", line.c_str());

			if (line.find("//") != std::string::npos)
				continue;
			else if (line.find("screen_width") != std::string::npos)
			{
				line[line.find("=")] = ' ';
				sstr = std::stringstream(line);

				std::string junk;

				sstr >> junk;
				sstr >> junk;
				Screen::Get().width = std::stoi(junk);
				Screen::Get().halfWidth = Screen::Get().width/2;

				std::cout << Screen::Get().width << std::endl;
			}
			else if (line.find("screen_height") != std::string::npos)
			{
				line[line.find("=")] = ' ';
				sstr = std::stringstream(line);

				std::string junk;

				sstr >> junk;
				sstr >> junk;
				Screen::Get().height = std::stoi(junk);
				Screen::Get().halfHeight = Screen::Get().height/2;

				std::cout << Screen::Get().height << std::endl;
			}
		}
	}
}

void Game::update()
{
	deltaTime = Clock.restart().asSeconds();

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
