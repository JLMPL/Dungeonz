#include "LuaInterface.hpp"
#include "../Gui/Gui.hpp"

void gui_read(std::string content)
{
	GUI::Get().goRead(content);
}