#include <sstream>
#include <thread>
#include <chrono>
#include <iostream>

#include <cstdlib> 

#include "include/gameOfLife.hpp"

int main() {
    game_of_life::GameOfLife game(30, 30);
    // glider
    game.revive(1, 0);
    game.revive(2, 1);
    game.revive(2, 2);
    game.revive(1, 2);
    game.revive(0, 2);

    std::string out;

    while (true) {
        out = std::string(50, '\n');
        for (size_t y = 0; y < game.height(); ++y) {
            for (size_t x = 0; x < game.width(); ++x) {
                out.push_back(game.isAlive(x, y) ? '@' : '*');
                out.push_back(' ');
            }
            out.push_back('\n');
        }


        std::cout << out;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        game.renderNextGameFieldState();
    }

}   