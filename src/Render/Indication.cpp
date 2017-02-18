#include "Indication.hpp"
#include "../Resource/FontCache.hpp"

Indication::Indication()
{
}

Indication::Indication(const std::string& message, const sf::Color& col, const vec2f& pos)
{
	text.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	text.setCharacterSize(10);
	text.setString(message);
	color = col;
	text.setFillColor(color);
	// text.setOrigin(static_cast<int>(text.getLocalBounds().width/2),
	// 			   static_cast<int>(text.getLocalBounds().height));
	text.setPosition(pos.geti().getSfVecf());
}

void Indication::draw()
{
	Renderer::Get().submitOverlay(&text);
}