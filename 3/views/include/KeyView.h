//
// Created by vanish2 on 10.12.23.
//

#ifndef LAB3_KEYVIEW_H
#define LAB3_KEYVIEW_H

#include <memory>
#include <SFML/Graphics.hpp>

class KeyView {
private:
    sf::Sprite sprite;

public:
    KeyView() = default;

    void set_sprite(const sf::Texture& texture);

    sf::Sprite get_sprite() const;
};


#endif //LAB3_KEYVIEW_H
