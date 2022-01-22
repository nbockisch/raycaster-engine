#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>

class InputHandler
{
    private:
        static InputHandler input_handler;
        Uint8 *key_states;
        bool received_quit;

        InputHandler();
        ~InputHandler();

    public:
        InputHandler(const InputHandler&) = delete;
        static InputHandler &get_handler();
        void update();
        bool is_key_pressed(SDL_Scancode key);
        bool should_quit();
};
