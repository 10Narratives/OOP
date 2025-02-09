//
// Created by vanish2 on 12.12.23.
//

#include "../include/EquipmentView.h"
#include "ArtifactEquipment.h"

void EquipmentView::set_sprite(const sf::Texture& texture, const std::shared_ptr<Equipment>& data) {
    this->sprite.setTexture(texture);

    if(data == nullptr) return;

    std::shared_ptr<ArtifactEquipment> artifact = std::dynamic_pointer_cast<ArtifactEquipment>(data);
    if(artifact) {
        if(data->get_placement() == "head") {
            this->sprite.setTextureRect(sf::IntRect(32,32,32,32));
        }
        if(data->get_placement() == "body") {
            this->sprite.setTextureRect(sf::IntRect(0,32,32,32));
        }
        if(data->get_placement() == "legs") {
            this->sprite.setTextureRect(sf::IntRect(96,32,32,32));
        }
        if(data->get_placement() == "hands") {
            this->sprite.setTextureRect(sf::IntRect(128,32,32,32));
        }
    } else {
        if(data->get_placement() == "head") {
            this->sprite.setTextureRect(sf::IntRect(32,0,32,32));
        }
        if(data->get_placement() == "body") {
            this->sprite.setTextureRect(sf::IntRect(0,0,32,32));
        }
        if(data->get_placement() == "legs") {
            this->sprite.setTextureRect(sf::IntRect(96,0,32,32));
        }
        if(data->get_placement() == "hands") {
            this->sprite.setTextureRect(sf::IntRect(128,0,32,32));
        }
    }

}

sf::Sprite EquipmentView::get_sprite() const {
    return this->sprite;
}
