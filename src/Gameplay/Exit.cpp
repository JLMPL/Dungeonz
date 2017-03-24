#include "Exit.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Gui/Gui.hpp"

Exit::Exit()
{
    m_type = EntityType::Exit;

    m_sprite = SpritePtr_t(new Sprite());
    m_sprite->loadFromFile("exit_door.png");
    m_sprite->setOrigin({16,32});

    m_box = BoxPtr_t(new Box());
    m_box->rect = Rectf(0,0,32,4);
    m_box->type = CollisionType::Static;
    m_box->enabled = true;
    // m_box->material = CollMaterial::Regular;
    // m_box->reactMaterial = CollMaterial::Living;
    // m_box->callback = [this]()
    // {
    //  // this->goFurther();
    //  printf("Yeszzdfaz!\n");
    // };

    CollisionHandler::Get().addBody(m_box);
}

void Exit::update(float deltaTime)
{
    m_sprite->setPosition({m_box->rect.x + m_box->rect.w/2, m_box->rect.y});
    m_sprite->draw();
}

void Exit::setNext(const std::string& next)
{
    m_next = next;
}

const std::string& Exit::getNext() const
{
    return m_next;
}

void Exit::setFunc(std::function<void ()> func)
{
    m_exit = func;  
}

void Exit::goFurther()
{
    GUI::Get().begForLevel(m_next);
}