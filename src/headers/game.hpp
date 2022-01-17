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
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        const char *window_title;
        int window_width;
        int window_height;
        int fps;
        bool running;
        Map map;
        std::vector<Entity *> entities;

        void render();
        void update();
        void events();

    public:
        Game(const char *window_title, int window_width, int window_height, int fps);
        int run();
        ~Game();
};
