//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_MIXEDWEAPON_H
#define LAB3_MIXEDWEAPON_H

#include "Weapon.h"
#include "Artifact.h"
#include "Enchanted.h"

class MixedWeapon : public Weapon, public Artifact, public Enchanted{
public:
    MixedWeapon() = default;
    ~MixedWeapon() override = default;

    /**
     * @brief Loads data about MixedWeapon from JSON object
     * @param data JSON object
     */
    void be_loaded(json data) override;
};


#endif //LAB3_MIXEDWEAPON_H
