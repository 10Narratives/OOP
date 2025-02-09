//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_CELL_H
#define LAB3_CELL_H

#include <memory>
#include "Placeable.h"
#include "Object.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Cell : public Placeable {
private:
    bool is_wall_ = false;
    std::shared_ptr<Object> inner_object;

public:
    Cell() = default;

    explicit Cell(std::pair<int, int> coords);

    Cell(std::pair<int, int> coords, bool is_wall);

    [[nodiscard]] std::shared_ptr<Object> get_inner_object() const;

    void set_inner_object(const std::shared_ptr<Object>& new_inner_object);

    explicit operator bool() const;

    void be_loaded(json data) override;
};


#endif //LAB3_CELL_H
