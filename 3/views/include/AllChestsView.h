//
// Created by vanish2 on 10.12.23.
//

#ifndef LAB3_ALLCHESTSVIEW_H
#define LAB3_ALLCHESTSVIEW_H


#include <memory>
#include "ChestView.h"
#include "Chest.h"

#include <SFML/Graphics.hpp>

class AllChestsView {
private:
    sf::Texture chest_asset;

public:
    AllChestsView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, const std::vector<Chest>& chests);

    void be_loaded(const std::string& file_path);
};


#endif //LAB3_ALLCHESTSVIEW_H
