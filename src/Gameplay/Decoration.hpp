#ifndef DECORATION_HPP
#define DECORATION_HPP
#include "../Core/Vec2.hpp"
#include "../Render/AnimatedSprite.hpp"
#include <memory>

class Decoration
{
    public:
        using Ptr = std::shared_ptr<Decoration>;

        Decoration();

        void init(const std::string& path);
        void update(float deltaTime);
        void setPosition(const vec2f& pos);

    private:
        AnimatedSprite m_sprite;
};

#endif