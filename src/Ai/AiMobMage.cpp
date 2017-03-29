#include "AiMobMage.hpp"
#include "../Gameplay/Living.hpp"
#include "../Gameplay/Level.hpp"
#include "../Resource/AnimationCache.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Collision/CollisionAlgorithm.hpp"

void AiMobMage::setup()
{
    m_state = MobState::Idle;
    m_target->setDirection(Direction::Down);
}

void AiMobMage::focus()
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
            float dist_a = length(a->getPosition() - m_target->getPosition());
            float dist_b = length(b->getPosition() - m_target->getPosition());

            return dist_a < dist_b;
        });

        m_focus = ents[0];
    }
}

void AiMobMage::update(float deltaTime)
{
    if (!m_target->isBusy())
    {
        focus();
        
        switch (m_state)
        {
            case MobState::Idle:
                idleState(deltaTime);
                break;
            case MobState::Flee:
                fleeState(deltaTime, false);
                break;
            case MobState::Move:
                fleeState(deltaTime, true);
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

void AiMobMage::idleState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_focus)
        {
            if (distance(m_target->getPosition(), m_focus->getPosition()) < 64)
            {
                m_state = MobState::Flee;
            }
            else if (distance(m_target->getPosition(), m_focus->getPosition()) > 150)
            {
                m_state = MobState::Move;
            }
            else 
                m_state = MobState::Attack;
        }
    }
    else
        m_state = MobState::Dead;

    m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_idle.ani"));
}

void AiMobMage::fleeState(float deltaTime, bool forward)
{
    if (!m_target->isDead())
    {
        if (m_focus)
        {
            vec2f fromThePlayer = m_focus->getPosition() - m_target->getPosition();
            fromThePlayer = normalize(fromThePlayer);

            if (forward)
                m_direction = m_focus->getPosition() - m_target->getPosition();
            else
                m_direction = m_target->getPosition() - m_focus->getPosition();

            m_direction = normalize(m_direction);

            m_target->setDirection(Direction::deduceDirection(fromThePlayer));
            m_target->move(m_direction * m_speed * deltaTime);
            m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_walk.ani"));

            if (distance(m_target->getPosition(), m_focus->getPosition()) > 96)
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

void AiMobMage::attackState(float deltaTime)
{
    if (!m_target->isDead())
    {
        if (m_timer.getElapsedTime().asMilliseconds() > 1000)
        {
            // auto enemy = static_cast<Living*>(m_focus);
            // enemy->damage(m_target->getAttribute(Attribute::Damage));
            // enemy->push(m_target->getDirection(), 5, 0.1);

            auto ball = (FireMissile*)m_target->getLevel()->addFireMissile(std::shared_ptr<FireMissile>(new FireMissile()));
            ball->init(m_target->getPosition(), m_target->getDirection(), EntityType::Fireball);
            ball->setOwner(static_cast<Entity*>(m_target));
            ball->setDirection(normalize(m_focus->getPosition() - m_target->getPosition()));

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

void AiMobMage::deadState(float deltaTime)
{
    m_target->setDirection(Direction::Up);
    m_target->setAnimation(AnimationCache::Get().getAnimation(m_target->getProfile().apperance + "_dead.ani"));
}
