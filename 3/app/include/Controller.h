//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_CONTROLLER_H
#define LAB3_CONTROLLER_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "Service.h"
#include "ViewState.h"

class Controller {
private:
    std::shared_ptr<Service> service_ = std::make_shared<Service>();
    std::shared_ptr<ViewState> view_state = std::make_shared<ViewState>();

public:
    Controller() = default;
    Controller(const std::shared_ptr<Service>& service, const std::shared_ptr<ViewState>& view_state);

    void process_input(const sf::Event& event);
    void trigger_update();
    void trigger_redraw(std::shared_ptr<sf::RenderWindow>& window);
};

#endif //LAB3_CONTROLLER_H
