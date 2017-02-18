#ifndef DIRECTION_HPP
#define DIRECTION_HPP
#include "Vec2.hpp"

using Direction_t = unsigned int;

namespace Direction
{

constexpr Direction_t UP = 0;
constexpr Direction_t DOWN = 1;
constexpr Direction_t LEFT = 2;
constexpr Direction_t RIGHT = 3;

static Direction_t deduceDirection(vec2f dir)
{
    float d = dot(dir, vec2f(0,-1));

    if(d >= 0.5)
        return UP;

    else if(d <= -0.5)
        return DOWN;

    else if(d < 0.5 and d > -0.5 and dir.x >= 0)
        return RIGHT;

    else if(d < 0.5 and d > -0.5 and dir.x <= 0)
        return LEFT;
}

};

#endif
