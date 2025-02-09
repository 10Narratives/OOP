//
// Created by vanish2 on 04.12.23.
//
#include "Placeable.h"

Placeable::Placeable(std::pair<int, int> coords) : coords(coords) {}

int Placeable::get_x() const { return this->coords.first; }

void Placeable::set_x(int new_x) { this->coords.first = new_x; }

int Placeable::get_y() const { return this->coords.second; }

void Placeable::set_y(int new_y) { this->coords.second = new_y; }

void Placeable::be_loaded(json data) {
    this->coords.first = data["x"].get<int>();
    this->coords.second = data["y"].get<int>();
}

json Placeable::be_saved() const {
    json save_object;
    save_object["x"] = this->coords.first;
    save_object["y"] = this->coords.second;
    return save_object;
}

std::pair<int, int> Placeable::get_position() const {
    return this->coords;
}

std::pair<int, int> operator+(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}