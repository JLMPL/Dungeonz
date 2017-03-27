#ifndef SOUND_HANDLER_HPP
#define SOUND_HANDLER_HPP
#include <SFML/Audio.hpp>

enum SoundEffect
{
    HitEffect = 0,
    SpellEffect,
    StepEffect,
    FailEffect,
    TakeEffect,
    NumSounds
};

//Singleton
class SoundHandler
{
    public:
        static SoundHandler& Get()
        {
            static SoundHandler self;
            return self;
        }

        ~SoundHandler();

        void init();

        void playMusic();
        void playSound(int effect, bool loop = false);
        void stopSound(int effect);

    private:
        sf::SoundBuffer m_buffers[SoundEffect::NumSounds];
        sf::Sound m_sounds[SoundEffect::NumSounds];

        sf::SoundBuffer m_musicBuffer;
        sf::Sound m_music;
};

#endif