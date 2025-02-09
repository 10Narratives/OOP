//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_PLAYERVIEW_H
#define LAB3_PLAYERVIEW_H

#include <SFML/Graphics.hpp>

#include <memory>
#include "Player.h"

class PlayerView {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    PlayerView() = default;

    sf::Sprite get_sprite() const;

    void draw(std::shared_ptr<sf::RenderWindow>& window, Player& player);

    void be_loaded(const std::string& file_path);
};

#endif //LAB3_PLAYERVIEW_H
