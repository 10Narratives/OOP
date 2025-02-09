//
// Created by vanish2 on 12.12.23.
//

#include "Artifact.h"

void Artifact::be_loaded(json data) {
    this->influence.be_loaded(data["influence"]);
}

Primary Artifact::get_influence() const {
    return this->influence;
}
