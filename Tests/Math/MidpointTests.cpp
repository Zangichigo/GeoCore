#include <catch2/catch_test_macros.hpp>

#include <GeoCore/Math/Midpoint.hpp>

using namespace GeoCore;

TEST_CASE("Midpoint of identical positions is identical")
{
    Position p(48.8566, 2.3522);

    Position result =
        Math::midpoint(p, p);

    REQUIRE(result.latitude() == 48.8566);
    REQUIRE(result.longitude() == 2.3522);
}

TEST_CASE("Midpoint latitude is between both positions")
{
    Position a(0.0, 0.0);
    Position b(10.0, 0.0);

    Position result =
        Math::midpoint(a, b);

    REQUIRE(result.latitude() == 5.0);
    REQUIRE(result.longitude() == 0.0);
}

TEST_CASE("Midpoint longitude is between both positions")
{
    Position a(0.0, 0.0);
    Position b(0.0, 10.0);

    Position result =
        Math::midpoint(a, b);

    REQUIRE(result.latitude() == 0.0);
    REQUIRE(result.longitude() == 5.0);
}

TEST_CASE("Midpoint of opposite corners")
{
    Position a(0.0, 0.0);
    Position b(10.0, 10.0);

    Position result =
        Math::midpoint(a, b);

    REQUIRE(result.latitude() == 5.0);
    REQUIRE(result.longitude() == 5.0);
}