//
// Created by vanish2 on 04.12.23.
//
#include "Creature.h"
#include <iostream>

Primary Primary::operator+(const Primary &other) const {
    Primary result;
    result.power = this->power + other.power;
    result.ability = this->ability + other.ability;
    result.endurance = this->endurance + other.endurance;
    result.health_limit = this->health_limit + other.health_limit;
    result.health = this->health + other.health;
    return result;
}


Creature::Creature(std::pair<int, int> coords) : Placeable(coords) {}

Primary Primary::operator-(const Primary &other) const {
    Primary result;
    result.power = this->power - other.power;
    result.ability = this->ability - other.ability;
    result.endurance = this->endurance - other.endurance;
    result.health_limit = this->health_limit - other.health_limit;
    result.health = this->health - other.health;
    return result;
}

bool Primary::operator==(const Primary &other) const {
    bool same_power = this->power == other.power;
    bool same_ability = this->ability == other.ability;
    bool same_endurance = this->endurance == other.endurance;
    bool same_health = this->health == other.health;
    bool same_health_limit = this->health_limit == other.health_limit;

    return same_power && same_ability && same_endurance && same_health && same_health_limit;
}

void Primary::be_loaded(json data) {
    this->power = data["power"].get<int>();
    this->ability = data["ability"].get<int>();
    this->endurance = data["endurance"].get<int>();
    this->health = data["health"].get<int>();
    this->health_limit = data["health_limit"].get<int>();
}

json Primary::be_saved() const {
    json save_object;
    save_object["power"] = this->power;
    save_object["ability"] = this->ability;
    save_object["endurance"] = this->endurance;
    save_object["health_limit"] = this->health_limit;
    save_object["health"] = this->health;
    return save_object;
}

Primary Creature::get_primary() const { return this->primary; }

Primary Creature::get_influence() const { return this->influence; }

Secondary Creature::get_secondary() const { return this->secondary; }

void Creature::compute_secondary() {
    Primary with_influence = this->primary + this->influence;
    this->secondary.bonus_damage = with_influence.power / 5;
    this->secondary.bonus_defence = with_influence.ability / 5;
    this->secondary.unlocking = with_influence.ability / 5;
    this->secondary.consumable_limit = with_influence.endurance / 5;
}

void Creature::be_loaded(json data) {
    Placeable::be_loaded(data);
    const auto& primary_data = data["primary"];
    this->primary.be_loaded(primary_data);
    this->exp = data["exp"].get<int>();
    this->compute_secondary();
}

json Creature::be_saved() const {
    json save_object = Placeable::be_saved();
    save_object["primary"] = this->primary.be_saved();
    save_object["exp"] = this->exp;
    return save_object;
}

int Creature::get_exp() const {
    return this->exp;
}

void Creature::set_primary(Primary new_primary) {
    this->primary = new_primary;
}

void Creature::get_damage(int damage_amount) {
    this->primary.health -= damage_amount;
}

void Creature::hit(Creature &who) {
    auto damage_amount = this->deal_damage() - who.resist();
    if(damage_amount < 0)
        damage_amount = 0;
    who.get_damage(damage_amount);
}


