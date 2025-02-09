//
// Created by vanish2 on 10.12.23.
//

#ifndef LAB3_CHEST_H
#define LAB3_CHEST_H

#include <memory>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Object.h"
#include "Placeable.h"

class Chest : public Placeable{
private:
    int level_{};
    std::shared_ptr<Object> inner_object;

public:
    Chest() = default;

    int get_level() const;

    std::shared_ptr<Object>& get_inner_object();

    void be_loaded(json data) override;

    //json be_saved() const override;
};


#endif //LAB3_CHEST_H
