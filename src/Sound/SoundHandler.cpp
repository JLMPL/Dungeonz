#include "SoundHandler.hpp"

SoundHandler::~SoundHandler()
{
}

void SoundHandler::init()
{
    m_buffers[SoundEffect::HitEffect].loadFromFile("data/Sounds/hit.wav");
    m_buffers[SoundEffect::SpellEffect].loadFromFile("data/Sounds/spell.wav");
    m_buffers[SoundEffect::StepEffect].loadFromFile("data/Sounds/step.wav");
    m_buffers[SoundEffect::FailEffect].loadFromFile("data/Sounds/fail.wav");
    m_buffers[SoundEffect::TakeEffect].loadFromFile("data/Sounds/take.wav");

    for (int i = 0; i < SoundEffect::NumSounds; i++)
    {
        m_sounds[i].setBuffer(m_buffers[i]);
    }

    m_sounds[SoundEffect::StepEffect].setPitch(0.4);
    m_sounds[SoundEffect::StepEffect].setVolume(64);

    m_sounds[SoundEffect::FailEffect].setPitch(0.3);
    m_sounds[SoundEffect::StepEffect].setVolume(30);

    // m_musicBuffer.loadFromFile("");
    // m_music.setBuffer(m_musicBuffer);
    // m_music.setVolume(64);
    // m_music.setLoop(true);
}

void SoundHandler::playMusic()
{
    // m_music.play();
}

void SoundHandler::playSound(int effect, bool loop)
{
    m_sounds[effect].setLoop(loop);
    m_sounds[effect].play();
}

void SoundHandler::stopSound(int effect)
{
    m_sounds[effect].stop();
}