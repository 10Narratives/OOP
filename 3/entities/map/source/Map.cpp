//
// Created by vanish2 on 05.12.23.
//

#include <iostream>
#include <fstream>
#include "Map.h"
#include "Weapon.h"

void Map::be_loaded(const json& data) {
    for(unsigned i = 0; i < 25; i++) {
        std::vector<Cell> new_line;
        for(unsigned j = 0; j < 40; j++) {
            new_line.push_back(Cell{{j, i}, false});
        }
        this->data_.push_back(new_line);
    }

    for(auto cell_data : data) {
        int x = cell_data["x"];
        int y = cell_data["y"];
        this->data_[y][x].be_loaded(cell_data);
    }
}

std::vector<std::vector<Cell>>& Map::get_cells() {
    return this->data_;
}

std::map<std::pair<int, int>, std::shared_ptr<Potion>> Map::get_all_potions() {
    std::shared_ptr<Potion> read_potion;
    std::map<std::pair<int, int>, std::shared_ptr<Potion>> all_potions;
    for(const auto& line : this->data_) {
        for(const auto& cell : line) {
            read_potion = std::dynamic_pointer_cast<Potion>(cell.get_inner_object());
            if(read_potion) {
                all_potions.insert({{cell.get_x(), cell.get_y()}, read_potion});
            }
        }
    }
    return all_potions;
}

std::map<std::pair<int, int>, std::shared_ptr<Key>> Map::get_all_keys() {
    std::shared_ptr<Key> read_key;
    std::map<std::pair<int, int>, std::shared_ptr<Key>> all_keys;
    for(const auto& line : this->data_) {
        for(const auto& cell : line) {
            read_key = std::dynamic_pointer_cast<Key>(cell.get_inner_object());
            if(read_key) {
                all_keys.insert({{cell.get_x(), cell.get_y()}, read_key});
            }
        }
    }
    return all_keys;
}

std::map<std::pair<int, int>, std::shared_ptr<Equipment>> Map::get_all_equipments() {
    std::shared_ptr<Equipment> read_equipment;
    std::map<std::pair<int, int>, std::shared_ptr<Equipment>> all_equipments;
    for(const auto& line : this->data_) {
        for(const auto& cell : line) {
            read_equipment = std::dynamic_pointer_cast<Equipment>(cell.get_inner_object());
            if(read_equipment) {
                all_equipments.insert({{cell.get_x(), cell.get_y()}, read_equipment});
            }
        }
    }
    return all_equipments;
}

std::map<std::pair<int, int>, std::shared_ptr<Weapon>> Map::get_all_weapons() {
    std::shared_ptr<Weapon> read_weapon;
    std::map<std::pair<int, int>, std::shared_ptr<Weapon>> all_weapons;
    for(const auto& line : this->data_) {
        for(const auto& cell : line) {
            read_weapon = std::dynamic_pointer_cast<Weapon>(cell.get_inner_object());
            if(read_weapon) {
                all_weapons.insert({{cell.get_x(), cell.get_y()}, read_weapon});
            }
        }
    }
    return all_weapons;
}
