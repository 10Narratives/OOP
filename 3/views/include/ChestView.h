//
// Created by vanish2 on 10.12.23.
//

#ifndef LAB3_CHESTVIEW_H
#define LAB3_CHESTVIEW_H


#include <SFML/Graphics.hpp>


class ChestView {
private:
    sf::Sprite sprite;

public:
    ChestView() = default;

    void set_sprite(const sf::Texture& chest_asset);


    sf::Sprite get_sprite() const;
};


#endif //LAB3_CHESTVIEW_H
