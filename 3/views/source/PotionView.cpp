//
// Created by vanish2 on 09.12.23.
//

#include "PotionView.h"

void PotionView::set_sprite(const sf::Texture& potion_asset, std::shared_ptr<Potion> data) {
    this->sprite.setTexture(potion_asset);
    if(data->get_potion_effect().health > 0)
        this->sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
    if(data->get_potion_effect().health_limit > 0) {
        this->sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
    }
    if(data->get_potion_effect().power > 0) {
        this->sprite.setTextureRect(sf::IntRect(64, 32, 32, 32));
    }
}

sf::Sprite PotionView::get_sprite() const {
    return this->sprite;
}

