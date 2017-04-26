#ifndef GUI_HPP
#define GUI_HPP
#include "GraphicInv.hpp"
#include "GraphicLoot.hpp"
#include "GuiMode.hpp"
#include "CenterLabel.hpp"
#include "Spellbook.hpp"
#include "../Render/Bar.hpp"
#include "../Gameplay/Level.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>

class Living;
class Inventory;
class StatePlaying;

//Singleton
class GUI
{
    public:
        static GUI& Get()
        {
            static GUI self;
            return self;
        }

        void init();
        void update(float deltaTime);

        void goLoot(Inventory* inv, const vec2i& pos);
        void goRead(const std::string& content);
        void showFocusHealthbar(int val, int max, const vec2i& pos);
        void setFocusLabel(const std::string& label, const vec2i& pos);
        void addLabel(const std::string& label);

        void goDead();
        void goFinishGame();

        void setTarget(Living* living);
        Living* getTarget();

        void setPlayingState(StatePlaying* state);
        void begForLevel(const std::string& level, Level::InitMode mode);

        void setBackToMenuFunc(std::function<void ()> func);
        void setFinishGameFunc(std::function<void ()> func);

        void setPause(bool pause);
        bool isPause() const;

    private:
        GUIMode m_mode;
        sf::Clock m_timer;
        sf::Sprite m_sight;
        vec2i m_camera;

        bool m_showLabel = false;
        sf::Text m_focusLabel;
        bool m_showHealthbar = false;
        Bar m_focusHealth;

        Living* m_target;

        GraphicInv m_ginv;
        GraphicLoot m_gloot;
        Bar m_health;
        Bar m_magicka;

        vec2i m_bookPos;
        sf::Sprite m_bookBack;
        sf::Text m_bookText;

        CenterLabel m_centerLabel;

        Spellbook m_spellbook;

        sf::Text m_deathSentence;
        sf::RectangleShape m_deathFade;
        float m_deathTimer = 0;

        StatePlaying* m_playingState;

        std::function<void ()> m_backToMenuFunc;
        std::function<void ()> m_finishGameFunc;

        bool m_finishGame = false;
        bool m_paused = false;

        sf::RectangleShape m_pauseBackground;
        sf::Text m_pauseText;
};

#endif
