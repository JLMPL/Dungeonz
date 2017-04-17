#include "BossMissile.hpp"
#include "Level.hpp"
#include "Living.hpp"
#include "../Render/AnimatedSprite.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Resource/AnimationCache.hpp"

constexpr int g_bigDamage = 2;
constexpr int g_smallDamage = 1;

BossMissile::BossMissile()
{
    m_sprite = Sprite::Ptr(new Sprite());

    m_box = Box::Ptr(new Box());
    m_box->rect = Rectf(0,0,24,24);
    m_box->type = Box::Type::TriggerVolume;
    m_box->reactMaterial = CollMaterial::Regular | CollMaterial::Living;
    m_box->callback = [this]()
    {
        this->blow(nullptr);
    };
    m_box->enabled = false;

    // CollisionHandler::Get().addBody(m_box);
}

void BossMissile::init(vec2f origin, Direction_t dir, Type type)
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

    switch (m_type)
    {
        case Type::Big:
        {
            m_sprite->loadFromFile("boss_missile.png");
            m_sprite->setOrigin({16,16});
            m_box->rect = Rectf(getPosition().x, getPosition().y, 24,24);
            CollisionHandler::Get().addBody(m_box);
            m_speed = 200;
        }
        break;
        case Type::Small:
        {
            m_sprite->loadFromFile("boss_small.png");
            m_sprite->setOrigin({8,8});
            m_box->rect = Rectf(getPosition().x, getPosition().y, 8,8);
            CollisionHandler::Get().addBody(m_box);
            m_speed = 300;
        }
        break;
    }

    
}

void BossMissile::setOwner(Entity* owner)
{
    m_owner = owner;
}

void BossMissile::update(float deltaTime)
{
    if (m_warmup.getElapsedTime().asMilliseconds() > 175)
        m_box->enabled = true;

    if (m_box->enabled == true)
    {
        float range = 32;
        if (m_type == Type::Small)
            range = 24;

        std::vector<Entity*> foundEnts = m_level->getEntitiesInRange(vec2f(m_box->rect.x + m_box->rect.w/2,
                                         m_box->rect.y + m_box->rect.h/2), range);
        
        for (auto& i : foundEnts)
        {
            blow(i);
        }
    }

    emitTrail();

    vec2f translation(m_velocity * m_speed * deltaTime);
    move(translation);

    if (m_type == Type::Big)
        m_sprite->setPosition(vec2i(m_box->rect.x + 12, m_box->rect.y + 12));
    else
        m_sprite->setPosition(vec2i(m_box->rect.x + 4, m_box->rect.y + 4));
    m_sprite->draw();
}

void BossMissile::emitTrail()
{
    if (m_trailTimer.getElapsedTime().asMilliseconds() > 50)
    {
        m_level->addBigParticle("trail.ani", getFakePos(), vec2i(0,0), 0.3);
        m_trailTimer.restart();
    }
}

void BossMissile::shootOthers()
{
    if (m_type == Type::Big)
    {
        auto ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(0,-1));

        ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(0,1));

        ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(1,0));

        ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(-1,0));

        //diag
        ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(1,1));

        ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(-1,-1));

        ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(1,-1));

        ball = (BossMissile*)m_level->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(this));
        ball->setDirection(vec2f(-1,1));
    }
}

void BossMissile::blow(Entity* ent)
{
    if (ent)
    {
        if (ent != m_owner)
        {
            switch (ent->getType())
            {
                case Entity::Type::Living:
                {
                    auto living = static_cast<Living*>(ent);

                    if (!living->isDead() and living != m_owner and m_speed != 0)
                    {
                        if (m_type == Type::Big)
                            living->damage(g_bigDamage);
                        else
                            living->damage(g_smallDamage);
                        living->push(Direction::deduceDirection(m_velocity), 8, 0.1);

                        m_speed = 0;
                        m_level->addBigParticle("trail.ani", getFakePos(), vec2i(0,0), 0.3);
                        destroy();
                    }
                }
                break;
            }
        }
    }
    else
    {
        m_speed = 0;
        shootOthers();
        m_level->addBigParticle("trail.ani", getFakePos(), vec2i(0,0), 0.3);
        destroy();
    }
}

void BossMissile::setDirection(const vec2f& dir)
{
    m_velocity = normalize(dir);
}
