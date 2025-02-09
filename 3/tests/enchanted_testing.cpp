//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Enchanted.h"

TEST_CASE("EnchantedConstructor") {
    SECTION("Default") {
        Enchanted e;
        REQUIRE(e.get_target_trait().empty());
        REQUIRE(e.get_avoid_trait().empty());
        REQUIRE(e.get_best() == 1);
        REQUIRE(e.get_worst() == 1);

    }
}

TEST_CASE("EnchantedLoad") {
    auto data = R"({
        "target_trait": "Human",
        "avoid_trait": "Undead",
        "best": 4,
        "worst": -2
    })"_json;
    Enchanted e;
    e.be_loaded(data);
    REQUIRE(e.get_target_trait() == "Human");
    REQUIRE(e.get_avoid_trait() == "Undead");
    REQUIRE(e.get_best() == 4);
    REQUIRE(e.get_worst() == -2);
}

TEST_CASE("EnchantedMethods") {
    SECTION("GetFactor") {
        auto data = R"({
            "target_trait": "Human",
            "avoid_trait": "Undead",
            "best": 4,
            "worst": -2
        })"_json;
        Enchanted e;
        e.be_loaded(data);
        REQUIRE(e.get_factor("Human") == 4);
        REQUIRE(e.get_factor("Undead") == -2);
        REQUIRE(e.get_factor("Orc") == 1);
    }
}