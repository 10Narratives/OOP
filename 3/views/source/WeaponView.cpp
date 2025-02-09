//
// Created by vanish2 on 12.12.23.
//

#include "../include/WeaponView.h"
#include "ArtifactWeapon.h"
#include "EnchantedWeapon.h"
#include "MixedWeapon.h"

void WeaponView::set_sprite(const sf::Texture& weapon_asset, const std::shared_ptr<Weapon>& weapon) {
    this->sprite.setTexture(weapon_asset);
    std::shared_ptr<ArtifactWeapon> artifact_weapon = std::dynamic_pointer_cast<ArtifactWeapon>(weapon);
    std::shared_ptr<EnchantedWeapon> enchanted_weapon = std::dynamic_pointer_cast<EnchantedWeapon>(weapon);
    std::shared_ptr<MixedWeapon> mixed_weapon = std::dynamic_pointer_cast<MixedWeapon>(weapon);

    if(artifact_weapon) {
        this->sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
    } else if(enchanted_weapon) {
        this->sprite.setTextureRect(sf::IntRect(0, 128, 32, 32));
    } else if(mixed_weapon) {
        this->sprite.setTextureRect(sf::IntRect(0, 96, 32, 32));
    } else {
        this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    }
}

sf::Sprite WeaponView::get_sprite() const {
    return this->sprite;
}