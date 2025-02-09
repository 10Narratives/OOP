//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Equipment.h"

TEST_CASE("EquipmentConstructor") {
    SECTION("Default") {
        Equipment eq;
        REQUIRE(eq.get_placement().empty());
        REQUIRE(eq.get_defence() == 0);
    }
}

TEST_CASE("EquipmentLoadAndSave") {
    auto data = R"({
            "name": "Helmet",
            "placement": "head",
            "defence": 3
        })"_json;
    Equipment eq;
    SECTION("Load") {
        eq.be_loaded(data);
        REQUIRE(eq.get_name() == "Helmet");
        REQUIRE(eq.get_placement() == "head");
        REQUIRE(eq.get_defence() == 3);
    }SECTION("Load") {
        eq.be_loaded(data);
        REQUIRE(eq.be_saved().empty() == false);
    }
}