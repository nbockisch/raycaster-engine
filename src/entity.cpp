/**
 * @author Nathan Bockisch
 *
 * Source file for the Entity class, containing all the class definitions
 * inherited by all entities, including the Player class
 **/

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

/* Abstract functions for rendering and updating, implemented in child classes 
 */
void Entity::render(SDL_Renderer *renderer)
{
}

void Entity::update()
{
}
