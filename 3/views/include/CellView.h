//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_CELLVIEW_H
#define LAB3_CELLVIEW_H

#include <SFML/Graphics.hpp>

class CellView {
private:
    sf::Sprite sprite;

public:
    CellView() = default;

    void set_sprite(sf::Texture& common_texture, bool is_wall);

    sf::Sprite get_sprite() const;
};


#endif //LAB3_CELLVIEW_H
