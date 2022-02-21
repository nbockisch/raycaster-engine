#include <iostream>

#include "headers/game.hpp"

const int WIDTH = 640 * 2;
const int HEIGHT = 480 * 2;

int main() {
    Game game = Game("Raycasting Engine", WIDTH, HEIGHT, 60);

    if (game.run() != 0) {
        return 1;
    }

    return 0;
}
