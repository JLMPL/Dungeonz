#ifndef renderer_hpp
#define renderer_hpp
#include "render_attribute.hpp"
#include "render_data.hpp"
#include "../message/listener.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>

//Singleton
class Renderer : public Listener
{
	public:
		static Renderer& Get()
		{
			static Renderer self;
			return self;
		}

		void init(sf::RenderWindow* window);
		void submit(const RenderData& data, const RenderAttribute& att);
		void submit(sf::RectangleShape* data);
		void submito(sf::Sprite* data);
		void submit(sf::Text* data);
		void flush();

		virtual void sendMessage(int message, MessagePtr_t value) override final;

		vec2i getCameraPos() const;

	private:
		void updateCamera();
		void sort();
		void render();
		void clearAll();

		void setCameraPos(const vec2i& pos);

	private:
		sf::RenderWindow* m_window = nullptr;
		std::vector<RenderData> m_BackgroundData;
		std::vector<RenderData> m_SortedData;
		std::vector<RenderData> m_OverlayData;

		std::vector<sf::Sprite*> m_SpriteData;
		std::vector<sf::RectangleShape*> m_RectData;
		std::vector<sf::Text*> m_TextData;
		sf::View m_camera;
};

#endif
