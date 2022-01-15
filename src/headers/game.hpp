#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <string>

class Game
{
    private:
        SDL_Window *window = NULL;
        SDL_Surface *surface = NULL;
        const char *window_title;
        int window_width;
        int window_height;
	int fps;
	bool running;

    public:
        Game(const char *window_title, int window_width, int window_height, int fps);
        int run();
        ~Game();
};
