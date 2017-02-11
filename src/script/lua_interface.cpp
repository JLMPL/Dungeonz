#include "lua_interface.hpp"
#include "../gui/gui.hpp"

void gui_read(std::string content)
{
	GUI::Get().goRead(content);
}