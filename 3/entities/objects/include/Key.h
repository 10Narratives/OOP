//
// Created by vanish2 on 10.12.23.
//

#ifndef LAB3_KEY_H
#define LAB3_KEY_H


#include <string>
#include <nlohmann/json.hpp>
using json =  nlohmann::json;

#include "Object.h"

class Key : public Object {
private:
    int amount_{};

public:
    Key() = default;
    ~Key() override = default;

    /**
     * @brief Getter for amount (number of keys in bunch)
     * @return Amount
     */
    [[nodiscard]] int get_amount() const;

    /**
     * @brief Loads data about Key from JSON object
     * @param data JSON object
     */
    void be_loaded(json data) override;

    /**
     * @brief Saves data about Key into JSON object
     * @return JSON object
     */
    [[nodiscard]] json be_saved() const override;
};


#endif //LAB3_KEY_H
