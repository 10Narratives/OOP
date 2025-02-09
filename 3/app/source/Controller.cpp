//
// Created by vanish2 on 04.12.23.
//

#include <iostream>
#include <thread>
#include "Controller.h"

constexpr sf::Int64 tick_time = 100 * 1000;

void Controller::process_input(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.scancode == sf::Keyboard::Scan::W) {
            this->service_->take_ground({0, -1});
        }
        if (event.key.scancode == sf::Keyboard::Scan::A) {
            this->service_->take_ground({-1, 0});
        }
        if (event.key.scancode == sf::Keyboard::Scan::S) {
            this->service_->take_ground({0, 1});
        }
        if (event.key.scancode == sf::Keyboard::Scan::D) {
            this->service_->take_ground({1, 0});
        }
        if (event.key.scancode == sf::Keyboard::Scan::Q) {
            this->service_->try_take();
        }
        if (event.key.scancode == sf::Keyboard::Scan::E) {
            this->service_->try_throw();
        }
        if (event.key.scancode == sf::Keyboard::Scan::R) {
            this->service_->drink();
        }
        if (event.key.scancode == sf::Keyboard::Scan::Z) {
            this->service_->upgrade_parameter(Parameters::Power);
        }
        if (event.key.scancode == sf::Keyboard::Scan::X) {
            this->service_->upgrade_parameter(Parameters::Ability);
        }
        if (event.key.scancode == sf::Keyboard::Scan::C) {
            this->service_->upgrade_parameter(Parameters::Endurance);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            this->service_->select({event.mouseButton.x, event.mouseButton.y});
        }
    }
}

Controller::Controller(const std::shared_ptr<Service> &service, const std::shared_ptr<ViewState>& view_state)
: service_(service), view_state(view_state) {}

void Controller::trigger_redraw(std::shared_ptr<sf::RenderWindow> &window) {
    this->view_state->redraw(window);
}

void Controller::trigger_update() {
    this->service_->update_all_enemies();;
}
