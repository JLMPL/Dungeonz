#include "AnimationCache.hpp"

void AnimationCache::init()
{
}

AnimPtr_t AnimationCache::getAnimation(const std::string& path)
{
    auto anim = m_Animations.find(path);

    if (anim == m_Animations.end())
        return loadAnimation(path);
    else
        return m_Animations[path];
}

AnimPtr_t AnimationCache::loadAnimation(const std::string& path)
{
    AnimPtr_t anim = AnimPtr_t(new Animation());
    anim->loadFromFile(path);
    m_Animations.insert(std::make_pair(path, anim));
    return anim;
}
