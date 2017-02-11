#ifndef error_hpp
#define error_hpp
#include <SDL2/SDL.h>
#include <string>

static void ShowErrorBox(const std::string& message)
{
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", message.c_str(), NULL);
}

#endif
