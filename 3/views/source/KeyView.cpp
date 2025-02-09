//
// Created by vanish2 on 10.12.23.
//

#include "../include/KeyView.h"

void KeyView::set_sprite(const sf::Texture& texture) {
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

sf::Sprite KeyView::get_sprite() const {
    return this->sprite;
}
