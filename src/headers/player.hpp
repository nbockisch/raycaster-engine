#include <SDL2/SDL_render.h>
#include "entity.hpp"

class Player : public Entity
{
    public:
	Player(int x, int y);
    virtual void render(SDL_Renderer *renderer) override;
    virtual void update() override;
	~Player();
};
