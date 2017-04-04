#include "Chunk.hpp"
#include "../Render/Renderer.hpp"
#include "Tile.hpp"

Chunk::Chunk()
{
    m_array = sf::VertexArray(sf::PrimitiveType::Quads, 1024);
}

void Chunk::addTile(Tile& tile)
{
    m_tiles.push_back(&tile);

    m_array.append(sf::Vertex(
        sf::Vector2f(tile.position.x + tile.rect.w,
                     tile.position.y + tile.rect.h),
        sf::Vector2f(tile.rect.x + tile.rect.w,
                     tile.rect.y + tile.rect.h)
    ));

    m_array.append(sf::Vertex(
        sf::Vector2f(tile.position.x + tile.rect.w,
                     tile.position.y),
        sf::Vector2f(tile.rect.x + tile.rect.w,
                     tile.rect.y)
    ));

    m_array.append(sf::Vertex(
        sf::Vector2f(tile.position.x, tile.position.y),
        sf::Vector2f(tile.rect.x, tile.rect.y)
    ));

    m_array.append(sf::Vertex(
        sf::Vector2f(tile.position.x,
                     tile.position.y + tile.rect.h),
        sf::Vector2f(tile.rect.x,
                     tile.rect.y + tile.rect.h)
    ));
}

void Chunk::setTexture(TexturePtr_t texture)
{
    m_texture = texture;
}

void Chunk::render()
{
    static sf::RenderStates states;
    states.texture = m_texture.get();
    Renderer::Get().submitArray(&m_array, states);
}
