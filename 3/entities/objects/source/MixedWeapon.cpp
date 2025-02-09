//
// Created by vanish2 on 12.12.23.
//

#include "MixedWeapon.h"

void MixedWeapon::be_loaded(json data) {
    Artifact::be_loaded(data);
    Enchanted::be_loaded(data["enchanted"]);
    Weapon::be_loaded(data);
}
