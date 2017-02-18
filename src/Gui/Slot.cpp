#include "Slot.hpp"
#include "../Resource/TextureCache.hpp"

Slot::Slot()
{
	rect = sf::RectangleShape({32,32});
	rect.setOutlineThickness(-1);
	unmark();
	rect.setFillColor({0x20,0x20,0x20});
}

void Slot::mark()
{
	rect.setOutlineColor({0x00,0x00,0xc0});
}

void Slot::unmark()
{
	rect.setOutlineColor({0x40,0x40,0x40});
}

void Slot::setPosition(const vec2i& pos)
{
	rect.setPosition(pos.getSfVecf());
	sprite.setPosition(pos.getSfVecf());
}

void Slot::setItem(Item* itmw)
{
	item = itmw;
	sprite.setTexture(*TextureCache::Get().getTexture(item->image));
	empty = false;
}
