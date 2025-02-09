//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "MixedWeapon.h"

TEST_CASE("MixedWeaponConstructor") {
    SECTION("Default") {
        MixedWeapon e;
        REQUIRE(e.get_name().empty());
        REQUIRE(e.get_damage() == 0);
        REQUIRE(e.get_target_trait().empty());
        REQUIRE(e.get_avoid_trait().empty());
        REQUIRE(e.get_best() == 1);
        REQUIRE(e.get_worst() == 1);
        REQUIRE(e.get_influence().power == 0);
        REQUIRE(e.get_influence().ability == 0);
        REQUIRE(e.get_influence().endurance == 0);
        REQUIRE(e.get_influence().health == 0);
        REQUIRE(e.get_influence().health_limit == 0);
    }
}

TEST_CASE("MixedWeaponLoad") {
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
            },
            "enchanted": {
                "target_trait": "Human",
                "avoid_trait": "Undead",
                "best": 4,
                "worst": -2
            }
        })"_json;
        MixedWeapon e;
        e.be_loaded(data);
        REQUIRE(e.get_name() == "Object");
        REQUIRE(e.get_damage() == 10);
        REQUIRE(e.get_target_trait() == "Human");
        REQUIRE(e.get_avoid_trait() == "Undead");
        REQUIRE(e.get_best() == 4);
        REQUIRE(e.get_worst() == -2);
        REQUIRE(e.get_influence().power == 10);
        REQUIRE(e.get_influence().ability == 0);
        REQUIRE(e.get_influence().endurance == 0);
        REQUIRE(e.get_influence().health == 0);
        REQUIRE(e.get_influence().health_limit == 0);
    }
}