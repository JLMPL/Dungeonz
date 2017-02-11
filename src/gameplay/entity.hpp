#ifndef entity_hpp
#define entity_hpp
#include "entity_type.hpp"
#include "../render/sprite_ptr.hpp"
#include "../collision/box_ptr.hpp"

class Level;

class Entity
{
	public:
		virtual ~Entity();

		virtual void update(float deltaTime);

		void move(vec2f offset);

		void setId(uint id);
		void setCode(const std::string& code);
		void setLevel(Level* level);
		void setPosition(const vec2f& pos);

		uint               getId() const;
		const std::string& getCode() const;
		EntityType         getType() const;
		vec2f              getPosition() const;
		Level*             getLevel() const;
		vec2i 			   getFakePos() const;

	protected:
		uint        m_id;
		std::string m_code;
		EntityType  m_type = EntityType::PLAIN;
		Level*      m_level = nullptr;
		SpritePtr_t m_sprite = nullptr;
		vec2f       m_pos;
		BoxPtr_t    m_box;
};

#endif
