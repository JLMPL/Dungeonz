#include "AiMob.hpp"
#include "../Gameplay/Living.hpp"
#include "../Gameplay/Level.hpp"
#include "../Resource/AnimationCache.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Collision/CollisionAlgorithm.hpp"

void AiMob::setup()
{
    m_state = MobState::Idle;
    m_target->setDirection(Direction::Down);
}

void AiMob::focus()
{
    m_focus = nullptr;
    auto ents = m_target->getLevel()->getEntitiesInRange(m_target->getPosition(), 200);

    for (auto i = ents.begin(); i != ents.end();)
    {
        if ((*i)->getCode() != "pc_player")
        {
            i = ents.erase(i);
        }
        else if (CollisionHandler::Get().castRay(m_target->getFakePos().getf(), (*i)->getFakePos().getf()) != Collision::infVec)
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
            float dist_a = lengthSqr(a->getPosition() - m_target->getPosition());
            float dist_b = lengthSqr(b->getPosition() - m_target->getPosition());

            return dist_a < dist_b;
        });

        m_focus = ents[0];
    }
}

void AiMob::update(float deltaTime)
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

void AiMob::idleState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_focus)
        {
            if (distance(m_target->getPosition(), m_focus->getPosition()) < 28)
            {
                m_state = MobState::Attack;
            }
            else 
                m_state = MobState::Move;
        }
    }
    else
        m_state = MobState::Dead;
    
    m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_idle.ani"));
}

void AiMob::moveState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_focus)
        {
            m_direction = m_focus->getPosition() - m_target->getPosition();
            m_direction = normalize(m_direction);

            m_target->setDirection(Direction::deduceDirection(m_direction));
            m_target->move(m_direction * m_speed * deltaTime);
            m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_walk.ani"));

            if (distance(m_target->getPosition(), m_focus->getPosition()) < 28)
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

void AiMob::attackState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_timer.getElapsedTime().asMilliseconds() > 1000)
        {
            auto enemy = static_cast<Living*>(m_focus);
            enemy->damage(m_target->getAttribute(Attribute::Damage));
            enemy->push(m_target->getDirection(), 5, 0.1);
            m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_attack.ani"),
            [&]()
            {
                m_state = MobState::Idle;
                m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_idle.ani"));
            });
            m_timer.restart();
        }
        else
            m_state = MobState::Idle;
    }
    else
        m_state = MobState::Dead;
}

void AiMob::deadState(float deltaTime)
{
    m_target->setDirection(Direction::Up);
    m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_dead.ani"));
}
