//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Object.h"

TEST_CASE("ObjectConstructor"){
    SECTION("Default") {
        Object o;
        REQUIRE(o.get_name().empty());
    } SECTION("Name") {
        Object o{"Object"};
        REQUIRE(o.get_name() == "Object");
    }
}

TEST_CASE("ObjectMethods") {
    SECTION("Setters") {
        Object o;
        o.set_name("Object");
        REQUIRE(o.get_name() == "Object");
    }
}

TEST_CASE("ObjectSaveAndLoad") {
    auto data = R"({
            "name": "Object"
        })"_json;
    Object o;
    SECTION("Load") {
        o.be_loaded(data);
        REQUIRE(o.get_name() == "Object");
    } SECTION("Save") {
        REQUIRE(!o.be_saved().empty());
    }
}