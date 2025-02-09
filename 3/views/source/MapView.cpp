//
// Created by vanish2 on 05.12.23.
//

#include "MapView.h"
#include "CellView.h"
#include "PotionView.h"
#include "KeyView.h"
#include "EquipmentView.h"
#include "WeaponView.h"

#include <iostream>

void MapView::draw(std::shared_ptr<sf::RenderWindow> &window, Map& map) {
    this->draw_cells_layer(window, map);
    this->draw_potion_layer(window, map.get_all_potions());
    this->draw_key_layer(window, map.get_all_keys());
    this->draw_equipment_layer(window, map.get_all_equipments());
    this->draw_weapon_layer(window, map.get_all_weapons());
}

void MapView::be_loaded(const std::string &file_path) {
    this->cell_texture.loadFromFile(file_path);
}

void MapView::draw_cells_layer(std::shared_ptr<sf::RenderWindow> &window, Map &map) {
    for(auto line : map.get_cells()) {
        for(auto& cell : line) {
            CellView cell_view;
            cell_view.set_sprite(this->cell_texture, bool(cell));
            sf::Sprite cell_sprite = cell_view.get_sprite();
            float x_position = cell.get_x() * 32;
            float y_position = cell.get_y() * 32;

            cell_sprite.setPosition(
                    x_position,
                    y_position);
            window->draw(cell_sprite);
        }
    }
}

void MapView::draw_potion_layer(std::shared_ptr<sf::RenderWindow> &window,
                                const std::map<std::pair<int, int>, std::shared_ptr<Potion>> &potions) {
    PotionView potion_view;
    for(const auto& potion : potions) {
        potion_view.set_sprite(this->potions_texture, potion.second);
        sf::Sprite potion_sprite = potion_view.get_sprite();
        float x_position = potion.first.first * 32;
        float y_position = potion.first.second * 32;

        potion_sprite.setPosition(
                x_position,
                y_position
        );
        window->draw(potion_sprite);
    }
}

void MapView::draw_key_layer(std::shared_ptr<sf::RenderWindow> &window,
                             const std::map<std::pair<int, int>, std::shared_ptr<Key>> &keys) {
    KeyView key_view;
    for(const auto& key : keys) {
        key_view.set_sprite(this->key_texture);
        sf::Sprite key_sprite = key_view.get_sprite();
        float x_position = key.first.first * 32;
        float y_position = key.first.second * 32;

        key_sprite.setPosition(
                x_position,
                y_position
        );
        window->draw(key_sprite);

    }
}


void MapView::draw_equipment_layer(std::shared_ptr<sf::RenderWindow> &window,
                                   const std::map<std::pair<int, int>, std::shared_ptr<Equipment>> &equipments) {
    EquipmentView equipment_view;
    for(const auto& equipment : equipments) {
        equipment_view.set_sprite(this->equipment_texture, equipment.second);
        sf::Sprite equipment_sprite = equipment_view.get_sprite();
        float x_position = equipment.first.first * 32;
        float y_position = equipment.first.second * 32;

        equipment_sprite.setPosition(
                x_position,
                y_position
        );
        window->draw(equipment_sprite);

    }
}

void MapView::draw_weapon_layer(std::shared_ptr<sf::RenderWindow> &window,
                                const std::map<std::pair<int, int>, std::shared_ptr<Weapon>> &weapons) {
    WeaponView weapon_view;
    for(const auto & weapon : weapons) {
        weapon_view.set_sprite(this->weapon_texture, weapon.second);
        sf::Sprite weapon_sprite = weapon_view.get_sprite();
        float x_position = weapon.first.first * 32;
        float y_position = weapon.first.second * 32;

        weapon_sprite.setPosition(
                x_position,
                y_position
        );
        window->draw(weapon_sprite);

    }
}

void MapView::load_cells_asset(const std::string &file_path) {
    this->cell_texture.loadFromFile(file_path);
}

void MapView::load_potions_asset(const std::string &file_path) {
    this->potions_texture.loadFromFile(file_path);
}

void MapView::load_key_asset(const std::string &file_path) {
    this->key_texture.loadFromFile(file_path);
}

void MapView::load_equipment_asset(const std::string &file_path) {
    this->equipment_texture.loadFromFile(file_path);
}

void MapView::load_weapon_asset(const std::string &file_path) {
    this->weapon_texture.loadFromFile(file_path);
}






