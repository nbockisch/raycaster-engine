#include <SDL2/SDL_render.h>
#include <iostream>
#include "headers/entity.hpp"

void Entity::set_x(int x)
{
    this->x = x;
}

void Entity::set_y(int y)
{
    this->y = y;
}

int Entity::get_x()
{
    return this->x;
}

int Entity::get_y()
{
    return this->y;
}

void Entity::render(SDL_Renderer *renderer)
{
    std::cout << "Rendering in Entity class\n";
}

void Entity::update()
{
    std::cout << "Updating in Entity class\n";
}
