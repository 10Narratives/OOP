//
// Created by vanish2 on 04.12.23.
//
#include <iostream>
#include "Player.h"
#include "ArtifactWeapon.h"
#include "MixedWeapon.h"
#include "ArtifactEquipment.h"

void Player::be_loaded(json data) {
    Creature::be_loaded(data);
    this->max_exp = data["max_exp"].get<int>();
    this->level = data["level"].get<int>();
    this->upgrade_points = data["upgrade_points"].get<int>();
}

json Player::be_saved() const {
    json save_object =  Creature::be_saved();
    save_object["max_exp"] = this->max_exp;
    save_object["level"] = this->level;
    save_object["upgrade_points"] = this->upgrade_points;
    return save_object;
}


void Player::be_moved(std::pair<int, int> new_coords) {
    this->coords = new_coords;
}

void Player::inc_exp(int inc_value) {
    this->exp += inc_value;
    if(this->exp >= this->max_exp) {
        while(this->exp >= this->max_exp) {
            this->exp -= this->max_exp;
            this->max_exp += 25;
            this->level++;
            this->upgrade_points *= 5;
        }
    }
}

void Player::upgrade_primary(Primary upgrade_value) {
    this->primary = this->primary + upgrade_value;
    this->compute_secondary();
    this->reduce_upgrade_points();
}

int Player::get_max_exp() const {
    return this->max_exp;
}

int Player::get_level() const {
    return this->level;
}

int Player::get_upgrade_points() const {
    return this->upgrade_points;
}

std::vector<std::pair<bool, std::shared_ptr<Potion>>>& Player::get_potions() {
    return this->inv.potions;
}

int Player::get_key_amount() const {
    return this->key_amount_;
}

void Player::reduce_upgrade_points() {
    this->upgrade_points--;
}

void Player::take_potion(std::shared_ptr<Potion>&& potion) {
    this->inv.potions.emplace_back(false, potion);
}

std::shared_ptr<Potion> Player::throw_potion(unsigned int index) {
    std::pair<bool, std::shared_ptr<Potion>> result = this->inv.potions.at(index);
    this->inv.potions.erase(this->inv.potions.begin() + index, this->inv.potions.begin() + index + 1);
    return result.second;
}


void Player::drink(unsigned int index) {
    auto potion = this->inv.potions.at(index);
    auto potion_effect = potion.second->be_drunk();
    this->primary = this->primary + potion_effect;
    this->inv.potions.erase(this->inv.potions.begin() + index, this->inv.potions.begin() + index + 1);
    this->compute_secondary();
}

void Player::inc_key_amount(int change) {
    this->key_amount_ += change;
}

void Player::reduce_key_amount() {
    this->key_amount_--;
    if(key_amount_ < 0)
        key_amount_ = 0;
}

std::pair<bool, std::shared_ptr<Weapon>> &Player::get_weapon() {
    return this->inv.weapon;
}

void Player::take_weapon(std::shared_ptr<Weapon> &&weapon) {
    this->inv.weapon.second = weapon;
    std::shared_ptr<ArtifactWeapon> a_weapon = std::dynamic_pointer_cast<ArtifactWeapon>(weapon);
    if(a_weapon) {
        this->influence = this->influence + a_weapon->get_influence();
        this->compute_secondary();
    }

    std::shared_ptr<MixedWeapon> m_weapon = std::dynamic_pointer_cast<MixedWeapon>(weapon);
    if(m_weapon) {
        this->influence = this->influence + m_weapon->get_influence();
        this->compute_secondary();
    }
}

std::shared_ptr<Weapon> Player::throw_weapon() {
    std::shared_ptr<Weapon> result = this->inv.weapon.second;
    std::shared_ptr<ArtifactWeapon> a_weapon = std::dynamic_pointer_cast<ArtifactWeapon>(this->inv.weapon.second);
    if(a_weapon) {
        this->influence = this->influence - a_weapon->get_influence();
        this->compute_secondary();
    }
    std::shared_ptr<MixedWeapon> m_weapon = std::dynamic_pointer_cast<MixedWeapon>(this->inv.weapon.second);
    if(m_weapon) {
        this->influence = this->influence - m_weapon->get_influence();
        this->compute_secondary();
    }
    this->inv.weapon = {false, nullptr};
    return  result;
}

std::map<std::string, std::pair<bool, std::shared_ptr<Equipment>>> &Player::get_equipments() {
    return this->inv.equipments;
}

void Player::take_equipment(std::shared_ptr<Equipment> &&equipment) {
    this->inv.equipments[equipment->get_placement()] = {false, equipment};
    std::shared_ptr<ArtifactEquipment> a_eq = std::dynamic_pointer_cast<ArtifactEquipment>(equipment);
    if(a_eq) {
        this->influence = this->influence + a_eq->get_influence();
        this->compute_secondary();
    }
}

std::shared_ptr<Equipment> Player::throw_equipment(const std::string &placement) {
    auto result = this->inv.equipments[placement].second;
    std::shared_ptr<ArtifactEquipment> a_eq = std::dynamic_pointer_cast<ArtifactEquipment>(result);
    if(a_eq) {
        this->influence = this->influence - a_eq->get_influence();
        this->compute_secondary();
    }
    this->inv.equipments[placement] = {false, nullptr};
    return result;
}

int Player::deal_damage() {
    int damage_amount = this->secondary.bonus_damage;
    if(this->inv.weapon.second != nullptr)
            damage_amount += this->get_weapon().second->get_damage();
    return damage_amount;
}

int Player::resist() {
    int resist_amount = this->secondary.bonus_defence;
    for(const auto& eq : this->inv.equipments) {
        resist_amount += eq.second.second->get_defence();
    }
    return resist_amount;
}

