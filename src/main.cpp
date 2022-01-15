#include <iostream>

#include "headers/game.hpp"

const int WIDTH = 640;
const int HEIGHT = 480;

int main() {
    Game game = Game("Raycasting Engine", 640, 480, 60);

    if (game.run() != 0) {
        return 1;
    }

    return 0;
}
