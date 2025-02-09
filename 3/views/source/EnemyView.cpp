//
// Created by vanish2 on 11.12.23.
//

#include "EnemyView.h"

sf::Sprite EnemyView::get_sprite() const {
    return this->sprite;
}

void EnemyView::set_sprite(const sf::Texture &enemy_asset) {
    this->sprite.setTexture(enemy_asset);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}
