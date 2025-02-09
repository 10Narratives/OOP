//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_ARTIFACTWEAPON_H
#define LAB3_ARTIFACTWEAPON_H


#include "Weapon.h"
#include "Artifact.h"

class ArtifactWeapon : public Weapon, public Artifact{
public:
    ArtifactWeapon() = default;
    ~ArtifactWeapon() override = default;

    /**
    * @breif Loads data about ArtifactEquipment from JSON object
    * @param data JSON object
    */
    void be_loaded(json data) override;
};


#endif //LAB3_ARTIFACTWEAPON_H
