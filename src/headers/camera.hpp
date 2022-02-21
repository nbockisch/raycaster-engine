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
        double fov;
    public:
        Camera(Player *player, Map *map, double fov);
        void update();
        void render(SDL_Renderer *renderer);
        ~Camera();
};
