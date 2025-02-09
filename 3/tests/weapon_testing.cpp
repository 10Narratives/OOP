//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Weapon.h"

TEST_CASE("WeaponConstructor") {
    SECTION("Default") {
        Weapon w;
        REQUIRE(w.get_name().empty());
        REQUIRE(w.get_damage() == 0);
    }
}

TEST_CASE("WeaponLoad") {
    SECTION("Load") {
        auto data = R"({
            "name": "Object",
            "damage": 10
        })"_json;
        Weapon w;
        w.be_loaded(data);
        REQUIRE(w.get_name() == "Object");
        REQUIRE(w.get_damage() == 10);
    }
}