#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Rectangle.hpp>

using namespace GeoCore;

TEST_CASE("Point inside rectangle")
{
    Rectangle rectangle(
        Position(0.0, 0.0),
        Position(10.0, 10.0));

    REQUIRE(
        rectangle.contains(
            Position(5.0, 5.0)));
}

TEST_CASE("Point outside rectangle")
{
    Rectangle rectangle(
        Position(0.0, 0.0),
        Position(10.0, 10.0));

    REQUIRE_FALSE(
        rectangle.contains(
            Position(15.0, 5.0)));
}

TEST_CASE("Rectangle contains south-west corner")
{
    Rectangle rectangle(
        Position(0.0, 0.0),
        Position(10.0, 10.0));

    REQUIRE(
        rectangle.contains(
            Position(0.0, 0.0)));
}

TEST_CASE("Rectangle contains north-east corner")
{
    Rectangle rectangle(
        Position(0.0, 0.0),
        Position(10.0, 10.0));

    REQUIRE(
        rectangle.contains(
            Position(10.0, 10.0)));
}

TEST_CASE("Rectangle accessors")
{
    Rectangle rectangle(
        Position(1.0, 2.0),
        Position(3.0, 4.0));

    REQUIRE(rectangle.southWest().latitude() == 1.0);
    REQUIRE(rectangle.southWest().longitude() == 2.0);

    REQUIRE(rectangle.northEast().latitude() == 3.0);
    REQUIRE(rectangle.northEast().longitude() == 4.0);
}