#include "AiPlayer.hpp"
#include "../Core/Dice.hpp"
#include "../Gameplay/Exit.hpp"
#include "../Gameplay/Door.hpp"
#include "../Gameplay/Level.hpp"
#include "../Gameplay/Arrow.hpp"
#include "../Gameplay/Chest.hpp"
#include "../Gameplay/Lever.hpp"
#include "../Gameplay/Living.hpp"
#include "../Gameplay/ItemBag.hpp"
#include "../Gameplay/LightningBolt.hpp"
#include "../Gui/Gui.hpp"
#include "../Input/InputHandler.hpp"
#include "../Resource/AnimationCache.hpp"
#include "../Render/IndicationHandler.hpp"
#include "../Collision/CollisionAlgorithm.hpp"
#include "../Sound/SoundHandler.hpp"

//*/
#include "../Collision/CollisionHandler.hpp"
#include "../Render/Renderer.hpp"
//*/

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

constexpr int g_fireballCost = 25;
constexpr int g_frostbiteCost = 32;
constexpr int g_speedCost = -99;
constexpr int g_lightningCost = 5;
constexpr int g_healCost = 32;

void AiPlayer::setup()
{
    m_state = State::Moving;

    m_hitPoint.setSize({8,8});
    m_hitPoint.setFillColor({255,0,0});
    m_hitPoint.setOrigin({4,4});
}

void AiPlayer::update(float deltaTime)
{
    m_noclipTimer += 1000 * deltaTime;

    if (InputHandler::Get().isKeyPressed(sf::Keyboard::F1) and
        m_noclipTimer >= 500)
    {
        m_noclip = !m_noclip;
        m_noclipTimer = 0;

        if (m_noclip)
            m_target->disableCollision();
        else
            m_target->enableCollision();
    }

    if (!m_target->isBusy())
    {
        focus();

        switch (m_state)
        {
            case State::Moving:
                movingState(deltaTime);
                break;
            case State::Idle:
                idleState(deltaTime);
                break;
            case State::Attack:
                attackState(deltaTime);
                break;
            case State::Picking:
                pickingState(deltaTime);
                break;
            case State::Casting:
                castState(deltaTime);
                break;
            case State::Rolling:
                rollState(deltaTime);
                break;
            case State::Shoot:
                shootState(deltaTime);
                break;
        }
    }
    else
        m_target->setAnimation(AnimationCache::Get().getAnimation("player_idle.ani"));

    if (m_manaRestoreTimer.getElapsedTime().asSeconds() >= 1)
    {
        m_target->restoreMana(1);
        m_manaRestoreTimer.restart();
    }

    if (m_target->isDead() and !m_target->isBusy())
    {
        GUI::Get().goDead();
        m_target->setBusy(true);
    }

    /*/

    m_ray[0] = sf::Vertex({m_target->getFakePos().getSfVecf()});
    if (m_focus)
        m_ray[1] = sf::Vertex({m_focus->getFakePos().getSfVecf()});
    else
        m_ray[1] = sf::Vertex({m_target->getFakePos().getSfVecf()});

    Renderer::Get().submitLine(m_ray, 2, sf::Lines);

    if (m_focus)
    {
        vec2f pos = CollisionHandler::Get().castRay(m_target->getFakePos().getf(), m_focus->getFakePos().getf());
        m_hitPoint.setPosition(pos.getSfVecf());
        Renderer::Get().submitOverlay(&m_hitPoint);
    }

    //*/
}

void AiPlayer::movingState(float deltaTime)
{
    if (InputHandler::Get().isRun() or m_speedSpellActive)
    {
        m_speed = m_runSpeed;
        if (m_speedSpellTimer.getElapsedTime().asSeconds() >= 30)
            m_speedSpellActive = false;
    }
    else
        m_speed = m_walkSpeed;

    if (InputHandler::Get().isUp())
    {
        m_target->move({0, -deltaTime * m_speed});
        m_target->setDirection(Direction::Up);
    }
    else if (InputHandler::Get().isDown())
    {
        m_target->move({0, deltaTime * m_speed});
        m_target->setDirection(Direction::Down);
    }
    if (InputHandler::Get().isLeft())
    {
        m_target->move({-deltaTime * m_speed, 0});
        m_target->setDirection(Direction::Left);
    }
    else if (InputHandler::Get().isRight())
    {
        m_target->move({deltaTime * m_speed, 0});
        m_target->setDirection(Direction::Right);
    }

    m_target->setAnimation(AnimationCache::Get().getAnimation("player_walk.ani"));

    if (!InputHandler::Get().isAnyKeyPressed())
    {
        m_state = State::Idle;
    }
    else if (InputHandler::Get().isAttack())
    {
        m_state = State::Attack;
    }
    else if (InputHandler::Get().isAction())
    {
        m_state = State::Picking;
    }
    else if (InputHandler::Get().isCast())
    {
        m_state = State::Casting;
    }
    else if (InputHandler::Get().isShoot())
    {
        m_state = State::Shoot;
    }

    if (InputHandler::Get().isRoll())
    {
        m_state = State::Rolling;
    }
}

void AiPlayer::idleState(float deltaTime)
{
    m_target->setAnimation(AnimationCache::Get().getAnimation("player_idle.ani"));

    if (InputHandler::Get().isUp() or
        InputHandler::Get().isDown() or
        InputHandler::Get().isLeft() or
        InputHandler::Get().isRight())
    {
        m_state = State::Moving;
    }
    else if (InputHandler::Get().isAttack())
    {
        m_state = State::Attack;
    }
    else if (InputHandler::Get().isAction())
    {
        m_state = State::Picking;
    }
    else if (InputHandler::Get().isCast())
    {
        m_state = State::Casting;
    }
    else if (InputHandler::Get().isShoot())
    {
        m_state = State::Shoot;
    }
}

void AiPlayer::attackState(float deltaTime)
{
    if (m_timer.getElapsedTime().asMilliseconds() > 300)
    {
        m_target->setAnimation(AnimationCache::Get().getAnimation("player_attack.ani"),
        [&]()
        {
            m_state = State::Moving;
        });

        if (m_focus)
        {
            float dist = length(m_focus->getPosition() - m_target->getPosition());

            if (dist <= 32)
            {
                switch (m_focus->getType())
                {
                    case Entity::Type::Living:
                    {
                        auto living = static_cast<Living*>(m_focus);

                        if (living->getAttribute(Attribute::Hp) > 0)
                        {
                            int damage = m_target->getAttribute(Attribute::Damage);
                            living->damage(damage);
                            living->push(m_target->getDirection(), 5, 0.1);

                            IndicationHandler::Get().addIndication("-" + std::to_string(damage), sf::Color(0,255,0), m_focus->getPosition() + vec2f(0,-50));

                            if (living->getAttribute(Attribute::Hp) <= 0)
                            {
                                m_target->addXp(living->getXp());
                                IndicationHandler::Get().addIndication("+" + std::to_string(living->getXp()) + "xp", sf::Color(0,128,255), m_target->getPosition() + vec2f(0,-35));
                            }
                        }
                        break;
                    }
                }
            }
        }
        m_timer.restart();
    }
    else 
        m_state = State::Idle;
}

void AiPlayer::pickingState(float deltaTime)
{
    if (m_focus and m_timer.getElapsedTime().asMilliseconds() > 150)
    {
        float dist = length(m_focus->getPosition() - m_target->getPosition());

        if (dist <= 48)
        {
            switch (m_focus->getType())
            {
                case Entity::Type::Living:
                {
                    auto living = static_cast<Living*>(m_focus);
                    if (living->getAttribute(Attribute::Hp) <= 0)
                    {
                        if (living->accessInv().getAmount() > 0)
                            GUI::Get().goLoot(&living->accessInv(), living->getPosition().geti());
                        else
                            IndicationHandler::Get().addIndication("empty", sf::Color(255,255,0), living->getPosition() + vec2f(0,-50));
                    }
                }
                break;
                case Entity::Type::Chest:
                {
                    auto chest = static_cast<Chest*>(m_focus);
                    if (chest->isOpen())
                    {
                        if (chest->accessInv().getAmount() > 0)
                            GUI::Get().goLoot(&chest->accessInv(), chest->getPosition().geti());
                        else
                            IndicationHandler::Get().addIndication("empty", sf::Color(255,255,0), chest->getPosition() + vec2f(0,-50));
                    }
                    else
                        chest->tryOpening(&m_target->accessInv());
                }
                break;
                case Entity::Type::Door:
                {
                    auto door = static_cast<Door*>(m_focus);
                    door->tryOpening(&m_target->accessInv());
                }
                break;
                case Entity::Type::Lever:
                {
                    auto lever = static_cast<Lever*>(m_focus);
                    lever->activate();
                }
                break;
                case Entity::Type::ItemBag:
                {
                    auto bag = static_cast<ItemBag*>(m_focus);
                    if (bag->accessInv().getAmount() > 1)
                    {
                        GUI::Get().goLoot(&bag->accessInv(), bag->getPosition().geti());
                    }
                    else
                    {
                        const Item::Ptr& item = bag->accessInv().getItem(0);
                        m_target->accessInv().addItem(item);
                        bag->accessInv().removeItem(item->code);
                    }
                }
                break;
                case Entity::Type::Exit:
                {
                    auto exit = static_cast<Exit*>(m_focus);
                    exit->goFurther();
                }
                break;
            }
        }
        m_timer.restart();
    }
    m_state = State::Moving;
}

void AiPlayer::rollState(float deltaTime)
{
    switch (m_target->getDirection())
    {
        case Direction::Up:
            m_target->move(vec2f(0, -m_runSpeed * deltaTime));
            break;
        case Direction::Down:
            m_target->move(vec2f(0, m_runSpeed * deltaTime));
            break;
        case Direction::Left:
            m_target->move(vec2f(-m_runSpeed * deltaTime, 0));
            break;
        case Direction::Right:
            m_target->move(vec2f(m_runSpeed * deltaTime, 0));
            break;
    }

    m_target->setAnimation(AnimationCache::Get().getAnimation("player_roll.ani"),
    [&]()
    {
        m_state = State::Idle;
        m_timer.restart();
    });
}

void AiPlayer::castState(float deltaTime)
{
    if (InputHandler::Get().isCast() and m_timer.getElapsedTime().asSeconds() > 0.3)
    {
        switch (m_target->getReadySpell())
        {
            case Spell::Fireball:
                castFireball();
                break;
            case Spell::Frostbite:
                castFrostbite();
                break;
            // case Spell::Speed:
            //     castSpeed();
            //     break;
            case Spell::Lightning:
                castLightning(deltaTime);
                break;
            case Spell::Heal:
                castHeal();
                break;

            default:break;
        }
    }
    else
        m_state = State::Idle;
}

void AiPlayer::shootState(float deltaTime)
{
    if (m_timer.getElapsedTime().asMilliseconds() >= 500 and
        m_target->getEquippedItem(Equip::Bow) and
        m_target->accessInv().hasItem("it_arrow"))
    {
        auto arrow = m_target->getLevel()->addArrow(std::shared_ptr<Arrow>(new Arrow()));
        arrow->init(m_target->getFakePos().getf(), m_target->getDirection());
        arrow->setOwner(static_cast<Entity*>(m_target));

        m_target->accessInv().removeItem("it_arrow");

        m_target->setAnimation(AnimationCache::Get().getAnimation("player_shoot.ani"),
        [&]()
        {
            m_state = State::Idle;
        });

        m_timer.restart();
    }
    else
        m_state = State::Idle;
}

void AiPlayer::castFireball()
{
    if (m_target->getAttribute(Attribute::Mp) >= g_fireballCost)
    {
        auto ball = (FireMissile*)m_target->getLevel()->addFireMissile(std::shared_ptr<FireMissile>(new FireMissile()));
        ball->init(m_target->getPosition(), m_target->getDirection(), Entity::Type::Fireball);
        ball->setOwner(static_cast<Entity*>(m_target));

        m_target->drainMana(g_fireballCost);
        m_target->setAnimation(AnimationCache::Get().getAnimation("player_cast.ani"),
        [&]()
        {
            m_state = State::Idle;
        });

        SoundHandler::Get().playSound(SoundEffect::SpellEffect);

        m_timer.restart();
    }
}

void AiPlayer::castFrostbite()
{
    if (m_target->getAttribute(Attribute::Mp) >= g_frostbiteCost)
    {
        auto ball = (IceMissile*)m_target->getLevel()->addIceMissile(std::shared_ptr<IceMissile>(new IceMissile()));
        ball->init(m_target->getPosition(), m_target->getDirection(), Entity::Type::Fireball);
        ball->setOwner(static_cast<Entity*>(m_target));

        m_target->drainMana(g_frostbiteCost);
        m_target->setAnimation(AnimationCache::Get().getAnimation("player_cast.ani"),
        [&]()
        {
            m_state = State::Idle;
        });

        SoundHandler::Get().playSound(SoundEffect::SpellEffect);

        m_timer.restart();
    }
}

void AiPlayer::castLightning(float deltaTime)
{
    if (m_focus and
        m_focus->getType() == Entity::Type::Living and
        m_target->getAttribute(Attribute::Mp) >= g_lightningCost)
    {
        auto bolt = m_target->getLevel()->addLightningBolt(std::shared_ptr<LightningBolt>(new LightningBolt()));
        bolt->init(m_target->getFakePos().getf() + vec2f(0,-20),
                   m_focus->getFakePos().getf() + vec2f(0,-20));

        m_target->setAnimation(AnimationCache::Get().getAnimation("player_cast.ani"));

        Living* focal = static_cast<Living*>(m_focus);
        focal->damage(8);
        focal->push(m_target->getDirection(), 5, 0.1);

        m_target->drainMana(g_lightningCost);

        m_timer.restart();
    }
}

void AiPlayer::castSpeed()
{
    if (m_target->getAttribute(Attribute::Mp) >= g_speedCost and !m_speedSpellActive)
    {
        m_speedSpellActive = true;
        m_speedSpellTimer.restart();

        m_target->drainMana(g_speedCost);

        m_target->getLevel()->addBigParticle("magic_works.ani", m_target->getFakePos(), vec2i(0, -20), 0.150);
        IndicationHandler::Get().addIndication("Speed", sf::Color(0,192,255), vec2f(m_target->getFakePos()) + vec2f(0, -40));

        SoundHandler::Get().playSound(SoundEffect::SpellEffect);

        m_timer.restart();
    }
}

void AiPlayer::castHeal()
{
    if (m_target->getAttribute(Attribute::Mp) >= g_healCost)
    {
        m_target->restoreHealth(12);
        m_target->drainMana(g_healCost);
        m_target->getLevel()->addBigParticle("magic_works.ani", m_target->getFakePos(), vec2i(0, -20), 0.150);

        IndicationHandler::Get().addIndication("Heal", sf::Color(0,192,255), vec2f(m_target->getFakePos()) + vec2f(0, -40));
        SoundHandler::Get().playSound(SoundEffect::SpellEffect);

        m_timer.restart();
    }
}

void AiPlayer::focus()
{
    auto ents = m_target->getLevel()->getEntitiesInRange(m_target->getPosition(), 96);
    m_focus = nullptr;

    if (!ents.empty())
    {
        for (auto i = ents.begin(); i != ents.end();)
        {
            vec2f cast = CollisionHandler::Get().castRay(m_target->getFakePos().getf(), (*i)->getFakePos().getf());
            Direction_t dire = Direction::deduceDirection(normalize((*i)->getFakePos().getf() - m_target->getFakePos().getf()));

            if ((*i)->getType() == Entity::Type::SpikeTrap or
                (*i)->getType() == Entity::Type::PressPlate)
            {
                i = ents.erase(i);
            }
            else if (cast != Collision::infVec and
                    (*i)->getType() != Entity::Type::Door and
                    (*i)->getType() != Entity::Type::Chest and
                    (*i)->getType() != Entity::Type::Exit)
            {
                i = ents.erase(i);
            }
            else if (dire != m_target->getDirection())
            {
                i = ents.erase(i);
            }
            else if ((*i)->getType() == Entity::Type::Living)
            {
                auto one = static_cast<Living*>(*i);
                if (one->isDead() and one->accessInv().getAmount() == 0)
                {
                    i = ents.erase(i);
                }
                else i++;
            }
            else
                i++;
        }

        Entity* theent = nullptr;
        for (std::size_t i = 0; i < ents.size(); i++)
        {
            if (theent == nullptr)
                theent = ents[i];
            else
            {
                float dista = length(theent->getPosition() - m_target->getPosition());
                float distb = length(ents[i]->getPosition() - m_target->getPosition());

                if (distb < dista)
                {
                    theent = ents[i];
                }
            }
        }

        m_focus = theent;

        // if (ents.size() > 1)
        // {
        //     std::sort(begin(ents), end(ents),
        //     [&](Entity* a, Entity* b)
        //     {
        //         float dista = length(a->getPosition() - m_target->getPosition());
        //         float distb = length(b->getPosition() - m_target->getPosition());

        //         return dista < distb;
        //     });

        //     m_focus = ents[0];
        // }
    }
    else
        m_focus = nullptr;

    if (m_focus)
    {
        switch (m_focus->getType())
        {
            case Entity::Type::Living:
            {
                auto focal = static_cast<Living*>(m_focus);
                std::string name = focal->getProfile().name;
                vec2i pos = vec2i(m_focus->getFakePos().x, m_focus->getFakePos().y - 40);
                GUI::Get().setFocusLabel(name, pos);
                GUI::Get().showFocusHealthbar(focal->getAttribute(Attribute::Hp),
                                              focal->getAttribute(Attribute::Health),
                                              pos);
            }
            break;
            case Entity::Type::Chest:
            {
                vec2i pos = vec2i(m_focus->getFakePos().x, m_focus->getFakePos().y - 40);
                GUI::Get().setFocusLabel("Chest", pos);
            }
            break;
            case Entity::Type::Door:
            {
                vec2i pos = vec2i(m_focus->getFakePos().x, m_focus->getFakePos().y - 40);
                GUI::Get().setFocusLabel("Door", pos);
            }
            break;
            case Entity::Type::Lever:
            {
                vec2i pos = vec2i(m_focus->getPosition().x, m_focus->getPosition().y - 40);
                GUI::Get().setFocusLabel("Lever", pos);
            }
            break;
            case Entity::Type::ItemBag:
            {
                vec2i pos = vec2i(m_focus->getPosition().x, m_focus->getPosition().y - 40);
                GUI::Get().setFocusLabel("Bag", pos);
            }
            break;
            case Entity::Type::Exit:
            {
                auto exit = static_cast<Exit*>(m_focus);
                vec2i pos = vec2i(m_focus->getFakePos().x, m_focus->getFakePos().y - 40);
                GUI::Get().setFocusLabel("Next Level", pos);
            }
            break;
        }
    }
}

AiPlayer::State AiPlayer::getState()
{
    return m_state;
}
