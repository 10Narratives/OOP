//
// Created by vanish2 on 12.12.23.
//

#include "Enchanted.h"

std::string Enchanted::get_target_trait() const {
    return this->target_trait_;
}


std::string Enchanted::get_avoid_trait() const {
    return this->avoid_trait_;
}

int Enchanted::get_best() const {
    return this->best_;
}

int Enchanted::get_worst() const {
    return this->worst_;
}

void Enchanted::be_loaded(json data) {
    this->target_trait_ = data["target_trait"].get<std::string>();
    this->avoid_trait_ = data["avoid_trait"].get<std::string>();
    this->best_ = data["best"].get<int>();
    this->worst_ = data["worst"].get<int>();
}

int Enchanted::get_factor(const std::string &trait) {
    int result{1};
    if(target_trait_ == trait)
        result = best_;
    if(avoid_trait_ == trait)
        result = worst_;
    return result;
}

