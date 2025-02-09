//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_WEAPON_H
#define LAB3_WEAPON_H


#include "Object.h"

class Weapon : public Object{
private:
    int damage_{};

public:
    Weapon() = default;
    ~Weapon() override = default;

    /**
     * @brief Getter for damage of Weapon
     * @return Damage
     */
    [[nodiscard]] int get_damage() const;

    /**
     * @breif Loads data about Weapon from JSON object
     * @param data JSON object
     */
    void be_loaded(json data) override;
};


#endif //LAB3_WEAPON_H
