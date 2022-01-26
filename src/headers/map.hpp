/**
 * @author Nathan Bockisch
 *
 * Header file for the Map class, containing all the class and variable
 * declarations for loading and updating the map
 **/

#include <vector>
#include <SDL2/SDL_render.h>

class Map
{
    private:
        std::vector<std::vector<int>> map;

    public:
        Map();
        std::vector<std::vector<int>> &get_map();
        void render(SDL_Renderer *renderer);
        void update();
        ~Map();
};
