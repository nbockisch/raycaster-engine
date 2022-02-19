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
        double angle;
    public:
        Player(double x, double y);
        virtual void render(SDL_Renderer *renderer) override;
        virtual void update() override;
        void move_forward(double amount);
        void move_back(double amount);
        void set_angle(double angle);
        void change_angle(double change);
        double get_angle();
        ~Player();
};
