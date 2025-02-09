//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_APP_H
#define LAB3_APP_H

#include <memory>
#include <SFML/Graphics.hpp>

#include <Controller.h>
#include <Service.h>
#include <State.h>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "Lab 3"

class App {
private:
    std::shared_ptr<sf::RenderWindow> window
    = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);

    std::shared_ptr<Controller> controller;

public:
    App() = default;
    void run();
};

#endif //LAB3_APP_H
