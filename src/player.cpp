/**
 * @author Nathan Bockisch
 *
 * Source file for the Player class, containing all the class function and 
 * variable definitions
 **/

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <cmath>
#include <iostream>
#include <math.h>
#include "headers/player.hpp"

Player::Player(double x, double y)
{
    this->set_x(x); this->set_y(y); this->set_angle(0); }

void Player::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    double next_x = std::cos(this->get_angle()) * 100 + this->get_x();
    double next_y = std::sin(this->get_angle()) * 100 + this->get_y();
    SDL_RenderDrawLine(renderer, this->get_x(), this->get_y(), next_x, next_y);
}

void Player::update()
{
    if (InputHandler::get_handler().is_key_pressed(SDL_SCANCODE_LEFT))
        this->change_angle(-0.005); 
    else if (InputHandler::get_handler().is_key_pressed(SDL_SCANCODE_RIGHT))
        this->change_angle(0.005);
    else if (InputHandler::get_handler().is_key_pressed(SDL_SCANCODE_UP))
        this->move_forward(1.1);
    else if (InputHandler::get_handler().is_key_pressed(SDL_SCANCODE_DOWN))
        this->move_back(1.1);
}

void Player::move_forward(double amount)
{ 
    double new_x = std::cos(this->get_angle()) * amount;
    double new_y = std::sin(this->get_angle()) * amount;
    
    this->set_x(this->get_x() + new_x);
    this->set_y(this->get_y() + new_y);
}

void Player::move_back(double amount)
{ 
    double new_x = std::cos(this->get_angle()) * amount;
    double new_y = std::sin(this->get_angle()) * amount;
    
    this->set_x(this->get_x() - new_x);
    this->set_y(this->get_y() - new_y);
}

void Player::change_angle(double change)
{
    double pi = 3.141592653589793238463;
    double new_angle = this->get_angle() + change;

    // Keep new angle within circle
    if (new_angle < 0) 
        new_angle += 2 * pi;
    else if (new_angle > 2 * pi)
        new_angle -= 2 * pi;

    this->set_angle(new_angle);
}

void Player::set_angle(double angle)
{
    this->angle = angle;
}

double Player::get_angle()
{
    return this->angle;
}

Player::~Player()
{
}
