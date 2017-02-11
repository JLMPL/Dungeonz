#ifndef font_cache_hpp
#define font_cache_hpp
#include "font_ptr.hpp"
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
