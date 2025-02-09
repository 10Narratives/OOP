//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_MAP_H
#define LAB3_MAP_H

#include <memory>
#include <vector>
#include <map>
#include "Cell.h"
#include "Potion.h"
#include "Key.h"
#include "Equipment.h"
#include "Weapon.h"

class Map {
private:
    std::vector<std::vector<Cell>> data_;

public:
    Map() = default;

    std::vector<std::vector<Cell>>& get_cells();

    std::map<std::pair<int, int>, std::shared_ptr<Potion>> get_all_potions();

    std::map<std::pair<int, int>, std::shared_ptr<Key>> get_all_keys();

    std::map<std::pair<int, int>, std::shared_ptr<Equipment>> get_all_equipments();

    std::map<std::pair<int, int>, std::shared_ptr<Weapon>> get_all_weapons();


    void be_loaded(const json& data);
};


#endif //LAB3_MAP_H
