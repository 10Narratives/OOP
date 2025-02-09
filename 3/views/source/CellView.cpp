//
// Created by vanish2 on 05.12.23.
//

#include "CellView.h"

void CellView::set_sprite(sf::Texture &common_texture, bool is_wall) {
    this->sprite.setTexture(common_texture);
    sf::IntRect int_rect;
    if(is_wall) {
        int_rect = {64, 0, 32, 32};
    } else {
        int_rect = {0, 0, 32, 32};
    }
    this->sprite.setTextureRect(int_rect);
}

sf::Sprite CellView::get_sprite() const { return this->sprite; }
