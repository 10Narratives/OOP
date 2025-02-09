//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_PLAYER_H
#define LAB3_PLAYER_H

#include "Moveable.h"
#include "Creature.h"

#include <vector>
#include <map>
#include <memory>

#include <utility>

#include "Potion.h"
#include "Weapon.h"
#include "Equipment.h"

struct Inventory{
    std::vector<std::pair<bool, std::shared_ptr<Potion>>> potions;
    std::map<std::string, std::pair<bool, std::shared_ptr<Equipment>>> equipments;
    std::pair<bool, std::shared_ptr<Weapon>> weapon;

};

class Player : public Moveable, public Creature{
private:
    int max_exp = 0, level = 0, upgrade_points = 0;
    int key_amount_ = 0;

    Inventory inv;

    void reduce_upgrade_points();
public:
    Player() = default;
    ~Player() override = default;

    [[nodiscard]] int get_max_exp() const;

    [[nodiscard]] int get_level() const;

    [[nodiscard]] int get_upgrade_points() const;

    void upgrade_primary(Primary upgrade_value);

    void inc_exp(int inc_value);

    [[nodiscard]] std::vector<std::pair<bool, std::shared_ptr<Potion>>>& get_potions();

    void take_potion(std::shared_ptr<Potion>&& potion);

    std::shared_ptr<Potion> throw_potion(unsigned index);

    void drink(unsigned index);

    [[nodiscard]] int get_key_amount() const;

    void inc_key_amount(int change);

    void reduce_key_amount();

    std::pair<bool, std::shared_ptr<Weapon>>& get_weapon(); // !

    void take_weapon(std::shared_ptr<Weapon>&& weapon); // !

    std::shared_ptr<Weapon> throw_weapon(); // !

    std::map<std::string, std::pair<bool, std::shared_ptr<Equipment>>>& get_equipments(); // !!

    void take_equipment(std::shared_ptr<Equipment>&& equipment); // !!

    std::shared_ptr<Equipment> throw_equipment(const std::string& placement); // !!

    void be_loaded(json data) override;

    [[nodiscard]] json be_saved() const override;

    void be_moved(std::pair<int, int> new_coords) override;

    int deal_damage() override;

    int resist() override;
};

#endif //LAB3_PLAYER_H
