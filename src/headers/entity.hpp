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
        double x;
        double y;

    public:
        void set_x(double x);
        void set_y(double y);
        double get_x();
        double get_y();
        virtual void render(SDL_Renderer *renderer);
        virtual void update();
};
