//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "ArtifactEquipment.h"

TEST_CASE("ArtifactEquipmentConstructor") {
    SECTION("Default") {
        ArtifactEquipment a;
        REQUIRE(a.get_name().empty());
        REQUIRE(a.get_placement().empty());
        REQUIRE(a.get_defence() == 0);
        REQUIRE(a.get_influence().power == 0);
        REQUIRE(a.get_influence().ability == 0);
        REQUIRE(a.get_influence().endurance == 0);
        REQUIRE(a.get_influence().health == 0);
        REQUIRE(a.get_influence().health_limit == 0);
    }
}

TEST_CASE("ArtifactEquipmentLoad") {
    auto data = R"({
            "name": "Helmet",
            "placement": "head",
            "defence": 3,
            "influence": {
                "power": 10,
                "ability": 0,
                "endurance": 0,
                "health": 0,
                "health_limit": 0
            }
    })"_json;
    ArtifactEquipment a;
    a.be_loaded(data);
    REQUIRE(a.get_name() == "Helmet");
    REQUIRE(a.get_placement() == "head");
    REQUIRE(a.get_defence() == 3);
    REQUIRE(a.get_influence().power == 10);
    REQUIRE(a.get_influence().ability == 0);
    REQUIRE(a.get_influence().endurance == 0);
    REQUIRE(a.get_influence().health == 0);
    REQUIRE(a.get_influence().health_limit == 0);
}