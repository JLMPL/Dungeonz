#ifndef script_handler_hpp
#define script_handler_hpp
extern "C"
{
#include <lua5.2/lua.h>
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>
}
#include "../LuaBridge/LuaBridge.h"

class ScriptHandler
{
	public:
		static ScriptHandler& Get()
		{
			static ScriptHandler self;
			return self;
		}

		void init();

		void loadLibs(lua_State* lua);
	private:
};

#endif