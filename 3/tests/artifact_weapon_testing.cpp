//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "ArtifactWeapon.h"

TEST_CASE("ArtifactWeaponConstructor") {
    SECTION("Default") {
        ArtifactWeapon a;
        REQUIRE(a.get_name().empty());
        REQUIRE(a.get_damage() == 0);
        REQUIRE(a.get_influence().power == 0);
        REQUIRE(a.get_influence().ability == 0);
        REQUIRE(a.get_influence().endurance == 0);
        REQUIRE(a.get_influence().health == 0);
        REQUIRE(a.get_influence().health_limit == 0);
    }
}

TEST_CASE("ArtifactWeaponLoad") {
    SECTION("Load") {
        auto data = R"({
            "name": "Object",
            "damage": 10,
            "influence": {
                "power": 10,
                "ability": 0,
                "endurance": 0,
                "health": 0,
                "health_limit": 0
            }
        })"_json;
        ArtifactWeapon a;
        a.be_loaded(data);
        REQUIRE(a.get_name() == "Object");
        REQUIRE(a.get_damage() == 10);
        REQUIRE(a.get_influence().power == 10);
        REQUIRE(a.get_influence().ability == 0);
        REQUIRE(a.get_influence().endurance == 0);
        REQUIRE(a.get_influence().health == 0);
        REQUIRE(a.get_influence().health_limit == 0);
    }
}