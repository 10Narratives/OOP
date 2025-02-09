//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_EQUIPMENT_H
#define LAB3_EQUIPMENT_H


#include "Object.h"

class Equipment : public Object {
private:
    std::string placement_;
    int defence_{0};

public:
    Equipment() = default;
    ~Equipment() override = default;

    /**
     * @breif Getter for placement (place on body of user)
     * @return Placement of Equipment
     */
    [[nodiscard]] std::string get_placement() const;

    /**
     * @breif Getter for defence
     * #@return Defence of Equipment
     */
    [[nodiscard]] int get_defence() const;

    /**
     * @breif Loads data about Equipment from JSON object
     * @param data JSON object
     */
    void be_loaded(json data) override;

    /**
     * @brief Saves data about Equipment into JSON object
     * @return JSON object
     */
    [[nodiscard]] json be_saved() const override;
};


#endif //LAB3_EQUIPMENT_H
