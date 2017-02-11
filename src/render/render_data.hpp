#ifndef texture_data_hpp
#define texture_data_hpp
#include <SFML/Graphics/Sprite.hpp>

struct RenderData
{
	sf::Drawable* data;
	float z = 0;

	RenderData() {}
	RenderData(sf::Drawable* date, float zed = 0) : data(date), z(zed) {}
};

#endif
