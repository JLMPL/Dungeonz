#ifndef ERROR_HPP
#define ERROR_HPP
#include <SDL2/SDL.h>
#include <string>

static void ShowErrorBox(const std::string& message)
{
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", message.c_str(), NULL);
}

#endif
