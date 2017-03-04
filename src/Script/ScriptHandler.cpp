#include "ScriptHandler.hpp"
#include "LuaInterface.hpp"
#include "../Gameplay/Living.hpp"
#include "../Gameplay/Spells.hpp"

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
		addFunction("setDefense", 		  &Living::setDefense).
		addFunction("restoreBasicDefense",&Living::restoreBasicDefense).
		addFunction("restoreHealth",      &Living::restoreHealth).
		addFunction("restoreFullHealth",  &Living::restoreFullHealth).
		addFunction("restoreMana",        &Living::restoreMana).
		addFunction("restoreFullMana",    &Living::restoreFullMana).
		addFunction("learnSpell",		  &Living::learnSpell).
		addFunction("knowsSpell", 		  &Living::knowsSpell).
	endClass();

	// getGlobalNamespace(lua).
	// beginNamespace("spell").
	// 	addProperty("Fireball", static_cast<int>(Spell::Fireball)).
	// endNamespace();

	getGlobalNamespace(lua).
	addFunction("gui_read", &gui_read);
}	
