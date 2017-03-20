#include "PressPlate.hpp"
#include "Door.hpp"
#include "SpikeTrap.hpp"
#include "../Collision/CollisionHandler.hpp"

PressPlate::PressPlate()
{
    m_type = EntityType::PressPlate;

    m_sprite = SpritePtr_t(new Sprite());
    m_sprite->loadFromFile("press_plate.png");
    m_sprite->setOrigin({0,0});
    m_sprite->setRect({0,0,32,32});

    m_box = BoxPtr_t(new Box());
    m_box->rect = Rectf(0,0,32,32);
    m_box->type = CollisionType::TriggerVolume;
    m_box->reactMaterial = CollMaterial::Living;
    m_box->callback = [this]()
    {
        activate();
    };

    CollisionHandler::Get().addBody(m_box);
}

void PressPlate::update(float deltaTime)
{
    if (m_timer.getElapsedTime().asSeconds() >= 5 and m_active)
    {
        deactivate();
    }

    m_sprite->setPosition({m_box->rect.x, m_box->rect.y});
    m_sprite->draw();
}

void PressPlate::activate()
{
    m_active = true;
    m_timer.restart();
    m_activateFunc();
    m_sprite->setRect({32,0,32,32});
}

void PressPlate::deactivate()
{
    m_active = false;
    m_deactivateFunc();
    m_sprite->setRect({0,0,32,32});
}

void PressPlate::setActivateFunc(std::function<void ()> func)
{
    m_activateFunc = func;
}

void PressPlate::setDeactivateFunc(std::function<void ()> func)
{
    m_deactivateFunc = func;
}
