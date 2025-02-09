#include <iostream>
#include <fstream>

#include "App.h"

int main() {
    try {
        App game;
        game.run();
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
