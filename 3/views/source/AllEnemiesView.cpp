//
// Created by vanish2 on 11.12.23.
//

#include "../include/AllEnemiesView.h"
#include "EnemyView.h"

void AllEnemiesView::draw(std::shared_ptr<sf::RenderWindow> &window, const std::vector<Enemy> &enemies) {
    EnemyView chest_views;
    for(const auto& chest : enemies) {
        chest_views.set_sprite(this->enemy_asset);
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

void AllEnemiesView::be_loaded(const std::string &file_path) {
    this->enemy_asset.loadFromFile(file_path);
}