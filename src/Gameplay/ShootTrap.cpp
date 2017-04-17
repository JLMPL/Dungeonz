#include "ShootTrap.hpp"
#include "Level.hpp"
#include "Arrow.hpp"

ShootTrap::ShootTrap(Direction_t dir)
{
    m_type = Entity::Type::ShootTrap;

    m_sprite = Sprite::Ptr(new Sprite());
    m_sprite->loadFromFile("shoot_trap.png");
    m_sprite->setOrigin({0,0});
    m_sprite->setRect({0,0,32,32});

    m_box = Box::Ptr(new Box());
    m_box->rect = Rectf(0,0,32,32);
    // m_box->type = Box::Type::TriggerVolume;
    // m_box->material = CollMaterial::Trap;
    // m_box->reactMaterial = CollMaterial::Living;
    // m_box->callback = [this]()
    // {
    //     this->activate();
    // };

    // CollisionHandler::Get().addBody(m_box);

    m_aim = dir;
}

void ShootTrap::update(float deltaTime)
{
    if (m_enabled and m_shootTimer.getElapsedTime() > sf::seconds(1.f))
    {
        auto arrow = m_level->addArrow(std::shared_ptr<Arrow>(new Arrow()));
        arrow->init(getFakePos().getf(), m_aim);
        arrow->setDamage(5u);
        arrow->setDecay(1.7f);
        arrow->setOwner(static_cast<Entity*>(this));

        m_shootTimer.restart();
    }

    m_sprite->setPosition({m_box->rect.x, m_box->rect.y});
    m_sprite->draw();
}

void ShootTrap::enable()
{
    m_enabled = true;
}

void ShootTrap::disable()
{
    m_enabled = false;
}
