#ifndef TEXTURE_CACHE_HPP
#define TEXTURE_CACHE_HPP
#include "TexturePtr.hpp"
#include <map>

//Singleton
class TextureCache
{
    public:
        static TextureCache& Get()
        {
            static TextureCache self;
            return self;
        }

        void init();

        TexturePtr_t getTexture(const std::string& path);

    private:
        TexturePtr_t loadTexture(const std::string& path);

    private:
        std::map<std::string, TexturePtr_t> m_Textures;
};

#endif
