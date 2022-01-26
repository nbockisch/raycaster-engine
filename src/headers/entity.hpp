/**
 * @author Nathan Bockisch
 *
 * Header file for the Entity class, containing all the class declarations
 * inherited by all entities, including the Player class
 **/

#include <SDL2/SDL_render.h>
#include "input_handler.hpp"

class Entity
{
    protected:
        int x;
        int y;

    public:
        void set_x(int x);
        void set_y(int y);
        int get_x();
        int get_y();
        virtual void render(SDL_Renderer *renderer);
        virtual void update();
};
