#ifndef INDICATION_HANDLER_HPP
#define INDICATION_HANDLER_HPP
#include <vector>

//For indication
#include "../resource/font_cache.hpp"
#include "../core/vec2.hpp"
#include "renderer.hpp"
#include <SFML/Graphics/Text.hpp>

struct Indication
{
	sf::Text text;
	sf::Color color;
	float transparency = 255;

	Indication() {}
	Indication(const std::string& message, const sf::Color& col, const vec2f& pos)
	{
		text.setFont(*FontCache::Get().getFont("data/Monaco_Linux.ttf"));
		text.setCharacterSize(10);
		text.setString(message);
		color = col;
		text.setFillColor(color);
		// text.setOrigin(static_cast<int>(text.getLocalBounds().width/2),
		// 			   static_cast<int>(text.getLocalBounds().height));
		text.setPosition(pos.geti().getSfVecf());
	}

	void draw()
	{
		Renderer::Get().submitOverlay(&text);
	}
};

class IndicationHandler
{
	public:
		static IndicationHandler& Get()
		{
			static IndicationHandler self;
			return self;
		}

		void init();
		void update(float deltaTime);
		void addIndication(const std::string& message, const sf::Color& col, const vec2f& pos);

	private:
		std::vector<Indication> m_inds;
};

#endif