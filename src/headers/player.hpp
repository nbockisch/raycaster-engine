/**
 * @author Nathan Bockisch
 *
 * Header file for the Player class, containing all the class function and 
 * variable declarations
 **/

#include <SDL2/SDL_render.h>
#include "entity.hpp"

class Player : public Entity
{
    private:
        double x_dir;
        double y_dir;
    public:
        Player(int x, int y);
        virtual void render(SDL_Renderer *renderer) override;
        virtual void update() override;
        void set_angle(int angle);
        int get_angle();
        ~Player();
};
