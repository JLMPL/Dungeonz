#include "game.hpp"
#include "error.hpp"
#include "../render/renderer.hpp"
#include "../input/input_handler.hpp"
#include "../resource/font_cache.hpp"
#include "../resource/texture_cache.hpp"
#include "../resource/animation_cache.hpp"
#include "../collision/collision_handler.hpp"
#include "../gui/gui.hpp"
#include "../render/indication_handler.hpp"

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

	version.setFont(*FontCache::Get().getFont("data/Monaco_Linux.ttf"));
	version.setCharacterSize(10);
	version.setString("Version 0.1.7 WIP");
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
	while(Window.isOpen())
	{
		bench_begin = Benchmark.getElapsedTime().asMilliseconds();
		while(Window.pollEvent(Event))
		{
			if(Event.type == sf::Event::Closed)
				Window.close();
			if(Event.type == sf::Event::KeyPressed and Event.key.code == sf::Keyboard::Escape)
				Window.close();
			// if(Event.type == sf::Event::KeyPressed and Event.key.code == sf::Keyboard::R)
			// {
			// 	InputHandler::Get().bindKey(KeyBind::UP, sf::Keyboard::Down);
			// 	InputHandler::Get().bindKey(KeyBind::DOWN, sf::Keyboard::Up);
			// 	InputHandler::Get().bindKey(KeyBind::LEFT, sf::Keyboard::Right);
			// 	InputHandler::Get().bindKey(KeyBind::RIGHT, sf::Keyboard::Left);
			// }
		}
		update();

		Window.clear();
		Renderer::Get().flush();
		Window.draw(version);
		Window.display();

		bench_end = Benchmark.getElapsedTime().asMilliseconds();

		if(bench_end % 100 == 0)
		{
			Window.setTitle("Window - " + std::to_string(bench_end - bench_begin) + "ms");
		}
	}
}
