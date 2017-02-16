#ifndef COLLISION_ALGORITHM_HPP
#define COLLISION_ALGORITHM_HPP
#include "../core/rect.hpp"

namespace Collision
{

static bool AABBResponse(const Rectf& a, const Rectf& b, vec2f& move)
{
    move = vec2f();

    float left   = b.x - (a.x + a.w);
    float right  = (b.x + b.w) - a.x;
    float top    = b.y - (a.y + a.h);
    float bottom = (b.y + b.h) - a.y;

    if(left > 0 or right < 0 or top > 0 or bottom < 0)
        return false;

    move.x = abs(left) < right ? left : right;
    move.y = abs(top) < bottom ? top : bottom;

    if(abs(move.x) < abs(move.y))
        move.y = 0;
    else
        move.x = 0;

    return true;
}

static bool AABBOverlap(const Rectf& a, const Rectf& b)
{
    if(a.x > b.x + b.w)
        return false;
    if(a.x + a.w < b.x)
        return false;
    if(a.y > b.y + b.h)
        return false;
    if(a.y + a.h < b.y)
        return false;
    return true;
}

};

#endif
