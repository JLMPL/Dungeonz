#include "FireMissile.hpp"
#include "Level.hpp"
#include "Living.hpp"
#include "../Render/AnimatedSprite.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Resource/AnimationCache.hpp"

FireMissile::FireMissile()
{
    m_sprite = SpritePtr_t(new AnimatedSprite());
    m_sprite->loadFromFile("fajerbol.ani");
    m_sprite->setOrigin({12,12});

    m_box = Box::Ptr(new Box());
    m_box->rect = Rectf(0,0,8,8);
    m_box->type = Box::Type::TriggerVolume;
    m_box->reactMaterial = CollMaterial::Regular | CollMaterial::Living;
    m_box->callback = [this]()
    {
        this->blow(nullptr);
    };
    m_box->enabled = false;

    CollisionHandler::Get().addBody(m_box);
}

void FireMissile::init(vec2f origin, Direction_t dir, Entity::Type type)
{
    m_type = type;
    m_direction = dir;
    m_box->rect.x = origin.x;
    m_box->rect.y = origin.y;

    switch (m_direction)
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

void FireMissile::setOwner(Entity* owner)
{
    m_owner = owner;
}

void FireMissile::update(float deltaTime)
{
    if (m_warmup.getElapsedTime().asSeconds() > 0.2)
        m_box->enabled = true;

    if (m_box->enabled == true)
    {
        std::vector<Entity*> foundEnts = m_level->getEntitiesInRange(vec2f(m_box->rect.x + m_box->rect.w/2,
                                         m_box->rect.y + m_box->rect.h/2), 24);
        
        for (auto& i : foundEnts)
        {
            blow(i);
        }
    }

    vec2f translation(m_velocity * m_speed * deltaTime);
    move(translation);

    m_sprite->setPosition(vec2i(m_box->rect.x + m_box->rect.w/2, m_box->rect.y - 12));
    m_sprite->update(deltaTime);
}

void FireMissile::blow(Entity* ent)
{
    if (ent)
    {
        switch (ent->getType())
        {
            case Entity::Type::Living:
            {
                auto living = static_cast<Living*>(ent);

                if (!living->isDead() and living != m_owner and m_speed != 0)
                {
                    auto beholder = static_cast<Living*>(m_owner);

                    living->damage(20);
                    living->push(m_direction, 8, 0.1);

                    if (living->isDead())
                    {
                        beholder->addXp(living->getXp());
                    }

                    m_speed = 0;
                    m_sprite->setAnimation(AnimationCache::Get().getAnimation("fajerbol_explosion.ani"),
                    [this]()
                    {
                        destroy();
                    });
                }
            }
            break;
        }
    }
    else
    {
        m_speed = 0;
        m_sprite->setAnimation(AnimationCache::Get().getAnimation("fajerbol_explosion.ani"),
        [this]()
        {
            destroy();
        });
    }
}

void FireMissile::setDirection(const vec2f& dir)
{
    m_velocity = dir;
}