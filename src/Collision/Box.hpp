#ifndef BOX_HPP
#define BOX_HPP
#include "CollisionMaterial.hpp"
#include "../Core/Rect.hpp"
#include "../Render/Renderer.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>
#include <memory>

struct Box
{
    using Ptr = std::shared_ptr<Box>;

    enum class Type : int
    {
        Static = 0,
        Dynamic,
        TriggerVolume
    };

    Rectf rect;
    Type type = Type::Static;
    CollMaterial_t material = CollMaterial::None;
    CollMaterial_t reactMaterial = CollMaterial::None;
    bool enabled = true;
    std::function<void ()> callback;

    sf::RectangleShape shape;

    //SLOW AS FUCK
    void draw()
    {
        shape = sf::RectangleShape({rect.w, rect.h});
        shape.setPosition(rect.x, rect.y);
        shape.setOutlineThickness(-1);
        
        int eno;
        if (enabled)
            eno = 128;
        else
            eno = 32;

        if (type == Type::Static)
            shape.setOutlineColor({0,0,255,eno});
        else if (type == Type::Dynamic)
            shape.setOutlineColor({0,255,0,eno});
        else 
            shape.setOutlineColor({255,0,0,eno});

        shape.setFillColor({0,0,0,0});

        Renderer::Get().submitOverlay(&shape);
    }
};

#endif
