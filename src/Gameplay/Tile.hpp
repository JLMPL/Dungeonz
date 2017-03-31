#ifndef TILE_HPP
#define TILE_HPP
#include "../Core/Vec2.hpp"
#include "../Core/Rect.hpp"
#include <SFML/Graphics.hpp>

struct Tile
{
    Tile(){}

    sf::Sprite sprite;
    vec2i position;
    Recti rect;
    bool empty = false;
};

#endif