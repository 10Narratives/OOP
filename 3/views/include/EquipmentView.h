//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_EQUIPMENTVIEW_H
#define LAB3_EQUIPMENTVIEW_H

#include <SFML/Graphics.hpp>
#include "Equipment.h"

class EquipmentView {
private:
    sf::Sprite sprite;

public:
    EquipmentView() = default;

    void set_sprite(const sf::Texture& texture, const std::shared_ptr<Equipment>& data);

    sf::Sprite get_sprite() const;
};


#endif //LAB3_EQUIPMENTVIEW_H
