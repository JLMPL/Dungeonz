#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP
#include "GameState.hpp"
#include "../Gameplay/Level.hpp"

enum class TheLevel
{
    First,
    Second
};

class Level;

class StatePlaying : public GameState
{
    public:
        StatePlaying();
        StatePlaying(const std::string& loadFirst);

        void init() override final;
        void update(float deltaTime) override final;
        void leave() override final;

        void setLevel(const std::string& level, bool first);
        void begForLevel(const std::string& level);

    private:
        Level m_level;
        std::string m_consider;
        bool m_considered = true;

        std::string m_loadFirst;
};

#endif