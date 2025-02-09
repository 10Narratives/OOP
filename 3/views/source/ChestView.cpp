//
// Created by vanish2 on 10.12.23.
//

#include "../include/ChestView.h"

void ChestView::set_sprite(const sf::Texture& chest_asset) {
    this->sprite.setTexture(chest_asset);
    this->sprite.setTextureRect(sf::IntRect(8,0,32,32));
}

sf::Sprite ChestView::get_sprite() const { return this->sprite; }
