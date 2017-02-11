#include "script_handler.hpp"
#include "lua_interface.hpp"
#include "../gameplay/living.hpp"

void ScriptHandler::init()
{
}

void ScriptHandler::loadLibs(lua_State* lua)
{
	using namespace luabridge;

	getGlobalNamespace(lua).
	beginClass<Living>("Living").
		addConstructor<void(*)(void)>().
		addFunction("setDamage",          &Living::setDamage).
		addFunction("restoreBasicDamage", &Living::restoreBasicDamage).
		addFunction("restoreHealth",      &Living::restoreHealth).
		addFunction("restoreFullHealth",  &Living::restoreFullHealth).
		addFunction("restoreMana",        &Living::restoreMana).
		addFunction("restoreFullMana",    &Living::restoreFullMana).
	endClass();

	getGlobalNamespace(lua).
	addFunction("gui_read", &gui_read);
}	
