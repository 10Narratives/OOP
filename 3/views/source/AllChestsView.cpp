//
// Created by vanish2 on 10.12.23.
//

#include "../include/AllChestsView.h"

void AllChestsView::draw(std::shared_ptr<sf::RenderWindow> &window, const std::vector<Chest>& chests) {
    ChestView chest_views;
    for(const auto& chest : chests) {
        chest_views.set_sprite(this->chest_asset);
        sf::Sprite chest_sprite = chest_views.get_sprite();
        float x_position = chest.get_x() * 32;
        float y_position = chest.get_y() * 32;

        chest_sprite.setPosition(
                x_position,
                y_position
                );
        window->draw(chest_sprite);
    }
}

void AllChestsView::be_loaded(const std::string &file_path) {
    this->chest_asset.loadFromFile(file_path);
}
