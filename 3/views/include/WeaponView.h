//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_WEAPONVIEW_H
#define LAB3_WEAPONVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Weapon.h"

class WeaponView {
private:
    sf::Sprite sprite;

public:
    WeaponView() = default;

    void set_sprite(const sf::Texture& weapon_asset, const std::shared_ptr<Weapon>& weapon);

    sf::Sprite get_sprite() const;
};


#endif //LAB3_WEAPONVIEW_H
