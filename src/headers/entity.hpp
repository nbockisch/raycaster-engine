#include <SDL2/SDL_render.h>

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
