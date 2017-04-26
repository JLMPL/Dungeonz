#ifndef MAP_HPP
#define MAP_HPP
#include "Chunk.hpp"
#include "../Resource/TexturePtr.hpp"
#include "../Collision/Box.hpp"
#include "../rapidxml/rapidxml.hpp"
#include <vector>
#include <string>
#include <memory>
#include <map>

class Level;

struct TileLayer
{
    std::vector<Tile> tiles;
    std::vector<std::vector<Chunk>> chunks;
};

class Map
{
    public:
        void loadFromFile(const std::string& path);
        void loadTileset(rapidxml::xml_node<>* tileset);
        void loadLayers(rapidxml::xml_node<>* map);
        void loadLayer(rapidxml::xml_node<>* layer);
        void loadObjects(rapidxml::xml_node<>* objects);
        void makeChunks();
        void collisions();

        void update();

        void setLevel(Level* level);

    private:
        std::vector<Tile> m_tileset;
        std::vector<TileLayer> m_layers;
        TexturePtr_t m_texture;

        Level* m_level;

        std::vector<Box::Ptr> m_boxes;

        int m_width = 0;
        int m_height = 0;
};

#endif
