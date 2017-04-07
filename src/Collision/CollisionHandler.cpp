#include "CollisionHandler.hpp"
#include "CollisionAlgorithm.hpp"
#include <SFML/Window/Keyboard.hpp>

constexpr float g_push = 0.02;

void CollisionHandler::init()
{
}

void CollisionHandler::update(float deltaTime)
{
    clean();

    if (m_bodies.size() > 1)
    for (int i = 0; i < m_bodies.size() - 1; i++)
    {
        for (int j = i + 1; j < m_bodies.size(); j++)
        {
            auto& a = *m_bodies[i];
            auto& b = *m_bodies[j];

            if (a.enabled and b.enabled)
            {
                //DYNAMIC DYNAMIC
                if (a.type == CollisionType::Dynamic and b.type == CollisionType::Dynamic)
                {
                    if (Collision::AABBOverlap(a.rect, b.rect))
                    {
                        vec2f move;
                        Collision::AABBResponse(a.rect, b.rect, move);
                        if (move.y == 0)
                        {
                            a.rect.x += move.x * 0.5 + g_push;
                            b.rect.x -= move.x * 0.5 + g_push;
                        }
                        else
                        {
                            a.rect.y += move.y * 0.5 + g_push;
                            b.rect.y -= move.y * 0.5 + g_push;
                        }
                        react(m_bodies[i], m_bodies[j]);
                    }
                }

                //DYNAMIC STATIC
                else if (a.type == CollisionType::Dynamic and b.type == CollisionType::Static)
                {
                    if (Collision::AABBOverlap(a.rect, b.rect))
                    {
                        vec2f move;
                        Collision::AABBResponse(a.rect, b.rect, move);
                        (move.y == 0) ? a.rect.x += move.x + g_push : a.rect.y += move.y + g_push;
                        react(m_bodies[i], m_bodies[j]);
                    }
                }
                else if (a.type == CollisionType::Static and b.type == CollisionType::Dynamic)
                {
                    if (Collision::AABBOverlap(a.rect, b.rect))
                    {
                        vec2f move;
                        Collision::AABBResponse(b.rect, a.rect, move);

                        (move.y == 0) ? b.rect.x += move.x + g_push : b.rect.y += move.y + g_push;
                        react(m_bodies[i], m_bodies[j]);
                    }
                }

                //TRIGGER DYNAMIC
                else if (a.type == CollisionType::TriggerVolume and b.type == CollisionType::Dynamic)
                {
                    if (Collision::AABBOverlap(a.rect, b.rect))
                    {
                        react(m_bodies[i], m_bodies[j]);
                    }
                }
                else if (b.type == CollisionType::TriggerVolume and a.type == CollisionType::Dynamic)
                {
                    if (Collision::AABBOverlap(a.rect, b.rect))
                    {
                        react(m_bodies[i], m_bodies[j]);
                    }
                }

                //TRIGGER STATIC
                else if (a.type == CollisionType::TriggerVolume and b.type == CollisionType::Static)
                {
                    if (Collision::AABBOverlap(a.rect, b.rect))
                    {
                        react(m_bodies[i], m_bodies[j]);
                    }
                }
                else if (b.type == CollisionType::TriggerVolume and a.type == CollisionType::Static)
                {
                    if (Collision::AABBOverlap(a.rect, b.rect))
                    {
                        react(m_bodies[i], m_bodies[j]);
                    }
                }
            }
        }
    }

    //*/
    for (int i = 0; i < m_bodies.size(); i++)
    {
        m_bodies[i]->draw();
    }
    //*/
}

void CollisionHandler::addBody(BoxPtr_t box)
{
    m_bodies.push_back(box);
}

vec2f CollisionHandler::castRay(vec2f origin, vec2f end)
{
    if (!m_bodies.empty())
    {
        std::vector<vec2f> results;
        for (std::size_t i = 0; i < m_bodies.size(); i++)
        {
            if (m_bodies[i]->type == CollisionType::Static)
                results.push_back(Collision::lineVsRect(origin, end, m_bodies[i]->rect));
        }

        for (auto i = results.begin(); i != results.end();)
        {
            if ((*i).x == Collision::inf)
                i = results.erase(i);
            else
                i++;
        }

        std::sort(results.begin(), results.end(),
        [&](vec2f& a, vec2f& b)
        {
            vec2f sub = a - origin;
            float dist0 = sub.x * sub.x + sub.y * sub.y;

            sub = b - origin;
            float dist1 = sub.x * sub.x + sub.y * sub.y;

            if (dist0 < dist1)
                return true;
            return false;
        });

        return results[0];
    }
    else
        return vec2f(Collision::inf, Collision::inf);
}

void CollisionHandler::react(BoxPtr_t a, BoxPtr_t b)
{
    if ((a->reactMaterial & b->material) == b->material)
    {
        if (a->callback)
            a->callback();
    }

    if ((b->reactMaterial & a->material) == a->material)
    {
        if (b->callback)
            b->callback();
    }
}

void CollisionHandler::clean()
{
    for (auto i = m_bodies.begin(); i != m_bodies.end();)
    {
        auto& the = *i;
        if (the.use_count() == 1)
        {
            the.reset();
            i = m_bodies.erase(i);
        }
        else i++;
    }
}

void CollisionHandler::cleanUp()
{
    for (std::size_t i = 0; i < m_bodies.size(); i++)
        m_bodies[i].reset();
    m_bodies.clear();
}