#include <SDL.h>
#include <iostream>
#include "RenderWindow.hpp"
using namespace std;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h,
            SDL_WINDOW_SHOWN);

    if (window == NULL)
        cout << "Window failed to INIT. Error: " << SDL_GetError() << endl;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}