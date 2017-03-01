#include "Game.hpp"
#include "Error.hpp"
#include "../Render/Renderer.hpp"
#include "../Input/InputHandler.hpp"
#include "../Resource/FontCache.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Resource/AnimationCache.hpp"
#include "../Render/IndicationHandler.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Gui/Gui.hpp"

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

Game::Game()
{
	Window.create(sf::VideoMode(800,600), "Window", sf::Style::Close);

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
	version.setString("Version 0.2.1 WIP");
	version.setPosition(sf::Vector2f(5,5));

	level.init();
}

Game::~Game()
{
}

void Game::update()
{
	deltaTime = Clock.restart().asSeconds();

	level.update(deltaTime);

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
			if (Event.type == sf::Event::KeyPressed and Event.key.code == sf::Keyboard::Escape)
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
