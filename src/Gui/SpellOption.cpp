#include "SpellOption.hpp"
#include "../Render/Renderer.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Resource/FontCache.hpp"

SpellOption::SpellOption()
{
}

SpellOption::SpellOption(const std::string& _icon, const std::string& _label) 
{
	icon.setTexture(*TextureCache::Get().getTexture(_icon));

	label.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	label.setCharacterSize(10);
	label.setString(_label);
	label.setFillColor({255,255,255});
	label.setOrigin({0, static_cast<int>(label.getLocalBounds().height/2)});
}

void SpellOption::draw()
{
	Renderer::Get().submitOverlay(&icon);
	Renderer::Get().submitOverlay(&label);
}

void SpellOption::enable()
{
	icon.setColor({255,255,255});
	label.setFillColor({255,255,255});
}

void SpellOption::disable()
{
	icon.setColor({96,96,96});
	label.setFillColor({96,96,96});
}

void SpellOption::setPosition(const vec2i& pos)
{
	icon.setPosition(pos.getSfVecf());
	label.setPosition(vec2i(pos + vec2i(32,16)).getSfVecf());
}