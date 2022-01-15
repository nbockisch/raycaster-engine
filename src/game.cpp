#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "headers/game.hpp"

Game::Game(const char *window_title, int window_width, int window_height, int fps)
{
    this->window_title = window_title;
    this->window_width = window_width;
    this->window_height = window_height;
    this->fps = fps;
}

int Game::run()
{
    // Initialize SDL and main SDL components
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << "\n";
        return 1; 
    }

    this->window = SDL_CreateWindow(this->window_title, SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, this->window_width, this->window_height, 
            SDL_WINDOW_SHOWN);
    if (!this->window) {
        std::cerr << "Error initializing window: " << SDL_GetError() << "\n";
        return 1; 
    }

    this->surface = SDL_GetWindowSurface(this->window);

    // Run the game loop
    this->running = true;
    SDL_Event e;

    int delay = 1000.0f / this->fps;
    Uint32 frame_start, frame_time;
    while (this->running) {
        frame_start = SDL_GetTicks();

        // Updating and rendering goes here
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window);

        frame_time = SDL_GetTicks() - frame_start;
        
        if (frame_start < delay)
            SDL_Delay((int) (delay - frame_time));

    }

    return 0;
}

Game::~Game()
{
    if (this->window)
        SDL_DestroyWindow(this->window);

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}
