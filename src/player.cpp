#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include "headers/player.hpp"

Player::Player(int x, int y)
{
    this->set_x(x);
    this->set_y(y);
}

void Player::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, this->get_x(), this->get_y(), this->get_x(), this->get_y() + 100);
}

void Player::update()
{
    /* std::cout << "Updating in the Player class\n"; */
}

Player::~Player()
{
}
