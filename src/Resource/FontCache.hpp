#ifndef FONT_CACHE_HPP
#define FONT_CACHE_HPP
#include "FontPtr.hpp"
#include <map>

class FontCache
{
    public:
        static FontCache& Get()
        {
            static FontCache self;
            return self;
        }

        void init();

        FontPtr_t getFont(const std::string& path);

    private:
        FontPtr_t loadFont(const std::string& path);

    private:
        std::map<std::string, FontPtr_t> m_Fonts;
};

#endif
