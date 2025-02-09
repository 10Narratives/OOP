//
// Created by vanish2 on 06.12.23.
//

#include <iostream>
#include "../include/Potion.h"

void Potion::set_potion_effect(Primary new_potion_effect) {
    this->potion_effect = new_potion_effect;
}

Primary Potion::get_potion_effect() const {
    return this->potion_effect;
}

void Potion::be_loaded(json data) {
    Object::be_loaded(data);
    this->potion_effect.be_loaded(data["potion_effect"]);
}

json Potion::be_saved() const {
    json save_object = Object::be_saved();
    save_object["potion_effect"] = this->potion_effect.be_saved();
    return save_object;
}

Primary Potion::be_drunk() {
    return this->potion_effect;
}

Potion::Potion(const std::string& name, Primary new_potion_effect) : Object(name) {
    this->potion_effect = new_potion_effect;
}
