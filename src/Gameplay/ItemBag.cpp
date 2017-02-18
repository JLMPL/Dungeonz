#include "ItemBag.hpp"
#include "../Collision/CollisionHandler.hpp"

ItemBag::ItemBag()
{
	m_type = EntityType::ITEM_BAG;
	m_sprite = SpritePtr_t(new Sprite());
	m_sprite->loadFromFile("data/bag.png");
	m_sprite->setOrigin({8,16});

	m_box = BoxPtr_t(new Box());
	m_box->rect = Rectf(0,0,4,4);
	m_box->type = CollisionType::DYNAMIC;

	CollisionHandler::Get().addBody(m_box);
}

void ItemBag::update(float deltaTime)
{
	Chest::update(deltaTime);

	if(m_inv.getAmount() <= 0)
	{
		m_destroy = true;
	}
}