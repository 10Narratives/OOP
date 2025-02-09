//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_ENCHANTEDWEAPON_H
#define LAB3_ENCHANTEDWEAPON_H


#include "Weapon.h"
#include "Enchanted.h"

class EnchantedWeapon : public Weapon, public Enchanted{
public:
    EnchantedWeapon() = default;
    ~EnchantedWeapon() override = default;

    /**
     * @brief Loads data about EnchantedWeapon from JSON object
     * @param data JSON object
     */
    void be_loaded(json data) override;
};


#endif //LAB3_ENCHANTEDWEAPON_H
