//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_PLAYERINFOVIEW_H
#define LAB3_PLAYERINFOVIEW_H

#include<SFML/Graphics.hpp>
#include <memory>
#include "Player.h"

class PlayerInfoView {
private:
    std::pair<float,float> position; // position of top left corner of text box
    sf::Font font;

public:
    PlayerInfoView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, Player &player);

    void set_position(std::pair<float, float> new_position);

    void be_loaded(const std::string& file_path);
};


#endif //LAB3_PLAYERINFOVIEW_H
