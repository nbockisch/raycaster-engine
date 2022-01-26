/**
 * @author Nathan Bockisch
 *
 * Header file for the Camera class, containing all the class declarations
 * The camera contains all the functions for raycasting and rendering the
 * player's view
 **/

#include <SDL2/SDL_render.h>
#include "map.hpp"
#include "player.hpp"

class Camera
{
    private:
        Player *player;
        Map *map;
    public:
        Camera(Player *player, Map *map);
        void update();
        void render(SDL_Renderer *renderer);
        ~Camera();
};
