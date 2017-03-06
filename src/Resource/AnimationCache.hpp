#ifndef ANIMATION_CACHE_HPP
#define ANIMATION_CACHE_HPP
#include "AnimationPtr.hpp"
#include "../zip/zip.h"
#include <map>

//Singleton
class AnimationCache
{
    public:
        static AnimationCache& Get()
        {
            static AnimationCache self;
            return self;
        }

        void init();
        ~AnimationCache();

        AnimPtr_t getAnimation(const std::string& path);

    private:
        AnimPtr_t loadAnimation(const std::string& path);

    private:
        std::map<std::string, AnimPtr_t> m_Animations;
        struct zip_t* m_zip = nullptr;
};

#endif
