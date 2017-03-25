#ifndef SOUND_HANDLER_HPP
#define SOUND_HANDLER_HPP
#include <SFML/Audio.hpp>

enum SoundEffect
{
    HitEffect = 0,
    SpellEffect,
    StepEffect,
    FailEffect,
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

        void init();
        void playSound(int effect, bool loop = false);
        void stopSound(int effect);

    private:
        sf::SoundBuffer m_buffers[SoundEffect::NumSounds];
        sf::Sound m_sounds[SoundEffect::NumSounds];
};

#endif