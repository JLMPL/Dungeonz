#ifndef box_hpp
#define box_hpp
#include "collision_type.hpp"
#include "collision_material.hpp"
#include "../core/rect.hpp"
#include "../render/renderer.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

struct Box
{
	Rectf rect;
	CollisionType type = CollisionType::STATIC;
	CollMaterial_t material = CollMaterial::NONE;
	CollMaterial_t reactMaterial = CollMaterial::NONE;
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
		if(enabled)
			eno = 128;
		else
			eno = 32;

		if(type == CollisionType::STATIC)
			shape.setOutlineColor({0,0,255,eno});
		else if(type == CollisionType::DYNAMIC)
			shape.setOutlineColor({0,255,0,eno});
		else 
			shape.setOutlineColor({255,0,0,eno});

		shape.setFillColor({0,0,0,0});

		Renderer::Get().submit(RenderData(&shape), RenderAttribute::OVERLAY);
	}
};

#endif
