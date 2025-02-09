//
// Created by vanish2 on 09.12.23.
//

#ifndef LAB3_POTIONVIEW_H
#define LAB3_POTIONVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Potion.h"

class PotionView {
private:
    sf::Sprite sprite;

public:
    PotionView() = default;

    void set_sprite(const sf::Texture& potion_asset, std::shared_ptr<Potion> data);

    sf::Sprite get_sprite() const;
};


#endif //LAB3_POTIONVIEW_H
