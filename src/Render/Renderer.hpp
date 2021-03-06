#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Thread.hpp>
#include <vector>

struct Line
{
    sf::Vertex* verts;
    int count = 0;
    sf::PrimitiveType type;
};

//Singleton
class Renderer
{
    public:
        static Renderer& Get()
        {
            static Renderer self;
            return self;
        }

        void init(sf::RenderWindow* window);

        void submitBackground(sf::CircleShape* data);
        void submitBackground(sf::Sprite* data);
        void submitSorted(sf::Sprite* data);
        void submitPrimitive(sf::Vertex* draw, int count, sf::PrimitiveType type);
        void submitForeground(sf::Sprite* data);
        void submitArray(sf::VertexArray* array, const sf::RenderStates& states);

        void submitOverlay(sf::RectangleShape* data);
        void submitOverlay(sf::Sprite* data);
        void submitOverlay(sf::Text* data);
        void flush();

        void setCameraPos(const vec2i& pos);
        void resetCameraPos();
        vec2i getCameraPos() const;

    private:
        void updateCamera();
        void cull();
        void sort();
        void render();
        void clearAll();

    private:
        sf::RenderWindow* m_window = nullptr;
        std::vector<sf::CircleShape*> m_backCircleData;
        std::vector<sf::Sprite*> m_backgroundData;
        std::vector<sf::Sprite*> m_sortedData;
        std::vector<sf::Sprite*> m_foregroundData;

        std::vector<std::pair<sf::VertexArray*, sf::RenderStates>> m_arrayData;

        std::vector<Line> m_linesData;

        std::vector<sf::RectangleShape*> m_overRectData;
        std::vector<sf::Sprite*>         m_overSpriteData;
        std::vector<sf::Text*>           m_overTextData;
        sf::View m_camera;
};

#endif
