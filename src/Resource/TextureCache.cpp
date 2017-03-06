#include "TextureCache.hpp"

void TextureCache::init()
{
	m_zip = zip_open("data/textures.pak", 0, 'r');
}

TextureCache::~TextureCache()
{
	zip_close(m_zip);
}

TexturePtr_t TextureCache::getTexture(const std::string& path)
{
	auto texture = m_Textures.find(path);
	if (texture == m_Textures.end())
		return loadTexture(path);
	else
		return m_Textures[path];
}

TexturePtr_t TextureCache::loadTexture(const std::string& path)
{
	//std::string finalpath = "data/Images/" + path;

	void* buffer = nullptr;
	size_t buffer_size = 0;

	zip_entry_open(m_zip, path.c_str());
	zip_entry_read(m_zip, &buffer, &buffer_size);

	if (!buffer)
	{
		printf("Failed to load %s!\n", path.c_str());
	}

	TexturePtr_t texture = TexturePtr_t(new sf::Texture());
	// texture->loadFromFile(finalpath);
	texture->loadFromMemory(buffer, buffer_size);
	m_Textures.insert(std::make_pair(path, texture));

	zip_entry_close(m_zip);
	return texture;
}
