#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_render.h>
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
    this->map = Map();
    /* this->entities = std::vector<Entity *>(); */
    Player player = Player(200, 200);
    this->entities.push_back(new Player(200, 200));
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

    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    if (!this->renderer) {
        std::cerr << "Error initializing renderer: " << SDL_GetError() << "\n";
        return 1; 
    }

    // Run the game loop
    this->running = true;

    int delay = 1000.0f / this->fps;
    Uint32 frame_start, frame_time;
    while (this->running) {
        frame_start = SDL_GetTicks();

        // Updating and rendering goes here
        this->update();
        this->render();

        frame_time = SDL_GetTicks() - frame_start;
        
        if (frame_start < delay)
            SDL_Delay((int) (delay - frame_time));

    }

    return 0;
}

void Game::render() 
{
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderClear(this->renderer);
    
    this->map.render(this->renderer);

    for (Entity *entity : this->entities) {
	    entity->render(this->renderer);
    }
    
    SDL_RenderPresent(this->renderer);
}

void Game::update()
{
    InputHandler::get_handler().update();
    
    if (InputHandler::get_handler().should_quit()) {
        this->running = false;
        return;
    }

    this->map.update();

    for (Entity *entity : this->entities) {
	    entity->update();
    }
}

Game::~Game()
{
    for (Entity *entity : this->entities) {
        delete entity;
    }

    if (this->window)
        SDL_DestroyWindow(this->window);

    if (this->renderer)
        SDL_DestroyRenderer(this->renderer);

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}
