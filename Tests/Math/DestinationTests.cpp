#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <GeoCore/Math/Distance.hpp>
#include <GeoCore/Math/Destination.hpp>

using namespace GeoCore;
using Catch::Approx;

TEST_CASE("Zero distance returns identical position")
{
    Position start(48.8566, 2.3522);

    Position result =
        Math::destination(start, 90.0, 0.0);

    REQUIRE(result.latitude() == Approx(start.latitude()));
    REQUIRE(result.longitude() == Approx(start.longitude()));
}

TEST_CASE("Moving north increases latitude")
{
    Position start(48.8566, 2.3522);

    Position result =
        Math::destination(start, 0.0, 1000.0);

    REQUIRE(result.latitude() > start.latitude());
}

TEST_CASE("Moving east changes longitude")
{
    Position start(48.8566, 2.3522);

    Position result =
        Math::destination(start, 90.0, 1000.0);

    REQUIRE(result.longitude() > start.longitude());
}

TEST_CASE("Destination remains approximately at requested distance")
{
    Position start(48.8566, 2.3522);

    Position result =
        Math::destination(start, 45.0, 1000.0);

    double distance =
        Math::distance(start, result);

    REQUIRE(distance == Approx(1000.0).margin(1.0));
}

TEST_CASE("Latitude and longitude remain valid")
{
    Position start(48.8566, 2.3522);

    Position result =
        Math::destination(start, 270.0, 500000.0);

    REQUIRE(result.latitude() >= -90.0);
    REQUIRE(result.latitude() <= 90.0);

    REQUIRE(result.longitude() >= -180.0);
    REQUIRE(result.longitude() <= 180.0);
}