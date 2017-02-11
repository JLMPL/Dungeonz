#ifndef texture_cache_hpp
#define texture_cache_hpp
#include "texture_ptr.hpp"
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
