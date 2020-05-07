// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

#include <mylibrary/example.h>


TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
}

TEST_CASE("Testing piece.cpp", "[piece]") {
  int x;
  int y;
  std::vector<std::vector<int>> shape;

  REQUIRE(x == 0);
  REQUIRE(y == 0);

  SECTION("Move Right") {
    //piece.moveRight();
  }
}

TEST_CASE("Testing rowLogic.cpp", "[rowLogic]") {

}