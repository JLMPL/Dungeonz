#include "TextureCache.hpp"

void TextureCache::init()
{

}

TexturePtr_t TextureCache::getTexture(const std::string& path)
{
	auto texture = m_Textures.find(path);
	if(texture == m_Textures.end())
		return loadTexture(path);
	else
		return m_Textures[path];
}

TexturePtr_t TextureCache::loadTexture(const std::string& path)
{
	std::string finalpath = "data/Images/" + path;
	TexturePtr_t texture = TexturePtr_t(new sf::Texture());
	texture->loadFromFile(finalpath);
	m_Textures.insert(std::make_pair(path, texture));
	return texture;
}
