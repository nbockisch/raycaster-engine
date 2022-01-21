#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>

class InputHandler
{
    private:
        static InputHandler input_handler;
        const Uint8 *key_states;

        InputHandler();
        ~InputHandler();

    public:
        InputHandler(const InputHandler&) = delete;
        static InputHandler &get_handler();
        void update();
        bool is_key_pressed(SDL_Scancode key);
};
