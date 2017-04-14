#include "AiBoss.hpp"
#include "../Gameplay/Living.hpp"
#include "../Gameplay/Level.hpp"
#include "../Resource/AnimationCache.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Collision/CollisionAlgorithm.hpp"

void AiBoss::setup()
{
    m_state = MobState::Idle;
    m_target->setDirection(Direction::Up);
}

void AiBoss::focus()
{
    m_focus = nullptr;
    auto ents = m_target->getLevel()->getEntitiesInRange(m_target->getPosition(), 1000);

    for (auto i = ents.begin(); i != ents.end();)
    {
        if ((*i)->getCode() != "pc_player")
        {
            i = ents.erase(i);
        }
        else
            i++;
    }

    if (ents.size() > 0)
    {
        if (ents.size() > 1)
        std::sort(begin(ents), end(ents),
        [&](Entity* a, Entity* b)
        {
            float dist_a = length(a->getPosition() - m_target->getPosition());
            float dist_b = length(b->getPosition() - m_target->getPosition());

            return dist_a < dist_b;
        });

        m_focus = ents[0];
    }
}

void AiBoss::update(float deltaTime)
{
    if (!m_target->isBusy())
    {
        focus();
        
        switch (m_state)
        {
            case MobState::Idle:
                idleState(deltaTime);
                break;
            case MobState::Move:
                moveState(deltaTime);
                break;
            case MobState::Attack:
                attackState(deltaTime);
                break;
            case MobState::Dead:
                deadState(deltaTime);
                break;
        }
    }
}

void AiBoss::idleState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_focus)
        {
            if (distance(m_target->getPosition(), m_focus->getPosition()) > 256)
            {
                m_state = MobState::Move;
            }
            else if (distance(m_target->getPosition(), m_focus->getPosition()) < 75)
            {
                fuckEmUp();
            }
            else 
                m_state = MobState::Attack;
        }
    }
    else
        m_state = MobState::Dead;

    m_target->setAnimation(AnimationCache::Get().getAnimation("boss_idle.ani"));
}

void AiBoss::moveState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_focus)
        {
            vec2f fromThePlayer = m_focus->getPosition() - m_target->getPosition();
            fromThePlayer = normalize(fromThePlayer);

            m_direction = m_focus->getPosition() - m_target->getPosition();
            m_direction = normalize(m_direction);

            m_target->move(m_direction * m_speed * deltaTime);
            m_target->setAnimation(AnimationCache::Get().getAnimation("boss_walk.ani"));

            if (distance(m_target->getPosition(), m_focus->getPosition()) > 100)
            {
                m_state = MobState::Idle;
            }
        }
        else
            m_state = MobState::Idle;
    }
    else
        m_state = MobState::Dead;
}

void AiBoss::attackState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_timer.getElapsedTime().asMilliseconds() > 1750)
        {
            auto ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
            ball->init(m_target->getPosition(), m_target->getDirection(), BossMissile::Type::Big);
            ball->setOwner(static_cast<Entity*>(m_target));
            ball->setDirection(normalize(m_focus->getPosition() - m_target->getPosition()));

            m_target->setAnimation(AnimationCache::Get().getAnimation("boss_attack.ani"),
            [&]()
            {
                m_state = MobState::Idle;
                m_target->setAnimation(AnimationCache::Get().getAnimation("boss_idle.ani"));
            });
            m_timer.restart();
        }
        else
            m_state = MobState::Idle;
    }
    else
        m_state = MobState::Dead;
}

void AiBoss::fuckEmUp()
{
    if (m_timer.getElapsedTime().asMilliseconds() > 200)
    {
        auto ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(0,-1));

        ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(0,1));

        ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(1,0));

        ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(-1,0));

        //diag
        ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(1,1));

        ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(-1,-1));

        ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(1,-1));

        ball = (BossMissile*)m_target->getLevel()->addBossMissile(std::shared_ptr<BossMissile>(new BossMissile()));
        ball->init(m_target->getPosition(), Direction::Up, BossMissile::Type::Small);
        ball->setOwner(static_cast<Entity*>(m_target));
        ball->setDirection(vec2f(-1,1));

        m_timer.restart();
    }
}

void AiBoss::deadState(float deltaTime)
{
    m_target->setDirection(Direction::Up);
    m_target->setAnimation(AnimationCache::Get().getAnimation("boss_dead.ani"));
}
