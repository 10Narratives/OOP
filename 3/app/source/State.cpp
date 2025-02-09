//
// Created by vanish2 on 04.12.23.
//
#include <fstream>
#include "State.h"

#include <iostream>

Player &State::get_player() {
    return this->player;
}

Map &State::get_map() {
    return this->map;
}

std::vector<Chest>& State::get_chests() {
    return this->chests;
}

std::vector<Enemy>& State::get_enemies() {
    return this->enemies;
}

void State::load(const std::string &file_path) {
    std::ifstream file(file_path);
    if(!file.is_open())
        throw std::invalid_argument("Can not load from file, because it does not exist.");
    json data = json::parse(file);
    file.close();

    this->player.be_loaded(data["player"]);
    this->map.be_loaded(data["map"]);

    for(const auto& chest_data : data["chests"]) {
        Chest new_chest;
        new_chest.be_loaded(chest_data);
        this->chests.push_back(new_chest);
    }

    for(const auto& enemy_data : data["enemies"]) {
        Enemy new_chest;
        new_chest.be_loaded(enemy_data);
        this->enemies.push_back(new_chest);
    }
}






