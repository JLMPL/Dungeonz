#ifndef SLOT_HPP
#define SLOT_HPP
#include "../Gameplay/ItemPtr.hpp"
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct Slot
{
    sf::RectangleShape rect;
    sf::Sprite sprite;
    Item* item;
    bool empty = true;

    Slot();

    void mark();
    void unmark();

    void setPosition(const vec2i& pos);
    void setItem(Item* itmw);
};

#endif