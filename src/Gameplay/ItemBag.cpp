#include "ItemBag.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Render/Renderer.hpp"

ItemBag::ItemBag()
{
    m_type = Entity::Type::ItemBag;
    m_sprite = Sprite::Ptr(new Sprite());
    m_sprite->loadFromFile("bag.png");
    m_sprite->setOrigin({8,16});

    m_box = Box::Ptr(new Box());
    m_box->rect = Rectf(0,0,4,4);
    m_box->type = Box::Type::Dynamic;

    CollisionHandler::Get().addBody(m_box);

    m_shadow = sf::CircleShape(7);
    m_shadow.setFillColor({0,0,0,64});
    m_shadow.setOrigin({7,7});
    m_shadow.setScale({1,0.5});
}

void ItemBag::update(float deltaTime)
{
    Chest::update(deltaTime);

    m_shadow.setPosition({m_box->rect.x + m_box->rect.w /2, m_box->rect.y + m_box->rect.h /2 + 2});
    Renderer::Get().submitBackground(&m_shadow);

    if (m_inv.getAmount() <= 0)
    {
        m_destroy = true;
    }
}