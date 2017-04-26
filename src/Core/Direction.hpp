#ifndef DIRECTION_HPP
#define DIRECTION_HPP
#include "Vec2.hpp"

using Direction_t = unsigned int;

namespace Direction
{

constexpr Direction_t Up = 0;
constexpr Direction_t Down = 1;
constexpr Direction_t Left = 2;
constexpr Direction_t Right = 3;

static Direction_t deduceDirection(vec2f dir)
{
    float d = dot(dir, vec2f(0,-1));
    float actual = acos(d) / M_PI;

    if (d >= 0.5)
        return Up;

    else if (d <= -0.5)
        return Down;

    else if (d < 0.5 and d > -0.5 and dir.x >= 0)
        return Right;

    else if (d < 0.5 and d > -0.5 and dir.x <= 0)
        return Left;

    return Up;
}
}

#endif
