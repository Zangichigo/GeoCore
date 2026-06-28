#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Polygon.hpp>

using namespace GeoCore;

static Polygon createSquare()
{
    return Polygon(
    {
        Position(0.0, 0.0),
        Position(0.0, 10.0),
        Position(10.0, 10.0),
        Position(10.0, 0.0)
    });
}

TEST_CASE("Point inside polygon")
{
    Polygon polygon = createSquare();

    REQUIRE(
        polygon.contains(Position(5.0, 5.0)));
}

TEST_CASE("Point outside polygon")
{
    Polygon polygon = createSquare();

    REQUIRE_FALSE(
        polygon.contains(Position(15.0, 5.0)));
}

TEST_CASE("Point far outside polygon")
{
    Polygon polygon = createSquare();

    REQUIRE_FALSE(
        polygon.contains(Position(-100.0, -100.0)));
}