/**
 * @author Nathan Bockisch
 *
 * Source file for the Player class, containing all the class function and 
 * variable definitions
 **/

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
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
    if (InputHandler::get_handler().is_key_pressed(SDL_SCANCODE_LEFT))
        std::cout << "Pressing left!\n";
    else
        std::cout << "Not pressing left!\n";
}

Player::~Player()
{
}
