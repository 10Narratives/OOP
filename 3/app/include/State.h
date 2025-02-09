//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_STATE_H
#define LAB3_STATE_H

#include "Player.h"
#include "Cell.h"
#include "Map.h"
#include "Chest.h"
#include "Enemy.h"

class State {
private:
    // Model of Player
    Player player{};
    // Model of Map
    Map map{};
    std::vector<Chest> chests;
    std::vector<Enemy> enemies;

public:
    /**
    * @breif Default constructor
    */
    State() = default;

    /**
     * @brief Getter for Player reference
     * @return Player reference
     */
    Player& get_player();

    /**
     * @brief Getter for Map reference
     * @return Map reference
     */
    Map& get_map();

    std::vector<Chest>& get_chests();

    std::vector<Enemy>& get_enemies();

    void load(const std::string& file_path);
};

#endif //LAB3_STATE_H
