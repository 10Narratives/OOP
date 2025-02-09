//
// Created by vanish2 on 12.12.23.
//

#include "ArtifactEquipment.h"

#include <iostream>

void ArtifactEquipment::be_loaded(json data) {
    Equipment::be_loaded(data);
    Artifact::be_loaded(data);
}

