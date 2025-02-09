//
// Created by vanish2 on 11.12.23.
//

#ifndef LAB3_ALLENEMIESVIEW_H
#define LAB3_ALLENEMIESVIEW_H

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>
#include "Enemy.h"

class AllEnemiesView {
private:
    sf::Texture enemy_asset;

public:
    AllEnemiesView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, const std::vector<Enemy>& enemies);

    void be_loaded(const std::string& file_path);
};


#endif //LAB3_ALLENEMIESVIEW_H
