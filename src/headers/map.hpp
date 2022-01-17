#include <vector>
#include <SDL2/SDL_render.h>

class Map
{
    private:
        std::vector<std::vector<int>> map;

    public:
        Map();
	void render(SDL_Renderer *renderer);
	void update();
        ~Map();
};
