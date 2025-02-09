//
// Created by vanish2 on 06.12.23.
//

#include "../include/Object.h"

Object::Object(const std::string &name) {
    this->set_name(name);
}

std::string Object::get_name() const {
    return this->name;
}

void Object::set_name(const std::string &new_name) {
    this->name = new_name;
}

void Object::be_loaded(json data) {
    this->name = data["name"].get<std::string>();
}

json Object::be_saved() const {
    json save_object;
    save_object["name"] = this->name;
    return save_object;
}



