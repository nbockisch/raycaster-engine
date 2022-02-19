/**
 * @author Nathan Bockisch
 *
 * Source file for the Entity class, containing all the class definitions
 * inherited by all entities, including the Player class
 **/

#include <SDL2/SDL_render.h>
#include <iostream>
#include "headers/entity.hpp"

void Entity::set_x(double x)
{
    this->x = x;
}

void Entity::set_y(double y)
{
    this->y = y;
}

double Entity::get_x()
{
    return this->x;
}

double Entity::get_y()
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
