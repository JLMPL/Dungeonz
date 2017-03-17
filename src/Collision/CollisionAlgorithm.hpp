#ifndef COLLISION_ALGORITHM_HPP
#define COLLISION_ALGORITHM_HPP
#include "../Core/Rect.hpp"
#include <limits>

namespace Collision
{

static float inf = -1000000; //std::numeric_limits<float>::infinity();
static vec2f infVec(inf, inf);

static bool AABBResponse(const Rectf& a, const Rectf& b, vec2f& move)
{
    move = vec2f();

    float left   = b.x - (a.x + a.w);
    float right  = (b.x + b.w) - a.x;
    float top    = b.y - (a.y + a.h);
    float bottom = (b.y + b.h) - a.y;

    if (left > 0 or right < 0 or top > 0 or bottom < 0)
        return false;

    move.x = abs(left) < right ? left : right;
    move.y = abs(top) < bottom ? top : bottom;

    if (abs(move.x) < abs(move.y))
        move.y = 0;
    else
        move.x = 0;

    return true;
}

static bool AABBOverlap(const Rectf& a, const Rectf& b)
{
    if (a.x > b.x + b.w)
        return false;
    if (a.x + a.w < b.x)
        return false;
    if (a.y > b.y + b.h)
        return false;
    if (a.y + a.h < b.y)
        return false;
    return true;
}

static vec2f lineVsLine(vec2f p1, vec2f p2, vec2f p3, vec2f p4)
{
    float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
    float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;
 
    float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (d == 0)
        return vec2f(inf, inf);
 
    float pre = (x1*y2 - y1*x2);
    float post = (x3*y4 - y3*x4);
    float x = (pre * (x3 - x4) - (x1 - x2) * post) / d;
    float y = (pre * (y3 - y4) - (y1 - y2) * post) / d;
     
    // Check if the x and y coordinates are within both lines
    if (x < std::min(x1, x2) || x > std::max(x1, x2) || x < std::min(x3, x4) || x > std::max(x3, x4))
    {
        return vec2f(inf, inf);
    }
    if (y < std::min(y1, y2) || y > std::max(y1, y2) || y < std::min(y3, y4) || y > std::max(y3, y4))
    {
        return vec2f(inf, inf);
    }

    return vec2f(x,y);
}

static vec2f lineVsRect(vec2f start, vec2f end, Rectf rect)
{
    vec2f verts[4];
    vec2f results[4];

    verts[0] = vec2f(rect.x, rect.y);
    verts[1] = vec2f(rect.x + rect.w, rect.y);
    verts[2] = vec2f(rect.x + rect.w, rect.y + rect.h);
    verts[3] = vec2f(rect.x, rect.y + rect.h);
    
    results[0] = lineVsLine(start, end, verts[0], verts[1]);
    results[1] = lineVsLine(start, end, verts[1], verts[2]);
    results[2] = lineVsLine(start, end, verts[2], verts[3]);
    results[3] = lineVsLine(start, end, verts[3], verts[0]);

    vec2f close(inf, inf);

    std::sort(results, results+4,
    [=](vec2f& a, vec2f& b)
    {
        vec2f sub0 = a - start;
        float dist0 = sub0.x * sub0.x + sub0.y * sub0.y;

        vec2f sub1 = b - start;
        float dist1 = sub1.x * sub1.x + sub1.y * sub1.y;

        if (dist0 < dist1)
            return true;
        return false;
    });

    return results[0];
}

};

#endif
