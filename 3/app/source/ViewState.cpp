//
// Created by vanish2 on 04.12.23.
//
#include "ViewState.h"
#include <iostream>
#include <fstream>

void ViewState::set_state(const std::shared_ptr<State> &state) {
    this->state_ = state;
}

void ViewState::redraw(std::shared_ptr<sf::RenderWindow>& window) {
    window->clear();

    this->map_view.draw(window, this->state_->get_map());

    this->all_chests_view.draw(window, this->state_->get_chests());
    this->all_enemies_view.draw(window, this->state_->get_enemies());

    this->player_view.draw(window, this->state_->get_player());
    this->player_info_view.set_position({1290, 0});
    this->player_info_view.draw(window, this->state_->get_player());
    this->player_inv_view.draw(window, this->state_->get_player());


    window->display();
}

void ViewState::load(const std::string &file_path) {
    std::ifstream file(file_path);
    if(!file.is_open())
        throw std::invalid_argument("Can not load from file, because it does not exist.");
    json data = json::parse(file);
    file.close();


    this->map_view.load_cells_asset(data["map"].get<std::string>());
    this->map_view.load_potions_asset(data["potions"].get<std::string>());
    this->map_view.load_key_asset(data["key"].get<std::string>());
    this->map_view.load_equipment_asset(data["equipment"].get<std::string>());
    this->map_view.load_weapon_asset(data["weapon"].get<std::string>());

    this->player_view.be_loaded(data["player"].get<std::string>());
    this->player_info_view.be_loaded(data["font"].get<std::string>());
    this->player_inv_view.load_potions_asset(data["potions"].get<std::string>());
    this->player_inv_view.load_weapon_asset(data["weapon"].get<std::string>());
    this->player_inv_view.load_equipment_asset(data["equipment"].get<std::string>());
    this->player_inv_view.load_font(data["font"].get<std::string>());

    this->all_chests_view.be_loaded(data["chest"].get<std::string>());
    this->all_enemies_view.be_loaded(data["enemy"].get<std::string>());
}
