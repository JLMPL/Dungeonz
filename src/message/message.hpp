#ifndef message_hpp
#define message_hpp
#include "../core/vec2.hpp"
#include "../render/render_attribute.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <string>

struct Message_t
{

};

namespace Message
{
    namespace GUI
    {
        constexpr int SET_FOCUS_LABEL = 0;

        struct MessageLabel : public Message_t
        {
            std::string name;
            vec2i pos;

            MessageLabel(const std::string& n, const vec2i& p) : name(n), pos(p) {}
        };
    };

    namespace RENDER
    {
        constexpr int SET_CAMERA_POS = 1;

        struct MessageCamera : public Message_t
        {
            vec2i pos;

            MessageCamera(const vec2i& p) : pos(p) {}
        };

        constexpr int SUBMIT_SPRITE = 2;

        struct MessageSubmitSprite : public Message_t
        {
            sf::Sprite* data;
            RenderAttribute attribute;

            MessageSubmitSprite(sf::Sprite* s, const RenderAttribute& att) : data(s), attribute(att) {}
        };
    };
};

#endif
