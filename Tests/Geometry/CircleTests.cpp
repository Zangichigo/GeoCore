#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Circle.hpp>

using namespace GeoCore;

TEST_CASE("Point inside circle")
{
    Circle circle(
        Position(48.8566, 2.3522),
        100.0);

    REQUIRE(
        circle.contains(
            Position(48.8567, 2.3523)));
}

TEST_CASE("Point outside circle")
{
    Circle circle(
        Position(48.8566, 2.3522),
        100.0);

    REQUIRE_FALSE(
        circle.contains(
            Position(48.8666, 2.3622)));
}

TEST_CASE("Circle contains its center")
{
    Circle circle(
        Position(48.8566, 2.3522),
        100.0);

    REQUIRE(
        circle.contains(
            Position(48.8566, 2.3522)));
}