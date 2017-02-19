#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "RenderAttribute.hpp"
#include "RenderData.hpp"
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>

//Singleton
class Renderer
{
	public:
		static Renderer& Get()
		{
			static Renderer self;
			return self;
		}

		void init(sf::RenderWindow* window);

		void submitBackground(sf::CircleShape* data);
		void submitBackground(sf::Sprite* data);
		void submitSorted(sf::Sprite* data);

		void submitOverlay(sf::RectangleShape* data);
		void submitOverlay(sf::Sprite* data);
		void submitOverlay(sf::Text* data);
		void flush();

		void setCameraPos(const vec2i& pos);
		vec2i getCameraPos() const;

	private:
		void updateCamera();
		void cull();
		void sort();
		void render();
		void clearAll();

	private:
		sf::RenderWindow* m_window = nullptr;
		std::vector<sf::CircleShape*> m_backCircleData;
		std::vector<sf::Sprite*> m_backgroundData;
		std::vector<sf::Sprite*> m_sortedData;

		//gui
		std::vector<sf::RectangleShape*> m_overRectData;
		std::vector<sf::Sprite*>         m_overSpriteData;
		std::vector<sf::Text*>           m_overTextData;
		sf::View m_camera;
};

#endif