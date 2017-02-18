#ifndef MAP_HPP
#define MAP_HPP
#include "../rapidxml/rapidxml.hpp"
#include "../Core/Vec2.hpp"
#include "../Core/Rect.hpp"
#include "../Resource/TexturePtr.hpp"
#include "../Collision/BoxPtr.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include <map>

class Level;

struct Tile
{
	Tile(){}

	sf::Sprite sprite;
	vec2i position;
	Recti rect;
	bool empty = false;
};

struct TileLayer
{
	std::vector<Tile> tiles;
};

class Map
{
	public:
		void loadFromFile(std::string path);
		void loadTileset(rapidxml::xml_node<>* tileset);
		void loadLayers(rapidxml::xml_node<>* map);
		void loadLayer(rapidxml::xml_node<>* layer);
		void loadObjects(rapidxml::xml_node<>* objects);
		void collisions();

		void update();

		void setLevel(Level* level);

	private:
		std::vector<Tile> m_Tileset;
		std::vector<TileLayer> m_Layers;
		TexturePtr_t m_texture;

		Level* m_level;

		std::vector<BoxPtr_t> m_Boxes;

		int m_width = 0;
		int m_height = 0;
};

#endif
