//
// Created by vanish2 on 11.12.23.
//

#ifndef LAB3_ENEMYVIEW_H
#define LAB3_ENEMYVIEW_H

#include <SFML/Graphics.hpp>

class EnemyView {
private:
    sf::Sprite sprite;

public:
    EnemyView() = default;

    sf::Sprite get_sprite() const;

    void set_sprite(const sf::Texture& enemy_asset);
};


#endif //LAB3_ENEMYVIEW_H
