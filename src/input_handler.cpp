#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>

#include "headers/input_handler.hpp"

InputHandler &InputHandler::get_handler()
{
    static InputHandler handler_instance;
    return handler_instance;
}

void InputHandler::update()
{
    key_states = SDL_GetKeyboardState(0);
}

bool InputHandler::is_key_pressed(SDL_Scancode key)
{
    if (key_states)
        if (key_states[key] == 1)
            return true;

    return false;
}

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}
