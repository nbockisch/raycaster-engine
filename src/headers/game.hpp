/**
 * @author Nathan Bockisch
 *
 * Header file for the Game class, containing all the class and variable
 * declarations for starting the SDL components and rendering/updating the map
 * and entities
 **/

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <string>

#include "map.hpp"
#include "player.hpp"

class Game
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        const char *window_title;
        int window_width;
        int window_height;
        int fps;
        bool running;
        Map map;
        std::vector<Entity *> entities;

        void render();
        void update();

    public:
        Game(const char *window_title, int window_width, int window_height, int fps);
        int run();
        ~Game();
};
