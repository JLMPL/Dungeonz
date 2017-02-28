#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

//for SpellOption
#include "../Render/Renderer.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Resource/FontCache.hpp"
#include <SFML/Graphics/Text.hpp>

struct SpellOption
{
	sf::Sprite icon;
	sf::Text label;

	SpellOption() {}
	SpellOption(const std::string& _icon, const std::string& _label) 
	{
		icon.setTexture(*TextureCache::Get().getTexture(_icon));

		label.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
		label.setCharacterSize(10);
		label.setString(_label);
		label.setFillColor({255,255,255});
		label.setOrigin({0, static_cast<int>(label.getLocalBounds().height/2)});
	}

	void draw()
	{
		Renderer::Get().submitOverlay(&icon);
		Renderer::Get().submitOverlay(&label);
	}

	void setPosition(const vec2i& pos)
	{
		icon.setPosition(pos.getSfVecf());
		label.setPosition(vec2i(pos + vec2i(32,16)).getSfVecf());
	}
};

class Living;

class Spellbook
{
	public:
		Spellbook();

		void update(float deltaTime);

		void setPosition(const vec2i& pos);
		void setTarget(Living* target);

	private:
		Living* m_target;
		vec2i m_position;

		sf::RectangleShape m_background;
		std::vector<SpellOption> m_options;

		int m_chosen = 0;
		sf::RectangleShape m_selection;
};

#endif