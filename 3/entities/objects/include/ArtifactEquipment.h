//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_ARTIFACTEQUIPMENT_H
#define LAB3_ARTIFACTEQUIPMENT_H


#include "Equipment.h"
#include "Artifact.h"

class ArtifactEquipment : public Equipment, public Artifact {
public:
    ArtifactEquipment() = default;
    ~ArtifactEquipment() override = default;

    /**
     * @breif Loads data about ArtifactEquipment from JSON object
     * @param data JSON object
     */
    void be_loaded(json data) override;
};


#endif //LAB3_ARTIFACTEQUIPMENT_H
