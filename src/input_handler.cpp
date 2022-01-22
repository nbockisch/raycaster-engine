#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_events.h>

#include "headers/input_handler.hpp"

InputHandler &InputHandler::get_handler()
{
    static InputHandler handler_instance;
    return handler_instance;
}

void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                received_quit = true;
                break;
            case SDL_KEYDOWN:
                key_states = (Uint8 *)SDL_GetKeyboardState(0);
                break;
            case SDL_KEYUP:
                key_states = (Uint8 *)SDL_GetKeyboardState(0);
                break;
            default:
                break;
        }
    }
}

bool InputHandler::is_key_pressed(SDL_Scancode key)
{
    if (key_states != 0)
        if (key_states[key] == 1)
            return true;

    return false;
}

bool InputHandler::should_quit()
{
    return received_quit;
}

InputHandler::InputHandler()
{
    received_quit = false;
}

InputHandler::~InputHandler()
{
}
