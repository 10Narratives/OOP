//
// Created by vanish2 on 04.12.23.
//
#include "App.h"
#include "ViewState.h"
#include <iostream>
#include <thread>

constexpr int fps = 60;
constexpr auto refresh_rate = std::chrono::microseconds(1000) / fps;

constexpr sf::Int64 tick_time = 100 * 1000;

constexpr int enemy_rate = 700;

void App::run() {
    std::shared_ptr<State> state = std::make_shared<State>();
    state->load("files/state_init.json");

    std::shared_ptr<ViewState> view_state = std::make_shared<ViewState>();
    view_state->set_state(state);
    view_state->load("files/view_state.json");

    std::shared_ptr<Service> service = std::make_shared<Service>(state);

    this->controller = std::make_shared<Controller>(service, view_state);

    sf::Clock clock;

    int curr_enemy_rate = 0;
    while (this->window->isOpen()) {
        clock.restart();
        sf::Event event{};

        if(this->window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                this->window->close();
            } else {
                this->controller->process_input(event);
            }
        }

        if(curr_enemy_rate == enemy_rate) {
            this->controller->trigger_update();
            curr_enemy_rate = 0;
        }
        curr_enemy_rate++;

        this->controller->trigger_redraw(this->window);
    }
}
