#include "font_cache.hpp"

void FontCache::init()
{
}

FontPtr_t FontCache::getFont(const std::string& path)
{
	auto font = m_Fonts.find(path);

	if(font == m_Fonts.end())
		return loadFont(path);
	else
		return m_Fonts[path];
}

FontPtr_t FontCache::loadFont(const std::string& path)
{
	FontPtr_t font = FontPtr_t(new sf::Font());
	font->loadFromFile(path);
	m_Fonts.insert(std::make_pair(path, font));
	return font;
}
