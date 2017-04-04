#ifndef CHUNK_HPP
#define CHUNK_HPP
#include "Tile.hpp"
#include "../Resource/TexturePtr.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Chunk
{
    public:
        Chunk();

        void setTexture(TexturePtr_t texture);
        void addTile(Tile& tile);

        void render();

    private:
        std::vector<Tile*> m_tiles;
        sf::VertexArray m_array;
        TexturePtr_t m_texture;
        vec2f m_position;
        float m_size = 512;
};

#endif
