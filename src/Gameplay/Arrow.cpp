#include "Arrow.hpp"

Arrow::Arrow()
{
    m_sprite = SpritePtr_t(new Sprite());
    m_sprite->loadFromFile("arrow.png");
    m_sprite->setOrigin({12,12});

    m_box = BoxPtr_t(new Box());
    m_box->type = CollisionType::TriggerVolume;
    m_box->reactMaterial = CollMaterial::Regular | CollMaterial::Living;
    m_box->callback = [this]()
    {
        this->blow(nullptr);
    };
    m_box->enabled = false;

    CollisionHandler::Get().addBody(m_box);
}

void Arrow::init(const vec2f& pos, Direction_t dir)
{
    if (dir == Direction::Up or dir == Direction::Down)
        m_box->rect = Rectf(0,0,4,24);
    else
        m_box->rect = Rectf(0,0,24,8);

    switch (dir)
    {
        case Direction::Up:
            m_velocity = vec2f(0,-1);
            break;
        case Direction::Down:
            m_velocity = vec2f(0,1);
            break;
        case Direction::Left:
            m_velocity = vec2f(-1,0);
            break;
        case Direction::Right:
            m_velocity = vec2f(1,0);
            break;
    }
}

void Arrow::update(float deltaTime)
{
    vec2f translation(m_velocity * m_speed * deltaTime);
    move(translation);

    m_sprite->setPosition(vec2i(m_box->rect.x + m_box->rect.w/2, m_box->rect.y - 12));
    m_sprite->draw();
}

void Arrow::setOwner(Entity* owner)
{
    m_owner = owner;
}
