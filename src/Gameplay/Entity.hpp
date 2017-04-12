#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "../Render/Sprite.hpp"
#include "../Collision/Box.hpp"
#include <cstring>
#include <memory>

#ifdef _WIN32
using uint = unsigned int;
#endif

class Level;

class Entity
{
    public:
        using Ptr = std::unique_ptr<Entity>;

        enum class Type
        {
            Plain,
            Living,
            Chest,
            Door,
            Lever,
            SpikeTrap,
            PressPlate,
            ItemBag,
            Fireball,
            Exit,
            Arrow
        };

        virtual ~Entity();

        virtual void update(float deltaTime);

        void move(vec2f offset);
        void destroy();

        void setId(uint id);
        void setCode(const std::string& code);
        void setLevel(Level* level);
        void setPosition(const vec2f& pos);

        uint               getId() const;
        const std::string& getCode() const;
        Type               getType() const;
        vec2f              getPosition() const;
        Level*             getLevel() const;
        vec2i              getFakePos() const;
        bool               isDestroyed();

    protected:
        uint        m_id;
        std::string m_code;
        Type  m_type = Type::Plain;
        Level*      m_level = nullptr;
        Sprite::Ptr m_sprite = nullptr;
        vec2f       m_pos;
        Box::Ptr    m_box;
        bool        m_destroy = false;
};

#endif
