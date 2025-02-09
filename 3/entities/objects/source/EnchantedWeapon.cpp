//
// Created by vanish2 on 12.12.23.
//

#include "EnchantedWeapon.h"

void EnchantedWeapon::be_loaded(json data) {
    Enchanted::be_loaded(data["enchanted"]);
    Weapon::be_loaded(data);
}
