#ifndef animation_cache_hpp
#define animation_cache_hpp
#include "animation_ptr.hpp"
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

        AnimPtr_t getAnimation(const std::string& path);

    private:
        AnimPtr_t loadAnimation(const std::string& path);

    private:
        std::map<std::string, AnimPtr_t> m_Animations;
};

#endif
