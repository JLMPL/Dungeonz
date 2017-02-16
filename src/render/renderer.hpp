#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "render_attribute.hpp"
#include "render_data.hpp"
#include "../core/vec2.hpp"
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
		// void submit(const RenderData& data, const RenderAttribute& att);

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
		void sort();
		void render();
		void clearAll();

	private:
		sf::RenderWindow* m_window = nullptr;
		std::vector<sf::CircleShape*> m_BackCircleData;
		std::vector<sf::Sprite*> m_BackgroundData;
		std::vector<sf::Sprite*> m_SortedData;
		std::vector<sf::Sprite*> m_OverlayData;

		//gui
		std::vector<sf::RectangleShape*> m_RectData;
		std::vector<sf::Sprite*>         m_SpriteData;
		std::vector<sf::Text*>           m_TextData;
		sf::View m_camera;
};

#endif
