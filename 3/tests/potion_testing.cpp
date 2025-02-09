//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Potion.h"

TEST_CASE("PotionConstructor") {
    SECTION("Default") {
        Potion p;
        REQUIRE(p.get_name().empty());
        REQUIRE(p.get_potion_effect().power == 0);
        REQUIRE(p.get_potion_effect().ability == 0);
        REQUIRE(p.get_potion_effect().endurance == 0);
        REQUIRE(p.get_potion_effect().health == 0);
        REQUIRE(p.get_potion_effect().health_limit == 0);
    }
}

TEST_CASE("PotionLoad") {
    auto data = R"({
            "name": "Object",
            "potion_effect": {
                "power": 10,
                "ability": 0,
                "endurance": 0,
                "health": 0,
                "health_limit": 0
            }
    })"_json;
    Potion p;
    p.be_loaded(data);
    REQUIRE(p.get_name() == "Object");
    REQUIRE(p.get_potion_effect().power == 10);
    REQUIRE(p.get_potion_effect().ability == 0);
    REQUIRE(p.get_potion_effect().endurance == 0);
    REQUIRE(p.get_potion_effect().health == 0);
    REQUIRE(p.get_potion_effect().health_limit == 0);
}