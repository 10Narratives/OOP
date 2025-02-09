//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_MAPVIEW_H
#define LAB3_MAPVIEW_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Key.h"

#include <memory>

class MapView {
private:
    sf::Texture cell_texture;
    sf::Texture potions_texture;
    sf::Texture key_texture;
    sf::Texture equipment_texture;
    sf::Texture weapon_texture;

    void draw_cells_layer(std::shared_ptr<sf::RenderWindow>& window, Map& map);

    void draw_potion_layer(std::shared_ptr<sf::RenderWindow>& window,
                           const std::map<std::pair<int, int>, std::shared_ptr<Potion>>& potions);

    void draw_key_layer(std::shared_ptr<sf::RenderWindow>& window,
                        const std::map<std::pair<int, int>, std::shared_ptr<Key>>& keys);

    void draw_equipment_layer(std::shared_ptr<sf::RenderWindow>& window,
                              const std::map<std::pair<int, int>, std::shared_ptr<Equipment>>& keys);


    void draw_weapon_layer(std::shared_ptr<sf::RenderWindow>& window,
                              const std::map<std::pair<int, int>, std::shared_ptr<Weapon>>& keys);
public:
    MapView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, Map& map);

    void load_cells_asset(const std::string& file_path);

    void load_potions_asset(const std::string& file_path);

    void load_key_asset(const std::string& file_path);

    void load_equipment_asset(const std::string& file_path);

    void load_weapon_asset(const std::string& file_path);

    void be_loaded(const std::string& file_path);
};


#endif //LAB3_MAPVIEW_H
