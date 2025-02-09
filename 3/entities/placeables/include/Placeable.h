//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_PLACEABLE_H
#define LAB3_PLACEABLE_H

#include <utility>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Placeable {
protected:
    std::pair<int, int> coords{0,0};

public:
    Placeable() = default;
    virtual ~Placeable() = default;

    explicit Placeable(std::pair<int, int> coords);

    [[nodiscard]] int get_x() const;

    [[nodiscard]] std::pair<int, int> get_position() const;

    void set_x(int new_x);

    [[nodiscard]] int get_y() const;

    void set_y(int new_y);

    virtual void be_loaded(json data);

    [[nodiscard]] virtual json be_saved() const;
};

std::pair<int, int> operator+(const std::pair<int, int>& a, const std::pair<int, int>& b);

#endif //LAB3_PLACEABLE_H
