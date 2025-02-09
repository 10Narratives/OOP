//
// Created by vanish2 on 09.12.23.
//

#ifndef LAB3_PLAYERINVVIEW_H
#define LAB3_PLAYERINVVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"

class PlayerInvView {
private:
    sf::Texture potions_asset;
    sf::Texture weapon_asset;
    sf::Texture equipment_asset;
    sf::Font font;

    void draw_potions(std::shared_ptr<sf::RenderWindow>& window, Player& inventory);

    void draw_weapon(std::shared_ptr<sf::RenderWindow>& window, Player& inventory);

    void draw_element(std::shared_ptr<sf::RenderWindow>& window,
                      const std::pair<bool, std::shared_ptr<Equipment>>& equipment);

    void draw_equipment(std::shared_ptr<sf::RenderWindow>& window, Player& inventory);
public:
    PlayerInvView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, Player& inventory);

    void load_potions_asset(const std::string& file_path);

    void load_weapon_asset(const std::string& file_path);

    void load_equipment_asset(const std::string& file_path);

    void load_font(const std::string& file_path);
};


#endif //LAB3_PLAYERINVVIEW_H
