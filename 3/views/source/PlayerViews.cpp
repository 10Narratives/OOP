//
// Created by vanish2 on 04.12.23.
//
#include "PlayerView.h"

sf::Sprite PlayerView::get_sprite() const { return this->sprite; }

void PlayerView::be_loaded(const std::string& file_path) {
    this->texture.loadFromFile(file_path);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void PlayerView::draw(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    float player_position_x = player.get_x() * 32;
    float player_position_y = player.get_y() * 32;

    this->sprite.setPosition(
            player_position_x,
            player_position_y);

    window->draw(this->sprite);
}
