#include "map.hpp"
#include "../base64/base64.h"
#include "../render/renderer.hpp"
#include "../core/error.hpp"
#include "../resource/texture_cache.hpp"
#include "../render/render_attribute.hpp"
#include "../collision/collision_handler.hpp"
#include "living_profile.hpp"
#include "living.hpp"
#include "level.hpp"
#include "door.hpp"
#include "lever.hpp"
#include "spike_trap.hpp"
#include "chest.hpp"
#include "../ai/ai_player.hpp"
#include "../ai/ai_mob.hpp"
#include "../gui/gui.hpp"
#include "zlib.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

void Map::loadFromFile(std::string path)
{
	using namespace rapidxml;

	std::ifstream file(path.c_str());
	std::string line;
	std::string content;

	if(!file.good())
	{
		ShowErrorBox("Something went wrong with " + path + " file.");
	}
	else
	{
		while(!file.eof())
		{
			std::getline(file, line);
			content += line;
			content += "\n";
		}

		xml_document<> doc;
		doc.parse<0>(&content[0]);

		xml_node<>* map = doc.first_node("map");

		m_width = atoi(map->first_attribute("width")->value());
		m_height = atoi(map->first_attribute("height")->value());

		xml_node<>* tileset = map->first_node("tileset");
		loadTileset(tileset);
		loadLayers(map);
		collisions();
	}
}

void Map::loadTileset(rapidxml::xml_node<>* tileset)
{
	using namespace rapidxml;

	xml_node<>* image = tileset->first_node("image");
	std::string texturePath = image->first_attribute("source")->value();
	int width = atoi(image->first_attribute("width")->value());
	int height = atoi(image->first_attribute("height")->value());

	m_texture = TextureCache::Get().getTexture("data/" + texturePath);

	for(int i = 0; i < height/32; i++)
	{
		for(int j = 0; j < width/32; j++)
		{
			Tile tile;
			tile.sprite.setTexture(*m_texture);
			tile.rect = Recti(j * 32, i * 32, 32, 32);
			tile.sprite.setTextureRect({tile.rect.x,
										tile.rect.y,
										tile.rect.w,
										tile.rect.h});
			m_Tileset.push_back(tile);
		}
	}

	xml_node<>* tile = tileset->first_node("tile");

	// while(tile != nullptr)
	// {
	//     int index = atoi(tile->first_attribute("id")->value());
	//
	//     xml_node<>* prop = tile->first_node("properties")->first_node("property");
	//     std::string name = prop->first_attribute("name")->value();
	//
	//     if(name == "collisions")
	//     {
	//         int value = atoi(prop->first_attribute("value")->value());
	//         m_Tileset[index].sprite.rotate(12);
	//         m_Tileset[index].collisionType = static_cast<TileCollision>(value);
	//     }
	//
	//     tile = tile->next_sibling("tile");
	// }
}

void Map::loadLayers(rapidxml::xml_node<>* map)
{
	using namespace rapidxml;

	xml_node<>* groundLayer = map->first_node("layer");
	loadLayer(groundLayer);

	xml_node<>* decorationLayer = map->first_node("layer")->next_sibling("layer");
	loadLayer(decorationLayer);

	xml_node<>* collisionLayer = decorationLayer->next_sibling("layer");
	loadLayer(collisionLayer);

	xml_node<>* objects = map->first_node("objectgroup");
	loadObjects(objects);
}

void Map::loadLayer(rapidxml::xml_node<>* layere)
{
	std::string rawData = layere->first_node("data")->value();

	for(int i = 0; i < rawData.size(); i++)
		if(rawData[i] == '=') rawData[i] = ' ';

	std::stringstream ass(rawData);
	std::string raw;
	ass >> raw;
	rawData = raw;

	std::string decodedData = base64_decode(rawData);

	uLongf finalSize = m_width * m_height * sizeof(int);
	std::vector<int> data(m_width * m_height);
	uncompress((Bytef*)&data[0], &finalSize, (const Bytef*)decodedData.c_str(), decodedData.size());

	TileLayer layer;
	layer.tiles.resize(m_width * m_height);

	for(int i = 0; i < data.size(); i++)
	{
		if(data[i] >= 1)
		{
			layer.tiles[i] = m_Tileset[data[i]-1];
		}
		else
		{
			Tile tile;
			tile.empty = true;
			layer.tiles[i] = tile;
		}
	}

	for(int i = 0; i < m_height; i++)
	{
		for(int j = 0; j < m_height; j++)
		{
			layer.tiles[m_width * i + j].position = vec2i(j * 32, i * 32);
			layer.tiles[m_width * i + j].sprite.setPosition(j * 32, i * 32);
		}
	}

	m_Layers.push_back(layer);
}

void Map::loadObjects(rapidxml::xml_node<>* objects)
{
	using namespace rapidxml;
	xml_node<>* object = objects->first_node("object");

	while(object)
	{
		std::string type = object->first_attribute("type")->value();

		if(type == "spawn")
		{
			std::string whom = object->first_node("properties")->first_node("property")->first_attribute("value")->value();
			vec2f pos;
			pos.x = std::stof(object->first_attribute("x")->value());
			pos.y = std::stof(object->first_attribute("y")->value());

			LivingProfile profile;
			profile.loadFromFile("data/" + whom + ".chr");

			auto living = (Living*)m_level->addEntity(EntityPtr_t(new Living()));
			living->init(profile);
			living->setAI(AIPtr_t(new AIMob()));
			living->setPosition(pos + vec2f(16,16));
		}
		else if(type == "door")
		{
			std::string name = object->first_attribute("name")->value();
			std::string item = object->first_node("properties")->first_node("property")->first_attribute("value")->value();
			vec2f pos;
			pos.x = std::stof(object->first_attribute("x")->value());
			pos.y = std::stof(object->first_attribute("y")->value());

			auto door = (Door*)m_level->addEntity(EntityPtr_t(new Door()));
			door->setCode(name);
			door->setPosition(pos + vec2f(0,30));
			door->setRequiredItem(item);
		}
		else if(type == "chest")
		{
			std::string name = object->first_attribute("name")->value();
			std::string item0 = object->first_node("properties")->first_node("property")->first_attribute("value")->value();
			vec2f pos;
			pos.x = std::stof(object->first_attribute("x")->value());
			pos.y = std::stof(object->first_attribute("y")->value());

			auto chest = (Chest*)m_level->addEntity(EntityPtr_t(new Chest()));
			chest->setCode(name);
			chest->setPosition(pos + vec2f(16,16));

			auto item = m_level->addItem(ItemPtr_t(new Item("data/" + item0 + ".lua")));
			chest->accessInv().addItem(item);
		}
		else if(type == "lever")
		{
			std::string name = object->first_attribute("name")->value();
			std::string whom = object->first_node("properties")->first_node("property")->first_attribute("value")->value();
			std::string type = object->first_node("properties")->first_node("property")->next_sibling()->first_attribute("value")->value();

			printf("%s\n", type.c_str());

			vec2f pos;
			pos.x = std::stof(object->first_attribute("x")->value());
			pos.y = std::stof(object->first_attribute("y")->value());

			auto lever = (Lever*)m_level->addEntity(EntityPtr_t(new Lever()));
			lever->setCode(name);
			lever->setPosition(pos + vec2f(16,16));
			lever->setActivateFunc(
			[=]()
			{
				if(type == "door")
				{
					Door* door = (Door*)m_level->getEntityByCode(whom);
					if(door)
						door->open();
				}
				else if(type == "spike_trap")
				{
					auto spikes = m_level->getEntitiesByCode(whom);
					if(!spikes.empty())
					{
						for(int i = 0; i < spikes.size(); i++)
						{
							static_cast<SpikeTrap*>(spikes[i])->disable();
						}
					}
				}
			});
		}
		else if(type == "spike_trap")
		{
			std::string name = object->first_attribute("name")->value();
			// std::string whom = object->first_node("properties")->first_node("property")->first_attribute("value")->value();
			vec2f pos;
			pos.x = std::stof(object->first_attribute("x")->value());
			pos.y = std::stof(object->first_attribute("y")->value());

			auto trap = (SpikeTrap*)m_level->addEntity(EntityPtr_t(new SpikeTrap()));
			trap->setCode(name);
			trap->setPosition(pos);
		}
		else if(type == "start")
		{
			// std::string name = object->first_attribute("name")->value();
			vec2f pos;
			pos.x = std::stof(object->first_attribute("x")->value());
			pos.y = std::stof(object->first_attribute("y")->value());

			LivingProfile profile;
			profile.loadFromFile("data/pc_player.chr");

			auto player = (Living*)m_level->addEntity(EntityPtr_t(new Living()));
			player->init(profile);
			player->setAI(AIPtr_t(new AIPlayer()));
			player->setPosition(pos);

			GUI::Get().setTarget(player);
		}
		object = object->next_sibling("object");
	}
}

void Map::collisions()
{
	for(int i = 0; i < m_Layers[2].tiles.size(); i++)
	{
		auto& tile = m_Layers[2].tiles[i];

		if(tile.rect.x == 96 and tile.rect.y == 128)
		{
			BoxPtr_t box(new Box());
			box->rect = {tile.position.x, tile.position.y, tile.rect.w, tile.rect.h};
			m_Boxes.push_back(box);

			CollisionHandler::Get().addBody(m_Boxes.back());
		}
	}
}

void Map::update()
{
	// for(int i = 0; i < m_Tileset.size(); i++)
	// {
	//     m_Tileset[i].sprite.setPosition(i * 32, 0);
	//     Renderer::Get().submit(&m_Tileset[i].sprite);
	// }

	for(int i = 0; i < m_Layers[0].tiles.size(); i++)
	{
		Renderer::Get().submitBackground(&m_Layers[0].tiles[i].sprite);
	}

	for(int i = 0; i < m_Layers[1].tiles.size(); i++)
	{
		Renderer::Get().submitBackground(&m_Layers[1].tiles[i].sprite);
	}

	if(false)
	for(int i = 0; i < m_Layers[2].tiles.size(); i++)
	{
		Renderer::Get().submitBackground(&m_Layers[2].tiles[i].sprite);
	}
}

void Map::setLevel(Level* level)
{
	m_level = level;
}