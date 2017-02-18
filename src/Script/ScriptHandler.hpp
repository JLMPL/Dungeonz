#ifndef SCRIPT_HANDLER_HPP
#define SCRIPT_HANDLER_HPP
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