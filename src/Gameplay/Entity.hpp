#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "EntityType.hpp"
#include "../Render/SpritePtr.hpp"
#include "../Collision/BoxPtr.hpp"
#include <cstring>

#ifdef _WIN32
using uint = unsigned int;
#endif

class Level;

class Entity
{
    public:
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
        EntityType         getType() const;
        vec2f              getPosition() const;
        Level*             getLevel() const;
        vec2i              getFakePos() const;
        bool               isDestroyed();

    protected:
        uint        m_id;
        std::string m_code;
        EntityType  m_type = EntityType::Plain;
        Level*      m_level = nullptr;
        SpritePtr_t m_sprite = nullptr;
        vec2f       m_pos;
        BoxPtr_t    m_box;
        bool        m_destroy = false;
};

#endif
