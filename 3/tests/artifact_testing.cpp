//
// Created by vanish2 on 13.12.23.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Artifact.h"

TEST_CASE("ArtifactConstructor"){
    SECTION("Default") {
        Artifact artifact;
        REQUIRE(artifact.get_influence().power == 0);
        REQUIRE(artifact.get_influence().ability == 0);
        REQUIRE(artifact.get_influence().endurance == 0);
        REQUIRE(artifact.get_influence().health == 0);
        REQUIRE(artifact.get_influence().health_limit == 0);
    }
}

TEST_CASE("ArtifactLoad") {
    auto data = R"({
            "influence": {
                "power": 10,
                "ability": 0,
                "endurance": 0,
                "health": 0,
                "health_limit": 0
            }
    })"_json;
    Artifact a;
    a.be_loaded(data);
    REQUIRE(a.get_influence().power == 10);
}