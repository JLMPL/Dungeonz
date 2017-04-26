#include "Lever.hpp"
#include "../Collision/CollisionHandler.hpp"

Lever::Lever()
{
    m_type = Entity::Type::Lever;

    m_sprite = Sprite::Ptr(new Sprite());
    m_sprite->loadFromFile("test_lever.png");
    m_sprite->setOrigin({16,32});
    m_sprite->setRect({0,0,32,32});

    m_box = Box::Ptr(new Box());
    m_box->rect = Rectf(0,0,0,0);
    m_box->type = Box::Type::Static;
    m_box->enabled = false;

    CollisionHandler::Get().addBody(m_box);
}

void Lever::update(float deltaTime)
{
    m_sprite->setPosition({m_box->rect.x, m_box->rect.y});
    m_sprite->draw();
}

void Lever::activate()
{
    m_sprite->setRect({32,0,32,32});
    m_func();
}

void Lever::setActivateFunc(std::function<void ()> func)
{
    m_func = func;
}
