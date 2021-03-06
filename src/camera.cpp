/**
 * @author Nathan Bockisch
 *
 * Source file for the Camera class, containing all the class definitions
 * The camera contains all the functions for raycasting and rendering the
 * player's view
 **/

#include "headers/camera.hpp"

Camera::Camera(Player *player, Map *map, double fov)
{
    this->player = player;
    this->map = map;
    this->fov = fov;
}

void Camera::update()
{
}

void Camera::render(SDL_Renderer *renderer)
{
}

Camera::~Camera()
{
}
